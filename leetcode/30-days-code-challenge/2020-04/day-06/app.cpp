#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <tr1/unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    std::tr1::unordered_map<std::string, vector<string>> m;

    for (int i = 0; i < strs.size(); i++)
    {
        string originalWord = strs[i];
        string sortedWord = originalWord;
        std::sort(sortedWord.begin(), sortedWord.end());

        if (m.find(sortedWord) == m.end())
        {
            vector<string> a;
            m[sortedWord] = a;
        }

        m[sortedWord].push_back(originalWord);
        cout << originalWord << " => " << sortedWord << endl;
    }

    vector<vector<string>> output;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        vector<string> a = it->second;
        output.push_back(a);
    }

    return output;
}

int main()
{
    cout << "Hello:" << endl;
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> res = groupAnagrams(v);
    cout << "Result: ";

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
