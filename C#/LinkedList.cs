using System;

namespace DataStructures
{
	
	/* within this project I've made the following statements:
       		1 - returns 0 if search can't find the key
       		2 - only inserts if the key is not 0
       		3 - returns 0 if the key isn't on the linkedlist */
	
	public class LinkedList
	{
		private Node head;

		//add a key to the linkedlist
		public void Add(Int32 key)
		{
			if (key != 0 && !this.Search(key))
			{
				Node node = new Node(this, key);
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

		//remove a key passed as parameter from the linkedlist
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

		//search if a key is on the linkedlist
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

		//checks if the linkedlist is empty
		private Boolean Empty()
		{
			if (head == null)
				return true;
			return false;
		}
	}
}
