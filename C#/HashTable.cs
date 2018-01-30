using System;

namespace DataStructures
{
	
	/* within this project I've made the following statements:
       		1 - returns 0 if search can't find the key
       		2 - only inserts if the key is not 0
       		3 - returns 0 if the key isn't on the hashtable 
       		4 - solved colision by chaining */
	
	public class HashTable
	{
		private LinkedList[] table;
		private Int32 size;

		//create a new hashtable with the desired size
		public HashTable(Int32 size)
		{
			if (size > 0)
			{
				this.size = size;
				table = new LinkedList[this.size];
				for (int i = 0; i < this.size; i++)
					table[i] = new LinkedList();
			}
			else
			{
				throw new Exception("Size smaller than or equal 0");
			}
		}

		//add a key on the linkedlist stored on the hashtable at the index returned by the hashfunction
		public void Add(Int32 key)
		{
			if (key != 0)
				table[HashFunction(key)].Add(key);
		}
		
		//remove a key on the linkedlist stored on the hashtable at the index returned by the hashfunction
		public Int32 Remove(Int32 key)
		{
			if (key != 0)
				return table[HashFunction(key)].Remove(key);
			return 0;
		}

		//search a key on the linkedlist stored on the hashtable at the index returned by the hashfunction
		public Boolean Search(Int32 key)
		{
			if (key != 0)
				return table[HashFunction(key)].Search(key);
			return false;
		}

		//hashfunction of the hashtable
		private Int32 HashFunction(Int32 key)
		{
			return key % size;
		}
	}
}
