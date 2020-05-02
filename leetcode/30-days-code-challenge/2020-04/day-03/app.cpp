#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxSubArrayLocalTest(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int previousSubAraySum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int actualNumber = nums[i];
        if (actualNumber > previousSubAraySum + actualNumber)
        {
            previousSubAraySum = actualNumber;
        }
        else
        {
            previousSubAraySum += actualNumber;
        }

        if (previousSubAraySum > maxSum)
        {
            maxSum = previousSubAraySum;
        }

        cout << "pos: " << i << " => " << nums[i] << " Previous:" << previousSubAraySum << " Max:" << maxSum << endl;
    }
    return maxSum;
}

int maxSubArraySent(vector<int> &nums)
{
    int m = INT_MIN;
    int p = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        p = nums[i] > p + nums[i] ? nums[i] : p + nums[i];
        if (p > m)
            m = p;
    }

    return m;
}

int main()
{
    // print output to user
    cout << "Hello:" << endl;
    // vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5}; // 6
    // vector<int> v = {-2, 1, -3, 4, -1, 0, 0, 0, 2, 1, -5}; // 6
    // vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // 6
    // vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 5}; // 6
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 6}; // 7
    // vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 5, 1}; // 7

    // int o = maxSubArrayLocalTest(v);
    int o = maxSubArraySent(v);
    cout << "Result: " << o << endl;
    return 0;
}
