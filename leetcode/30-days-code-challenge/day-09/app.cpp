#include <iostream>

using namespace std;

int calculateIndex(string text, int textIdx)
{
    int textSkip = 0;
    while (textIdx >= 0 && text[textIdx] == '#')
    {
        while (textIdx >= 0 && text[textIdx] == '#')
        {
            textIdx--;
            textSkip++;
        }

        while (textSkip > 0 && textIdx >= 0 && text[textIdx] != '#')
        {
            textIdx--;
            textSkip--;
        }
    }
    return textIdx;
}

bool backspaceCompare(string S, string T)
{
    int tIdx = T.length() - 1;
    int sIdx = S.length() - 1;

    while (sIdx >= 0 || tIdx >= 0)
    {
        tIdx = calculateIndex(T, tIdx);
        sIdx = calculateIndex(S, sIdx);

        if (sIdx < 0 && tIdx < 0)
            return true;

        char s = sIdx >= 0 ? S[sIdx] : '+';
        char t = tIdx >= 0 ? T[tIdx] : '-';

        if (s != t)
            return false;

        tIdx--;
        sIdx--;
    }

    return true;
}

int main()
{
    bool res;
    res = backspaceCompare("ab#c", "ad#c");
    cout << "ab#c == ad#c => " << res << endl;

    res = backspaceCompare("ab##", "c#d#");
    cout << "ab## == c#d# => " << res << endl;

    res = backspaceCompare("a##c", "#a#c");
    cout << "a##c == #a#c => " << res << endl;

    res = backspaceCompare("a#c", "b");
    cout << "a#c == b => " << res << endl;

    res = backspaceCompare("aabcc#dee#ffff###ghi", "abcdefghi");
    cout << "aabcc#dee#ffff###ghi == abcdefghi => " << res << endl;

    res = backspaceCompare("bxj##tw", "bxo#j##tw");
    cout << "bxj##tw == bxo#j##tw => " << res << endl;

    return 0;
}
