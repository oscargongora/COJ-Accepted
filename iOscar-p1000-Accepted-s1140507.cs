using System;

namespace Sum {
    class Program {
        static void Main(string[] args) {
            string[] aux = Console.ReadLine().Split();
            int a = int.Parse(aux[0]);
            int b = int.Parse(aux[1]);
            Console.WriteLine((a + b).ToString());
        }
    }
}