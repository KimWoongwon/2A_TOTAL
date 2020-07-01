using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.WebSockets;
using System.Security.Cryptography.X509Certificates;
using System.Text.RegularExpressions;

namespace ConsoleApp2
{
    class Person
    {
        public string name = "";
        public float avr = 0;
    }
    class Program
    {
        
        static bool testfn(int p_x)
        {
            return p_x > 12;
        }
        static void Main(string[] args)
        {
            List<Person> listStudent = new List<Person>
            {
                new Person() { name = "김철수", avr = 78.5f},
                new Person() { name = "김영희", avr = 91.2f},
                new Person() { name = "홍길동", avr = 77.3f},
                new Person() { name = "김길수", avr = 80.8f},
                new Person() { name = "김영순", avr = 54.2f},
                new Person() { name = "김상수", avr = 90.8f},
                new Person() { name = "이한수", avr = 61.4f}

            };

            var result = from item in listStudent
                         orderby item.avr
                         group item by (int)(item.avr / 10) into outdata
                         select new
                         {
                             Grade = outdata.Key,
                             resultarr = outdata.ToArray()
                         };
            
            foreach(var item in result)
            {
                Console.WriteLine($" < 성적 : {item.Grade * 10} ~ {(item.Grade + 1) * 10} > ");
                foreach(var item2 in item.resultarr)
                    Console.WriteLine($"\t {item2.name} , {item2.avr}");
                Console.WriteLine();
            }

            //foreach(var item in result)
            //{
            //    Console.WriteLine(" < {0}씨 > ", item.Key);
            //    foreach(var item2 in item)
            //    {
            //        Console.WriteLine($"\t\t {item2.name}, {item2.avr}");
            //    }
            //}

            //int[] arr = { 20, 3, 7, 12, 6, 21, 4, 15 };

            ////IEnumerable<int> arrresult = arr.Where( (x) => x > 12 );

            ////foreach (var item in arrresult)
            ////    Console.WriteLine(item);

            //IEnumerable<int> result = from number in arr
            //                          where number > 7   // 조건식이 들어가며 bool 형 반환이 되는 조건이라면 왠만한건 다 된다.
            //                          orderby number descending // descending 이 들어가면 내림차순 정렬 아니라면 오름차순 정렬
            //                          select number;
            ////IEnumerable 은 result[0]와 같은 방법으로 접근할 수 없다.

            //IEnumerable<int> result_2 = arr.Where((number) => number > 7).OrderBy((number) => number).Select((number) => number);
            //// result와 result_2의 결과는 같다. 하지만 result_2와 같은 형식은 고인물들의 전유물이다.


            ////int[] resultarr = result.ToArray();
            //int[] resultarr = result_2.ToArray();
            //foreach (var item in resultarr)
            //    Console.WriteLine(item);




        }
    }
}
