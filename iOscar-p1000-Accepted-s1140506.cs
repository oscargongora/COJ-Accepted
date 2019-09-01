using System;
using System.Collections.Generic;
using System.Text;

namespace _000
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            int a = int.Parse(input[0]), b = int.Parse(input[1]);
            int c = a + b;
            Console.WriteLine(c.ToString());
        }
    }
}
