#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include "stack.h"

typedef struct block
{
    int id;
    int tam_bloco;
    int minimo;
    int cartesian_number;
    int *numeros;
} block;

typedef struct lookup_table
{
    int **matriz;
    int largura;
    int altura;
} lookup_table;

typedef struct minima
{
    lookup_table *tabela;
    block **blocos;
    int *numeros;
    int qtd_blocos;
} minima;

typedef struct informacoes_busca
{  
    int i_relativo;
    int j_relativo;
    int pos_i;
    int pos_j;
    int indice_i;
    int indice_j;
    int indice_minima;
    block *bloco_i;
    block *bloco_j;
    lookup_table *tabela_i;
    lookup_table *tabela_j;
    int resultado;
} informacoes_busca;

typedef struct rmq_struct
{
    lookup_table **tabelas;
    minima *minimos;
    int *vetor;
    int tam_vetor;
    int qtd_tabelas;
    int b;
    informacoes_busca *info;
} rmq_struct;

int pow2(int potencia)
{
    return 1 << potencia;
}

int log2(int numero)
{
    int resultado = 0;
    while(numero >= 2)
    {
        numero = numero >> 1;
        resultado++;
    }
    return resultado;
}

void free_block(block *b)
{
    if(b != NULL)
    {
        if(b->numeros != NULL)
            free(b->numeros);
        free(b);
    }
}

block *new_block(int tam)
{
    if(tam > 0)
    {
        block *b = (block*)malloc(sizeof(block));
        if(b != NULL)
        {
            b->id = 0;
            b->tam_bloco = tam;
            b->minimo = 0;
            b->cartesian_number = 0;
            b->numeros = (int*)calloc(tam, sizeof(int));
            if(b->numeros != NULL)
                return b;
            free_block(b);
        }
    }
    return NULL;
}

void free_lookup_table(lookup_table *l)
{
    if(l != NULL)
    {
        for(int i = 0; i < l->largura; i++)
            free(l->matriz[i]);
        free(l->matriz);
        free(l);
    }
}

lookup_table *new_lookup_table(int n)
{
    lookup_table *l = (lookup_table*)malloc(sizeof(lookup_table));
    if(l != NULL)
    {
        l->altura = n;
        l->largura = log2(n) + 1;
        l->matriz = (int**)calloc(l->largura, sizeof(int*));
        for(int i = 0; i < l->largura; i++)
            l->matriz[i] = (int*)calloc(l->altura, sizeof(int));
        return l;
    }   
    return NULL;
}

lookup_table *criar_tabela(int *vetor, int tam)
{
    if(vetor != NULL)
    {
        lookup_table *l = new_lookup_table(tam);
        if(l != NULL)
        {
            int *primeira_coluna = l->matriz[0];
            for(int i = 0; i < tam; i++)
                primeira_coluna[i] = i;

            for(int i = 1; i < l->largura; i++)
            {
                int diferenca = pow2(i - 1);
                int j = 0;
                while(j + diferenca < l->altura)
                {
                    int *coluna_atual = l->matriz[i];
                    int *coluna_anterior = l->matriz[i - 1];
                    if(coluna_anterior[j + diferenca] != 0)
                    {
                        int x = vetor[coluna_anterior[j]];
                        int y = vetor[coluna_anterior[j + diferenca]];
                        if(x < y)
                            coluna_atual[j] = coluna_anterior[j];
                        else
                            coluna_atual[j] = coluna_anterior[j + diferenca];
                    }
                    j++;
                }
            }
            return l;
        }
    }
    return NULL;
}

int buscar_tabela(lookup_table *l, int *vetor, int i, int j)
{
    int x = j - i + 1;
    int k = log2(x);
    int intervalo = pow2(k);
    int *coluna = l->matriz[k];
    int indice = -1;
    if(i + intervalo - 1 == j)
        indice = coluna[i];
    else
    {
        int i_1 = coluna[i];
        int i_2 = coluna[(int)(j - intervalo + 1)];
        if(vetor[i_1] < vetor[i_2])
            indice = i_1;
        else
            indice = i_2;
    }
    return indice;
}

