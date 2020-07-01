using System;
using System.Runtime.CompilerServices;
using System.Security;
using System.Security.Cryptography.X509Certificates;

namespace _200603
{
    delegate void myFn(int a, int b);
    class Program
    {
        static void TestFn(int a, int v)
        {

        }
        static void Main(string[] args)
        {
            int tempresult = 10;
            myFn fn = (a, v) =>
            {
                int result = a + v;
                tempresult += 30;

            };
            Func<int, int, int> fnc = (x,y) => x + y; 

            Console.WriteLine($"{fnc(10,20)}");

        }
    }
}
