using System;

namespace DataStructures
{
	public class Queue
	{
		private Node head;
		private Node tail;

		public void Enqueue(Int32 key)
		{
			if (key != 0)
			{
				Node node = new Node(this, key);
				if (this.Empty())
				{
					head = node;
					tail = node;
				}
				else
				{
					tail.Next = node;
					tail = node;
				}
			}
		}

		public Int32 Dequeue()
		{
			if (this.Empty())
				return 0;
			Int32 key = head.Key;
			head = head.Next;
			if (this.Empty())
				tail = null;
			return key;
		}

		private Boolean Empty()
		{
			if (head == null || tail == null)
				return true;
			return false;
		}
	}
}