void free_minima(minima *m)
{
    if(m != NULL)
    {
        if(m->blocos != NULL)
        {
            for(int i = 0; i < m->qtd_blocos; i++)
                if(m->blocos[i] != NULL)
                    free_block(m->blocos[i]);
            free(m->blocos);
        }
        if(m->tabela != NULL)
            free_lookup_table(m->tabela);
        free(m->numeros);
        free(m);
    }
}

minima *new_minima(int tam)
{
    if(tam > 0)
    {
        minima *m = (minima*)malloc(sizeof(minima));
        if(m != NULL)
        {
            m->numeros = (int*)calloc(tam, sizeof(int));
            m->tabela = NULL;
            m->qtd_blocos = tam;
            m->blocos = (block**)calloc(tam, sizeof(block*));
            if(m->blocos != NULL)
                return m;
            free_minima(m);
        }
    }
    return NULL;
}

void free_info(informacoes_busca *i)
{
    if(i != NULL)
        free(i);
}

informacoes_busca *new_info()
{
    informacoes_busca *i = (informacoes_busca*)malloc(sizeof(informacoes_busca));
    if(i != NULL)
    {
        i->i_relativo = -1;
        i->j_relativo = -1;
        i->pos_i = -1;
        i->pos_j = -1;
        i->indice_i = -1;
        i->indice_j = -1;
        i->indice_minima = -1;
        i->bloco_i = NULL;
        i->bloco_j = NULL;
        i->tabela_i = NULL;
        i->tabela_j = NULL;
        i->resultado = -1;
        return i;
    }
    return NULL;
}

void free_rmq_struct(rmq_struct *r)
{
    if(r != NULL)
    {
        if(r->tabelas != NULL)
        {
            for(int i = 0; i < r->qtd_tabelas; i++)
                if(r->tabelas[i] != NULL)
                    free_lookup_table(r->tabelas[i]);
            free(r->tabelas);
        }
        if(r->minimos != NULL)
            free_minima(r->minimos);
        free_info(r->info);
        free(r->vetor);
        free(r);
    }
}

rmq_struct *new_rmq_struct(int tam, int *vetor)
{
    if(tam > 0 && vetor != NULL)
    {
        rmq_struct *r = (rmq_struct*)malloc(sizeof(rmq_struct));
        if(r != NULL)
        {
            r->vetor = vetor;
            r->tam_vetor = tam;
            int b = log2(tam) >> 2;
            if(b == 0)
                b = 1;
            r->b = b;
            r->qtd_tabelas = pow2(b << 1);
            r->tabelas = (lookup_table**)calloc(r->qtd_tabelas, sizeof(lookup_table*));
            int qtd_minimos = (int)(r->tam_vetor / r->b);
            if((r->tam_vetor % r->b) != 0)
                qtd_minimos++;
            r->minimos = new_minima(qtd_minimos);
            r->info = new_info();
            if(r->tabelas != NULL && r->minimos != NULL)
                return r;
            free_rmq_struct(r);
        }
    }
    return NULL;
}

void preprocessar(rmq_struct *RMQ)
{
    if(RMQ != NULL)
    {
        int resto = RMQ->tam_vetor % RMQ->b;
        int tam_bloco = RMQ->b;
        int pos_vetor = 0;
        int qtd_blocos = RMQ->minimos->qtd_blocos;
        for(int i = 0; i < qtd_blocos; i++)
        {
            if(i == qtd_blocos - 1 && resto != 0)
                tam_bloco = resto;
            block *bloco = new_block(tam_bloco);
            bloco->id = i;
            bloco->minimo = INT_MAX;
            int indice_minimo = pos_vetor;
            stack *espinha_dir = newstk();
            int k = 1; 
            for(int j = 0; j < tam_bloco; j++)
            {
                if(RMQ->vetor[pos_vetor] < bloco->minimo)
                    bloco->minimo = RMQ->vetor[pos_vetor];
                bloco->numeros[j] = RMQ->vetor[pos_vetor];
                while(bloco->numeros[j] < top(espinha_dir))
                {
                    pop(espinha_dir);
                    k = k << 1;
                }
                push(espinha_dir, bloco->numeros[j]);
                bloco->cartesian_number = bloco->cartesian_number | k;
                k = k << 1;
                pos_vetor++;
            }
            freestk(espinha_dir);
            if(RMQ->tabelas[bloco->cartesian_number] == NULL)
                RMQ->tabelas[bloco->cartesian_number] = criar_tabela(bloco->numeros, tam_bloco);
            RMQ->minimos->blocos[i] = bloco;
            RMQ->minimos->numeros[i] = bloco->minimo;
        }
        RMQ->minimos->tabela = criar_tabela(RMQ->minimos->numeros, qtd_blocos);
    }
}

