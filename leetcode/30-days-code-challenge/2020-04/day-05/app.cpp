#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxProfitSent(vector<int> &prices)
{
    int p = 0;
    int t = INT_MIN;

    bool g = true;

    for (int i = 0; i < prices.size(); i++)
    {
        int c = prices[i];

        int n = INT_MIN;
        if (i + 1 < prices.size())
        {
            n = prices[i + 1];
        }

        if (g)
        {
            if (c < n)
            {
                t = c;
                g = !g;
            }
        }
        else
        {
            if (c > n)
            {
                p += (c - t);
                t = INT_MIN;
                g = !g;
            }
        }
    }

    return p;
}

int maxProfitLocalTest(vector<int> &prices)
{
    int profit = 0;
    int currentValueInHand = INT_MIN;

    bool findMin = true;

    for (int i = 0; i < prices.size(); i++)
    {
        int currValue = prices[i];

        int nextValue = INT_MIN;
        if (i + 1 < prices.size())
        {
            nextValue = prices[i + 1];
        }

        if (findMin)
        {
            if (currValue < nextValue)
            {
                currentValueInHand = currValue;
                findMin = false;
            }
            else
            {
                continue;
            }
        }
        else
        {
            if (currValue > nextValue)
            {
                profit += (currValue - currentValueInHand);
                currentValueInHand = INT_MIN;
                findMin = true;
            }
            else
            {
                continue;
            }
        }
    }

    return profit;
}

int main()
{
    cout << "Hello:" << endl;
    // vector<int> v = {7, 1, 5, 3, 6, 4}; // 7
    vector<int> v = {1, 2, 3, 4, 5}; // 4
    // vector<int> v = {7, 6, 4, 3, 1};    // 0

    int res = maxProfitSent(v);
    cout << "Result: " << res;

    return 0;
}
