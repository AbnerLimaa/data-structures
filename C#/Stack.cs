using System;

namespace DataStructures
{
	
	/* within this project I've made the following statement:
       		1 - returns 0 by pop if the stack is empty */
	
	public class Stack
	{
		private Node top;
		
		//add a key to the stack
		public void Push(Int32 key)
		{
			if (key != 0)
			{
				Node node = new Node(this, key);
				node.Next = top;
				top = node;
			}
		}
		
		//remove a key from the stack
		public Int32 Pop()
		{
			if (this.Empty())
				return 0;
			Int32 key = top.Key;
			top = top.Next;
			return key;
		}

		//checks if the stack is empty
		private Boolean Empty()
		{
			if (top == null)
				return true;
			return false;
		}
	}
}
