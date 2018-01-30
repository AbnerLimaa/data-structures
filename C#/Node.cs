using System;

/* here you have a class that defines the node used by all data structures and
   an enum that defines what is BLACK and RED in one node */

namespace DataStructures
{
	internal enum NodeColor { RED = 1, BLACK = 0 }

	class Node
	{
		private Int32 key;
		private Node next;
		private Node previous;
		private Node parent;
		private Node left;
		private Node right;
		private NodeColor color;

		public Node(Stack stack, Int32 key) { this.key = key; }

		public Node(Queue queue, Int32 key) { this.key = key; }

		public Node(LinkedList linkedList, Int32 key) { this.key = key; }

		public Node(BinarySearchTree bsTree, Int32 key) { this.key = key; }

		public Node(RedBlackTree rbTree) { color = NodeColor.BLACK; }

		public Node(RedBlackTree rbTree, Int32 key)
		{
			this.key = key;
			color = NodeColor.BLACK;
		}

		public Int32 Key
		{
			get { return key; }
			set { key = value; }
		}

		public Node Next
		{
			get { return next; }
			set { next = value; }
		}

		public Node Previous
		{
			get { return previous; }
			set { previous = value; }
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

		public NodeColor Color
		{
			get { return color; }
			set { color = value; }
		}
	}
}
