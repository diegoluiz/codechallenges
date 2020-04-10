#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countElements(vector<int> &arr)
{
    unordered_set<int> s;
    int output = 0;
    int size = arr.size();
    int i;

    for (i = 0; i < size; i++)
    {
        s.insert(arr[i]);
    }

    for (i = 0; i < size; i++)
    {
        int value = arr[i] + 1;
        if (s.find(value) != s.end())
        {
            output++;
        }
    }

    return output;
}

int main()
{
    vector<int> v = {1, 3, 2, 3, 5, 0};

    int res = countElements(v);
    cout << "Result: " << res;

    return 0;
}
