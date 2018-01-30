using System;

namespace Library
{
    public class BinarySearchTree
    {
		private Node root;
		private Int32 size;

		public BinarySearchTree()
		{
			size = 0;
		}

		public Int32 TreeMin()
		{
			if (root == null)
				return 0;
			Node node = root;
			while (node.Left != null)
				node = node.Left;
			return node.Key;
		}

		public Int32 TreeMax()
		{
			if (root == null)
				return 0;
			Node node = root;
			while (node.Right != null)
				node = node.Right;
			return node.Key;
		}

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

		public void Insert(Int32 key)
		{
			if (key != 0 && SearchNode(key) == null)
			{
				Node node = new Node(key);
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

		public Boolean Search(Int32 key)
		{
			if (SearchNode(key) != null)
				return true;
			return false;
		}

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

	class Node
	{
		private Int32 key;
		private Node parent;
		private Node left;
		private Node right;

		public Node(Int32 key)
		{
			this.key = key;
		}

		public Int32 Key
		{
			get { return key; }
			set { key = value; }
		}

		public Node Parent
		{
			get { return parent; }
			set { parent = value; }
		}

		public Node Left
		{
			get { return left; }
			set { left = value; }
		}

		public Node Right
		{
			get { return right; }
			set { right = value; }
		}
	}
}
