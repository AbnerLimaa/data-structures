using System;

namespace DataStructures
{
	
	/* within this project I've made the following statement:
       		1 - returns 0 by dequeue if the queue is empty */
	
	public class Queue
	{
		private Node head;
		private Node tail;

		//add a new key to the queue
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

		//remove a key from the queue
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

		//check if the queue is empty
		private Boolean Empty()
		{
			if (head == null || tail == null)
				return true;
			return false;
		}
	}
}
