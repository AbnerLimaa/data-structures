using System;

namespace Library
{
    public class Stack
    {
        private Node top;

        public void Push(Int32 key)
        {
            if (key != 0)
            {
                Node node = new Node(key);
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

    class Node
    {
        private Int32 key;
        private Node next;

        public Node(Int32 key)
        {
            this.key = key;
        }

        public Int32 Key
        {
            get { return key; }
            set { this.key = value; }
        }

        public Node Next
        {
            get { return this.next; }
            set { this.next = value; }
        }
    }
}
