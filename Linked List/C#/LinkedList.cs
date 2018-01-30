using System;

namespace Library
{
    public class LinkedList
    {
		private Node head;

		public void Add(Int32 key)
		{
			if (key != 0 && !this.Search(key))
			{
				Node node = new Node(key);
				if (this.Empty())
					head = node;
				else
				{
					node.Next = head;
					head.Previous = node;
					head = node;
				}
			}
		}

		public Int32 Remove(Int32 key)
		{
			if (key == 0 || this.Empty())
				return 0;
			Node node = head;
			while (node != null && node.Key != key)
				node = node.Next;
			if (node != null)
			{
				Int32 remKey = node.Key;
				if (node.Previous == null && node.Next == null)
					head = null;
				else if (node.Previous == null)
				{
					node.Next.Previous = null;
					head = node.Next;
				}	
				else if (node.Next == null)
					node.Previous.Next = null;
				else
				{
					node.Previous.Next = node.Next;
					node.Next.Previous = node.Previous;
				}
				return remKey;
			}
			return 0;
		}

		public Boolean Search(Int32 key)
		{
			if (key == 0 || this.Empty())
				return false;
			Node node = head;
			while (node != null && node.Key != key)
				node = node.Next;
			if (node != null)
				return true;
			return false;
		}

		private Boolean Empty()
		{
			if (head == null)
				return true;
			return false;
		}
	}

	class Node
	{
		private Int32 key;
		private Node next;
		private Node previous;

		public Node(Int32 key)
		{
			this.key = key;
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
	}
}
