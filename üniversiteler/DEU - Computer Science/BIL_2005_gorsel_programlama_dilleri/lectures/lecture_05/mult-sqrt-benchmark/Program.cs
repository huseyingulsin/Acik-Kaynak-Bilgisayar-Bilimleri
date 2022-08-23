using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Stopwatch
using System.Diagnostics;

namespace mult_sqrt_benchmark
{
    class Program
    {
        public static bool isPrimeRoot(int num)
        {
            if(num < 2)
            {
                return false;
            }
            for(int i = 2; i <= Math.Sqrt(num); i++)
            {
                if(num % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
        public static bool isPrimeSquare(int num)
        {
            if (num < 2)
            {
                return false;
            }
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
            return true;

        }

        static void Main(string[] args)
        {
            int LIMIT = 123456;
            int TIMES = 100;
            Stopwatch square_timer = new Stopwatch();
            Stopwatch root_timer = new Stopwatch();

            for(int i = 0; i < TIMES; i++)
            {
                root_timer.Start();
                for (int j = 0; j < LIMIT; j++)
                {
                    bool b = isPrimeRoot(j);
                }
                root_timer.Stop();

                square_timer.Start();
                for (int j = 0; j < LIMIT; j++)
                {
                    bool b = isPrimeSquare(j);
                }
                square_timer.Stop();
            }

            long root = root_timer.ElapsedMilliseconds;
            long square = square_timer.ElapsedMilliseconds;
            Console.WriteLine("Root: " + root.ToString() + "ms");
            Console.WriteLine("Square: " + square.ToString() + "ms");
            Console.WriteLine("Difference: %" + ((root * 100.0) / square - 100).ToString());
            Console.ReadKey();
        }
    }
}
