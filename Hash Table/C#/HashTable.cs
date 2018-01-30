using System;

namespace Library
{
    public class HashTable
    {
		private LinkedList[] table;
		private Int32 size;

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

		public void Add(Int32 key)
		{
			if (key != 0)
				table[HashFunction(key)].Add(key);
		}

		public Int32 Remove(Int32 key)
		{
			if (key != 0)
				return table[HashFunction(key)].Remove(key);
			return 0;
		}

		public Boolean Search(Int32 key)
		{
			if (key != 0)
				return table[HashFunction(key)].Search(key);
			return false;
		}

		private Int32 HashFunction(Int32 key)
		{
			return key % size;
		}
    }
}