int rmq(rmq_struct *RMQ, int i, int j)
{
    if(RMQ != NULL)
    {
        if(i >= 0 && i < RMQ->tam_vetor && j >= 0 && j < RMQ->tam_vetor)
        {
            if(i <= j)
            {
                int minimo = INT_MAX;
                int num_i;
                int num_j;
                int num_minima = INT_MAX;
                int i_relativo = (int)(i / RMQ->b);
                int j_relativo = (int)(j / RMQ->b);
                block *bloco_i = RMQ->minimos->blocos[i_relativo];
                block *bloco_j = RMQ->minimos->blocos[j_relativo];
                int pos_i = i - bloco_i->id * RMQ->b;
                int pos_j = j - bloco_j->id * RMQ->b;
                lookup_table *tabela_i = RMQ->tabelas[bloco_i->cartesian_number];
                lookup_table *tabela_j = RMQ->tabelas[bloco_j->cartesian_number];
                int indice_i = buscar_tabela(tabela_i, bloco_i->numeros, pos_i, bloco_i->tam_bloco - 1);
                int indice_j = buscar_tabela(tabela_j, bloco_j->numeros, 0, pos_j);

                RMQ->info->i_relativo = i_relativo;
                RMQ->info->j_relativo = j_relativo;
                RMQ->info->pos_i = pos_i;
                RMQ->info->pos_j = pos_j;
                RMQ->info->indice_i = indice_i;
                RMQ->info->indice_j = indice_j;
                RMQ->info->bloco_i = bloco_i;
                RMQ->info->bloco_j = bloco_j;
                RMQ->info->tabela_i = tabela_i;
                RMQ->info->tabela_j = tabela_j;
                if(i == j)
                    minimo = RMQ->vetor[i];
                else if(j == i + 1)
                    minimo = (RMQ->vetor[i] < RMQ->vetor[j]) ? RMQ->vetor[i] : RMQ->vetor[j];
                else
                {
                    num_i = bloco_i->numeros[indice_i];
                    num_j = bloco_j->numeros[indice_j];
                    if(j_relativo == i_relativo + 1)
                        minimo = (num_i < num_j) ? num_i : num_j;
                    else
                    {   
                        int indice_minima = buscar_tabela(RMQ->minimos->tabela, RMQ->minimos->numeros, i_relativo + 1, j_relativo - 1);
                        RMQ->info->indice_minima = indice_minima;
                        num_minima = RMQ->minimos->numeros[indice_minima];
                        if(num_i < num_j && num_i < num_minima)
                            minimo = num_i;
                        else if(num_j < num_i && num_j < num_minima)
                            minimo = num_j;
                        else
                            minimo = num_minima;
                    }   
                }
                RMQ->info->resultado = minimo;
                return minimo;
            }
        }
    }
    return -1;
}

void mensagem(char *texto)
{
    printf("%s\n", texto);
    getchar();
}

void imprimir_vetor(int *vetor, int inicio, int final, char *texto, int indice)
{
    int tam_texto = strlen(texto) + 2;
    int aux = 0;
    printf("%s:[", texto);
    for(int i = inicio; i <= final; i++)
    {
        if(i - inicio == 100)
        {
            printf("...]\n");
            break;
        } 
        if(aux % 10 == 0 && aux != 0)
        {
            printf("\n");
            for(int j = 0; j < tam_texto; j++)
                printf(" ");
        }
        if(i == indice)
            printf("*");
        printf("%d", vetor[i]);
        if(i != final)
            printf(",\t");
        else
            printf("]\n");
        aux++;
    }
}

void imprimir_tabela(lookup_table *l, char *texto)
{
    printf("%s:\n", texto);
    for(int i = 0; i < l->altura; i++)
    {
        for(int j = 0; j < l->largura; j++)
        {
            int *coluna = l->matriz[j];
            printf("%d\t", coluna[i]);
        }
        printf("\n");
    }
}

