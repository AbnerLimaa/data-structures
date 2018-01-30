using System;

namespace DataStructures
{
	public class Stack
	{
		private Node top;

		public void Push(Int32 key)
		{
			if (key != 0)
			{
				Node node = new Node(this, key);
				node.Next = top;
				top = node;
			}
		}

		public Int32 Pop()
		{
			if (this.Empty())
				return 0;
			Int32 key = top.Key;
			top = top.Next;
			return key;
		}

		private Boolean Empty()
		{
			if (top == null)
				return true;
			return false;
		}
	}
}
