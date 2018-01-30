using System;

namespace DataStructures
{
	
	/* within this project I've made the following statements:
       		1 - returns 0 by treemin and treemax if there is no key on the binary search tree
       		2 - returns NULL by iotwalk if there is no key on the binary search tree
       		3 - returns 0 if search can't find the key
       		4 - returns 0 by sucessor and predecessor if there is no sucessor/predecessor of the desired key
       		5 - only inserts if the key isn't on the tree or is not 0
       		6 - returns 0 by delete if the key isn't on the tree */
	
	public class BinarySearchTree
	{
		private Node root;
		private Int32 size;

		//create a new binary search tree
		public BinarySearchTree() { size = 0; }

		//return the minimum key stored on the binary search tree
		public Int32 TreeMin()
		{
			if (root == null)
				return 0;
			Node node = root;
			while (node.Left != null)
				node = node.Left;
			return node.Key;
		}

		//return the maximum key stored on the binary search tree
		public Int32 TreeMax()
		{
			if (root == null)
				return 0;
			Node node = root;
			while (node.Right != null)
				node = node.Right;
			return node.Key;
		}

		//return an array with the keys of the binary search tree in ascending order
		public Int32[] InOrderTreeWalk()
		{
			if (root == null)
				return null;
			Int32[] numbers = new Int32[size];
			Int32 min = TreeMin();
			for (int i = 0; i < size; i++)
			{
				numbers[i] = min;
				min = Sucessor(min);
			}
			return numbers;
		}

		//return the sucessor of a key inside the binary search tree
		public Int32 Sucessor(Int32 key)
		{
			Node node = SearchNode(key);
			if (node == null)
				return 0;
			if (node.Right != null)
			{
				node = node.Right;
				while (node.Left != null)
					node = node.Left;
				return node.Key;
			}
			Node aux = node.Parent;
			while (aux != null && node == aux.Right)
			{
				node = aux;
				aux = aux.Parent;
			}
			if (aux != null)
				return aux.Key;
			return 0;
		}

		//return the predecessor of a key inside the binary search tree
		public Int32 Predecessor(Int32 key)
		{
			Node node = SearchNode(key);
			if (node == null)
				return 0;
			if (node.Left != null)
			{
				node = node.Left;
				while (node.Right != null)
					node = node.Right;
				return node.Key;
			}
			Node aux = node.Parent;
			while (aux != null && node == aux.Left)
			{
				node = aux;
				aux = aux.Parent;
			}
			if (aux != null)
				return aux.Key;
			return 0;
		}

		//insert a key on the binary search tree
		public void Insert(Int32 key)
		{
			if (key != 0 && SearchNode(key) == null)
			{
				Node node = new Node(this, key);
				node.Key = key;
				Node aux = null;
				Node search = root;
				while (search != null)
				{
					aux = search;
					if (key < search.Key)
						search = search.Left;
					else
						search = search.Right;
				}
				node.Parent = aux;
				if (aux == null)
					root = node;
				else if (key < aux.Key)
					aux.Left = node;
				else
					aux.Right = node;
				size++;
			}
		}

		//makes an inside operation to switch the node u with node v, used by the deletion algorithm
		private void Transplant(Node u, Node v)
		{
			if (u != null)
			{
				if (u.Parent == null)
					root = v;
				else if (u == u.Parent.Left)
					u.Parent.Left = v;
				else
					u.Parent.Right = v;
				if (v != null)
					v.Parent = u.Parent;
			}
		}

		//delete a key from the binary search tree
		public Int32 Delete(Int32 key)
		{
			Node node = SearchNode(key);
			if (node == null)
				return 0;
			Int32 remKey = node.Key;
			if (node.Left == null)
				Transplant(node, node.Right);
			else if (node.Right == null)
				Transplant(node, node.Right);
			else
			{
				Node aux = node.Right;
				while (aux.Left != null)
					aux = aux.Left;
				if (aux.Parent != node)
				{
					Transplant(aux, aux.Right);
					aux.Right = node.Right;
					aux.Right.Parent = aux;
				}
				Transplant(node, aux);
				aux.Left = node.Left;
				aux.Left.Parent = aux;
			}
			size--;
			return remKey;
		}
		
		//search for a key inside the binary search tree
		public Boolean Search(Int32 key)
		{
			if (SearchNode(key) != null)
				return true;
			return false;
		}

		//return the Node if it is on the binary search tree or NULL if it isn't 
		private Node SearchNode(Int32 key)
		{
			if (key == 0 || root == null)
				return null;
			Node node = root;
			while (node != null && key != node.Key)
				if (key < node.Key)
					node = node.Left;
				else
					node = node.Right;
			return node;
		}
	}
}
