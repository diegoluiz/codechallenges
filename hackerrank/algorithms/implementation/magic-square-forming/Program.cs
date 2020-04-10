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

class Solution {

    // Complete the formingMagicSquare function below.
    static int formingMagicSquare(int[][] s) {

return 0;
    }

    static void Main(string[] args) {
        int[][] s = new int[3][];

        for (int i = 0; i < 3; i++) {
            s[i] = Array.ConvertAll(Console.ReadLine().Split(' '), sTemp => Convert.ToInt32(sTemp));
        }

        int result = formingMagicSquare(s);

        Console.WriteLine(result);
    }
}
