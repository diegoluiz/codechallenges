#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <string>

using namespace std;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    bool checkValidString(string s)
    {
        int ini = 0;
        int fin = 0;

        for (char c : s)
        {
            ini += c == '(' ? 1 : -1;
            fin += c != ')' ? 1 : -1;
            if (fin < 0) return false;
            ini = max(ini, 0);
        }

        return ini == 0;
    }
};

int main()
{
    vector<tuple<string, bool>> cases = {
        {"()", true},
        {"(*)", true},
        {"**", true},
        {"", true},
        {"(*))", true},
        {"(()*", true},
        {"*())", true},
        {"(*)(*", true},
        {"(*))", true},
        {"(*)(*)(*))", true},
        {"((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()", true},
        {"(()(())()())*((()(())))*()(*)()()(*((()((*(*))))()*()(()((()(*((()))*(((())(())))*))(()*))(()*)", true},
        {"())", false},
        {"*))", false},
        {"(()", false},
        {"(*)(", false},
        {"(*)(*)(*)(", false},
        {"(((", false},
        {")))", false},
        {"(", false},
        {")", false},
        {")(", false},
        {"(())((())()()(*)(*()(())())())()()((()())((()))(*", false},
        {"()(*(*()()(*)(()())((*))()(()(*((*)))))*)()(()))((", false},
    };

    for (auto i = 0; i < cases.size(); i++)
    {
        string input;
        bool output;

        tie(input, output) = cases[i];

        auto res = Solution().checkValidString(input);

        cout << "Case " << i << " (Expected " << output << "): " << res << endl;
    }

    return 0;
}
