using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    delegate void EventHandler(string message);
    class MyNotifir
    {
        public event EventHandler Somethinghappend = null;
        public void DoSomething(int number)
        {
            int temp = number % 10;
            if (temp != 0 && temp % 3 == 0)
            {
                if (Somethinghappend != null)
                {
                    Somethinghappend(string.Format("{0} : 짝", number));
                }
            }
        }
    }
    class testFN
    {
        public void EventTest02(string message)
        {
            Console.WriteLine("Eventtest02 = {0}", message);
        }
    }
    class Program
    {
        static void EventTest01(string message)
        {
            Console.WriteLine("Eventtest01 = {0}", message);
        }
        static void Main(string[] args)
        {
            MyNotifir testcls = new MyNotifir();
            testcls.Somethinghappend += EventTest01;
            testFN testcls2 = new testFN();
            testcls.Somethinghappend += testcls2.EventTest02;

            for (int i = 0; i<1000; i++)
            {
                testcls.DoSomething(i);
            }
        }
    }
}
