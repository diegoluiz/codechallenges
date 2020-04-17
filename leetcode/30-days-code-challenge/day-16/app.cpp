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
        bool newOpened = true;
        bool currentOpened = true;

        stack<int> opened, closed;
        stack<int> wildcard;

        int openCloseIdx = s.find("()");
        while (openCloseIdx >= 0)
        {
            s.erase(openCloseIdx, 2);
            openCloseIdx = s.find("()");
        }

        for (int i = 0; i < s.size(); i++)
        {
            char character = s[i];
            if (character == '(')
            {
                newOpened = true;
                opened.push(i);
            }
            else if (character == '*')
            {
                wildcard.push(i);
            }
            else if (character == ')')
            {
                newOpened = false;
                closed.push(i);
            }

            if (currentOpened != newOpened)
            {
                if (!currentOpened)
                {
                    int tempOpened = opened.top();
                    opened.pop();

                    int ini = INT_MIN;

                    while (!closed.empty() && (!opened.empty() || !wildcard.empty()))
                    {
                        closed.pop();
                        if (opened.empty())
                        {
                            ini = wildcard.top();
                            wildcard.pop();
                        }
                        else
                        {
                            ini = opened.top();
                            opened.pop();
                        }
                    }

                    if (!closed.empty())
                    {
                        return false;
                    }

                    opened.push(tempOpened);
                }

                currentOpened = newOpened;
            }
        }

        while (!closed.empty() && (!opened.empty() || !wildcard.empty()))
        {
            closed.pop();
            opened.empty() ? wildcard.pop() : opened.pop();
        }

        while (!opened.empty() && !wildcard.empty())
        {
            if (opened.top() > wildcard.top())
            {
                wildcard.pop();
                continue;
            }
            opened.pop();
            wildcard.pop();
        }

        return closed.empty() && opened.empty();
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
