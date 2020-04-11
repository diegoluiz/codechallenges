using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution
{

    private static bool validateSquare(int[][] s, int v)
    {
        var sums = getSquareSums(s);
        return sums.All(x => x == v);
    }

    private static int[] getSquareSums(int[][] s)
    {
        // sums for rows, cols, and diags
        int[] sums = new int[] { 0, 0, 0, 0, 0, 0, 0, 0 };
        for (var i = 0; i < 3; i++)
        {
            for (var j = 0; j < 3; j++)
            {
                sums[i] += s[i][j];
                sums[i + 3] += s[j][i];
            }

            sums[6] += s[i][i];
            sums[7] += s[i][2 - i];
        }

        return sums;
    }

    private static int[] getDiffs(int[] sums, int v)
    {
        return sums.Select(x => v - x).ToArray();
    }

    private static HashSet<int> getDuplicated(int[][] s)
    {
        return s.SelectMany(x => x).GroupBy(x => x).Where(x => x.Count() > 1).Select(x => x.Key).ToHashSet();
    }

    private static HashSet<int> getMissingNumbers(int[][] s)
    {
        HashSet<int> missingNumber = new HashSet<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        for (var i = 0; i < 3; i++)
            for (var j = 0; j < 3; j++)
                if (missingNumber.Contains(s[i][j]))
                    missingNumber.Remove(s[i][j]);

        return missingNumber;
    }

    private static void print(int[][] s, int[] sums, int[] diffs)
    {
        Console.WriteLine("Square:");
        for (var i = 0; i < 3; i++)
        {
            for (var j = 0; j < 3; j++)
            {
                Console.Write($"{s[i][j]}   ");
            }
            Console.WriteLine($" = {sums[i]}");
        }

        Console.WriteLine($"-----------------");
        for (var i = 0; i < 3; i++)
        {
            Console.Write($"{sums[i + 3]}".PadRight(4, ' '));
        }
        Console.WriteLine($"");
        Console.WriteLine($"Diags: {sums[6]} and {sums[7]}");
    }

    static int formingMagicSquare(int[][] s)
    {
        var expectedSideSum = 15;
        var missingNumber = getMissingNumbers(s);
        var duplicatedNumbers = getDuplicated(s);
        var sums = getSquareSums(s);
        var diffs = getDiffs(sums, expectedSideSum);

        print(s, sums, diffs);

        validateSquare(s, expectedSideSum);

        return 0;
    }

    static void Main(string[] args)
    {
        Dictionary<int[][], int> cases = new Dictionary<int[][], int>
        {
            {
                new int[][] {
                    new int[]{5, 3, 4},
                    new int[]{1, 5, 8},
                    new int[]{6, 4, 2},
                },
                7
            },
            {
                new int[][] {
                    new int[]{4, 9, 2},
                    new int[]{3, 5, 7},
                    new int[]{8, 1, 5},
                },
                1
            },
            {
                new int[][] {
                    new int[]{4, 8, 2},
                    new int[]{4, 5, 7},
                    new int[]{6, 1, 6},
                },
                4
            }
        };

        foreach (var testCase in cases)
        {
            int result = formingMagicSquare(testCase.Key);

            Console.WriteLine($"Result: {result}. Expected: {testCase.Value}");
        }
    }

    // static void Main(string[] args) {
    //     TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

    //     int[][] s = new int[3][];

    //     for (int i = 0; i < 3; i++) {
    //         s[i] = Array.ConvertAll(Console.ReadLine().Split(' '), sTemp => Convert.ToInt32(sTemp));
    //     }

    //     int result = formingMagicSquare(s);

    //     textWriter.WriteLine(result);

    //     textWriter.Flush();
    //     textWriter.Close();
    // }
}
