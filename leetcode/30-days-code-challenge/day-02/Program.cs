using System;
using System.Collections.Generic;

namespace day_02
{
    class Program
    {
        public static bool IsHappy(int n)
        {
            var s = new HashSet<int> { };
            while (!s.Contains(n))
            {
                if (n == 1) return true;

                s.Add(n);
                
                var m = n;
                n = 0;
                while (m != 0)
                {
                    var t = m % 10;
                    n += t * t;
                    m /= 10;
                }
            }

            return false;
        }

        static void Main(string[] args)
        {
            for (var n = 0; n < 100; n++)
            {
                Console.WriteLine($"Is {n} happy? {IsHappy(n)}".ToLower());
            }
        }
    }
}