void console(rmq_struct *RMQ)
{
    system("clear");
    printf("\t\t\tINFORMAÇÕES DO VETOR\n\n");
    imprimir_vetor(RMQ->vetor, 0, RMQ->tam_vetor - 1, "Vetor", -1);
}

void informacoes(rmq_struct *RMQ)
{
    int i_relativo = RMQ->info->i_relativo;
    int j_relativo = RMQ->info->j_relativo;
    int indice_i = RMQ->info->indice_i;
    int indice_j = RMQ->info->indice_j;
    int indice_minima = RMQ->info->indice_minima;
    block *bloco_i = RMQ->info->bloco_i;
    block *bloco_j = RMQ->info->bloco_j;
    lookup_table *tabela_i = RMQ->info->tabela_i;
    lookup_table *tabela_j = RMQ->info->tabela_j;

    printf("\t\t\tINFORMAÇÕES DA BUSCA\n\n");
    printf("n: %d\n", RMQ->tam_vetor);
    printf("b: %d\n", RMQ->b);
    printf("n/b: %d\n", RMQ->minimos->qtd_blocos);
    printf("Quantidade de tabelas: %d\n\n", RMQ->qtd_tabelas);
    imprimir_vetor(bloco_i->numeros, 0, bloco_i->tam_bloco - 1, "Bloco i", indice_i);
    printf("Posicao do i no bloco: %d\n", RMQ->info->pos_i);
    printf("Numero cartesiano: %d\n", bloco_i->cartesian_number);
    imprimir_tabela(tabela_i, "Tabela");
    printf("\n");
    if(j_relativo > i_relativo + 1)
    {
        int indice_minima = RMQ->info->indice_minima;
        imprimir_vetor(RMQ->minimos->numeros, i_relativo + 1, j_relativo - 1, "Bloco j - i", indice_minima);
    }
    printf("\n");
    imprimir_vetor(bloco_j->numeros, 0, bloco_j->tam_bloco - 1, "Bloco j", indice_j);
    printf("Posicao do j no bloco: %d\n", RMQ->info->pos_j);
    printf("Numero cartesiano: %d\n", bloco_j->cartesian_number);
    imprimir_tabela(tabela_j, "Tabela");
    printf("\nResultado: %d\n", RMQ->info->resultado);
}

void iniciar(rmq_struct *RMQ)
{
    int continua = 1;
    int i;
    int j;
    char c;
    while(continua)
    {
        mensagem("Mostrar vetor?[s/n]");
        c = getchar();
        if(c == 's')
            console(RMQ);
        printf("\nDigite os indices de busca. (0 - %d)\n", RMQ->tam_vetor - 1);
        printf("i: ");
        scanf("%d", &i);
        printf("j: ");
        scanf("%d", &j);
        int minimo = rmq(RMQ, i, j);
        if(minimo != -1)
        {
            informacoes(RMQ);
            mensagem("Novamente?[s/n]:");
            c = getchar();
            if(c == 'n')
                continua = 0;
            else
                system("clear"); 
        }
        else
        {
            mensagem("Indices invalidos.[Enter]");
            getchar();
        }
    }
}

int main(void)
{
    rmq_struct *RMQ = NULL;
    int tam_vetor = 0;
    int *vetor;
    char c;
    int continua = 1;
    srand(time(NULL));

    system("clear");
    printf("Insira o tamanho do vetor.\n");
    while(tam_vetor <= 0)
    {
        scanf("%d", &tam_vetor);
        if(tam_vetor > 0)
            vetor = (int*)calloc(tam_vetor, sizeof(int));
        else
            mensagem("Digite um numero maior do que 0.");   
    }

    while(continua)
    {
        mensagem("Vetor aleatorio?[s/n]:");
        c = getchar();
        if(c == 's')
        {
            for(int i = 0; i < tam_vetor; i++)
                vetor[i] = rand() % 1000;
            continua = 0;
        }
        else if(c == 'n')
        {
            mensagem("Digite os numeros do vetor.");
            for(int i = 0; i < tam_vetor; i++)
                scanf("%d", &vetor[i]);
            continua = 0;
        }
        else
            mensagem("Escolha uma opcao valida.");
    }
    
    RMQ = new_rmq_struct(tam_vetor, vetor);
    preprocessar(RMQ);
    iniciar(RMQ);

    free_rmq_struct(RMQ);
    return 0;
}