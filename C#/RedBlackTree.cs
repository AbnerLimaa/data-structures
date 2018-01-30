using System;

namespace DataStructures
{
	public class RedBlackTree
	{
		private Node root;
		private Node nil;
		private Int32 size;

		public RedBlackTree()
		{
			size = 0;
			nil = new Node(this);
			root = nil;
		}

		public Int32 TreeMin()
		{
			if (root == nil)
				return 0;
			Node node = root;
			while (node.Left != nil)
				node = node.Left;
			return node.Key;
		}

		public Int32 TreeMax()
		{
			if (root == nil)
				return 0;
			Node node = root;
			while (node.Right != nil)
				node = node.Right;
			return node.Key;
		}

		public Int32[] InOrderTreeWalk()
		{
			if (root == nil)
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
			if (node == nil)
				return 0;
			if (node.Right != nil)
			{
				node = node.Right;
				while (node.Left != nil)
					node = node.Left;
				return node.Key;
			}
			Node aux = node.Parent;
			while (aux != nil && node == aux.Right)
			{
				node = aux;
				aux = aux.Parent;
			}
			if (aux != nil)
				return aux.Key;
			return 0;
		}

		public Int32 Predecessor(Int32 key)
		{
			Node node = SearchNode(key);
			if (node == nil)
				return 0;
			if (node.Left != nil)
			{
				node = node.Left;
				while (node.Right != nil)
					node = node.Right;
				return node.Key;
			}
			Node aux = node.Parent;
			while (aux != nil && node == aux.Left)
			{
				node = aux;
				aux = aux.Parent;
			}
			if (aux != nil)
				return aux.Key;
			return 0;
		}

		private void LeftRotate(Node node)
		{
			if (node != nil)
			{
				Node aux = node.Right;
				node.Right = aux.Left;
				if (aux.Left != nil)
					aux.Left.Parent = node;
				aux.Parent = node.Parent;
				if (node.Parent == nil)
					root = aux;
				else if (node == node.Parent.Left)
					node.Parent.Left = aux;
				else
					node.Parent.Right = aux;
				aux.Left = node;
				node.Parent = aux;
			}
		}

		private void RightRotate(Node node)
		{
			if (node != nil)
			{
				Node aux = node.Left;
				node.Left = aux.Right;
				if (aux.Right != nil)
					aux.Right.Parent = node;
				aux.Parent = node.Parent;
				if (node.Parent == nil)
					root = aux;
				else if (node == node.Parent.Left)
					node.Parent.Left = aux;
				else
					node.Parent.Right = aux;
				aux.Right = node;
				node.Parent = aux;
			}
		}

		private void InsertFixUp(Node node)
		{
			if (node != nil)
			{
				Node aux;
				while (node.Parent.Color == NodeColor.RED)
				{
					if (node.Parent == node.Parent.Parent.Left)
					{
						aux = node.Parent.Parent.Right;
						if (aux.Color == NodeColor.RED)
						{
							node.Parent.Color = NodeColor.BLACK;
							aux.Color = NodeColor.BLACK;
							node.Parent.Parent.Color = NodeColor.RED;
							node = node.Parent.Parent;
						}
						else
						{
							if (node == node.Parent.Right)
							{
								node = node.Parent;
								LeftRotate(node);
							}
							node.Parent.Color = NodeColor.BLACK;
							node.Parent.Parent.Color = NodeColor.RED;
							RightRotate(node.Parent.Parent);
						}
					}
					else
					{
						aux = node.Parent.Parent.Left;
						if (aux.Color == NodeColor.RED)
						{
							node.Parent.Color = NodeColor.BLACK;
							aux.Color = NodeColor.BLACK;
							node.Parent.Parent.Color = NodeColor.RED;
							node = node.Parent.Parent;
						}
						else
						{
							if (node == node.Parent.Left)
							{
								node = node.Parent;
								RightRotate(node);
							}
							node.Parent.Color = NodeColor.BLACK;
							node.Parent.Parent.Color = NodeColor.RED;
							LeftRotate(node.Parent.Parent);
						}
					}
				}
				root.Color = NodeColor.BLACK;
			}
		}

