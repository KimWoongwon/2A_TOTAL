using System;

namespace ConsoleApp1
{
    class Node<T>
    {
        private T _data;
        public T mData
        {
            get
            {
                return _data;
            }
            set
            {
                _data = value;
            }
        }
        private Node<T> _next;
        public Node<T> mNext
        {
            get
            {
                return _next;
            }
            set
            {
                _next = value;
            }
        }
    }
    class vectorint<T>
    {
        private Node<T> head;
        public int Count
        {
            get; set;
        }
        public vectorint()
        {
            head = new Node<T>();
            head.mData = default(T);
            head.mNext = null;
            Count = 1;
        }
        public Node<T> GetHeader()
        {
            return head;
        }
        public bool push(T p_val)
        {
            Node<T> temp = new Node<T>();
            temp.mData = p_val;
            temp.mNext = null;

            if (head.mNext == null)
            {
                this.head.mNext = temp;
                return true;
            }

            Node<T> cursor = this.head;

            while(cursor.mNext != null)
            {
                cursor = cursor.mNext;
            }

            cursor.mNext = temp;
            Count++;
            return true;
        }
        public bool insertat(int p_index, T p_val)
        {
            if (this.head.mNext == null)
            {
                p_index = 1;
            }
                
            if (p_index > Count)
            {
                Console.WriteLine("fail..");
                return false;
            }
                
            Node<T> temp = new Node<T>();
            Node<T> cursor = this.head;

            for (int i = 0; i < p_index; i++)
            {
                cursor = cursor.mNext;
            }

            temp.mData = p_val;
            temp.mNext = cursor.mNext;
            cursor.mNext = temp;
            Count++;

            return true;
        }
        public bool addrange(int p_index,T[] p_arr)
        {
            if (this.head.mNext == null)
                p_index = 1;

            Node<T> cursor = this.head;
            for (int i = 0; i < p_index; i++)
            {
                cursor = cursor.mNext;
            }

            Node<T> next = null;
            //Node temp = null;
            next = cursor.mNext;
            foreach(T num in p_arr)
            {
                Count++;
                Node<T> temp = new Node<T>();
                temp.mData = num;
                temp.mNext = null;
                cursor.mNext = temp;
                cursor = cursor.mNext;
            }
            cursor.mNext = next;
            return true;
        }
        public void outstring()
        {
            Node<T> cursor = this.head;
            if(cursor.mNext == null)
            {
                Console.WriteLine("null");
                return;
            }
                
            while (cursor.mNext != null)
            {
                cursor = cursor.mNext;
                Console.Write($"{cursor.mData}  ");
            }
            Console.WriteLine();
        }
        public bool removeat(int p_index)
        {
            if(this.head == null)
                return false;

            Node<T> cursor = this.head.mNext;
            Node<T> temp = null;
            for(int i = 0; i<p_index; i++)
            {
                temp = cursor;
                cursor = cursor.mNext;
            }
            temp.mNext = cursor.mNext;
            return true;
        }
        public bool clear()
        {
            this.head.mNext = null;
            Count = 0;
            return true;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            vectorint<int> aa = new vectorint<int>();
            aa.push(10);
            aa.push(20);
            aa.push(30);
            aa.outstring();

            aa.insertat(1, 5);
            aa.outstring();

            aa.insertat(8, 77);
            aa.outstring();

            
            int[] num = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            aa.addrange(2, num);
            aa.outstring();

            Console.WriteLine($"size : {aa.Count}");

            aa.clear();
            aa.outstring();
        }
    }
}
