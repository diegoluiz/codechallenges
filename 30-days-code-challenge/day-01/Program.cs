using System;
using System.Collections.Generic;

namespace day_01
{
    class Program
    {
        public static int SingleNumber(int[] nums)
        {
            var hashMap = new Dictionary<int, int>();
            foreach (var i in nums)
            {
                if (!hashMap.ContainsKey(i))
                {
                    hashMap.Add(i, 0);
                }

                hashMap[i] += 1;
            }

            foreach (var i in hashMap)
            {
                if (i.Value == 1)
                {
                    return i.Key;
                }
            }

            return -1;
        }

        static void Main(string[] args)
        {
            var o = SingleNumber(new int[] { 4, 1, 2, 1, 2 });
            Console.WriteLine($"{o}");
        }
    }
}