		public void Insert(Int32 key)
		{
			if (key != 0 && SearchNode(key) == nil)
			{
				Node node = new Node(this, key);
				node.Key = key;
				Node aux = nil;
				Node search = root;
				while (search != nil)
				{
					aux = search;
					if (key < search.Key)
						search = search.Left;
					else
						search = search.Right;
				}
				node.Parent = aux;
				if (aux == nil)
					root = node;
				else if (key < aux.Key)
					aux.Left = node;
				else
					aux.Right = node;
				node.Left = nil;
				node.Right = nil;
				node.Color = NodeColor.RED;
				size++;
				InsertFixUp(node);
			}
		}

		private void Transplant(Node u, Node v)
		{
			if (u != nil)
			{
				if (u.Parent == nil)
					root = v;
				else if (u == u.Parent.Left)
					u.Parent.Left = v;
				else
					u.Parent.Right = v;
				v.Parent = u.Parent;
			}
		}

		private void DeleteFixUp(Node node)
		{
			if (node != nil)
			{
				Node aux;
				while (node != root && node.Color == NodeColor.BLACK)
				{
					if (node == node.Parent.Left)
					{
						aux = node.Parent.Right;
						if (aux.Color == NodeColor.RED)
						{
							aux.Color = NodeColor.BLACK;
							node.Parent.Color = NodeColor.RED;
							LeftRotate(node.Parent);
							aux = node.Parent.Right;
						}
						if (aux.Left.Color == NodeColor.RED && aux.Right.Color == NodeColor.BLACK)
						{
							aux.Color = NodeColor.RED;
							node = node.Parent;
						}
						else
						{
							if (aux.Right.Color == NodeColor.BLACK)
							{
								aux.Left.Color = NodeColor.BLACK;
								aux.Color = NodeColor.RED;
								RightRotate(aux);
								aux = node.Parent.Right;
							}
							aux.Color = node.Parent.Color;
							node.Parent.Color = NodeColor.BLACK;
							aux.Right.Color = NodeColor.BLACK;
							LeftRotate(node.Parent);
							node = root;
						}
					}
					else
					{
						aux = node.Parent.Left;
						if (aux.Color == NodeColor.RED)
						{
							aux.Color = NodeColor.BLACK;
							node.Parent.Color = NodeColor.RED;
							RightRotate(node.Parent);
							aux = node.Parent.Left;
						}
						if (aux.Right.Color == NodeColor.RED && aux.Left.Color == NodeColor.BLACK)
						{
							aux.Color = NodeColor.RED;
							node = node.Parent;
						}
						else
						{
							if (aux.Left.Color == NodeColor.BLACK)
							{
								aux.Right.Color = NodeColor.BLACK;
								aux.Color = NodeColor.RED;
								LeftRotate(aux);
								aux = node.Parent.Left;
							}
							aux.Color = node.Parent.Color;
							node.Parent.Color = NodeColor.BLACK;
							aux.Left.Color = NodeColor.BLACK;
							RightRotate(node.Parent);
							node = root;
						}
					}
				}
			}
		}

		public Int32 Delete(Int32 key)
		{
			Node node = SearchNode(key);
			if (node == nil)
				return 0;
			Int32 remKey = node.Key;
			Node start;
			Node orig = node;
			NodeColor origColor = node.Color;
			if (node.Left == nil)
			{
				start = node.Right;
				Transplant(node, node.Right);
			}
			else if (node.Right == nil)
			{
				start = node.Left;
				Transplant(node, node.Left);
			}
			else
			{
				orig = node.Right;
				while (orig.Left != nil)
					orig = orig.Left;
				origColor = orig.Color;
				start = orig.Right;
				if (orig.Parent == node)
					start.Parent = orig;
				else
				{
					Transplant(orig, orig.Right);
					orig.Right = node.Right;
					orig.Right.Parent = orig;
				}
				Transplant(node, orig);
				orig.Left = node.Left;
				orig.Left.Parent = orig;
				orig.Color = node.Color;
			}
			size--;
			if (origColor == NodeColor.BLACK)
				DeleteFixUp(start);
			return remKey;
		}

		public Boolean Search(Int32 key)
		{
			if (SearchNode(key) != nil)
				return true;
			return false;
		}

		private Node SearchNode(Int32 key)
		{
			if (key == 0 || root == nil)
				return nil;
			Node node = root;
			while (node != nil && key != node.Key)
				if (key < node.Key)
					node = node.Left;
				else
					node = node.Right;
			return node;
		}
	}
}
