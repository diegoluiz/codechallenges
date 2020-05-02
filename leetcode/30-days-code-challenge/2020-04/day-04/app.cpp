#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void printArray(vector<int> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void moveZeroesLocalTest(vector<int> &nums)
{
    int zerosCount = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        int currentNumber = nums[i];
        if (currentNumber == 0)
        {
            cout << "FOUND 0 AT " << i << endl;
            zerosCount++;
        }
        else
        {
            if (zerosCount > 0)
            {
                nums[i - zerosCount] = currentNumber;
            }
        }
        printArray(nums);
    }

    for (int i = size - zerosCount; i < size; i++)
    {
        nums[i] = 0;
    }
}

void moveZeroesSent(vector<int> &nums)
{
    int c = 0;
    int s = nums.size();
    for (int i = 0; i < s; i++)
    {
        if (nums[i] == 0)
        {
            c++;
        }
        else
        {
            if (c > 0)
            {
                nums[i - c] = nums[i];
            }
        }
    }

    for (int i = s - c; i < s; i++)
        nums[i] = 0;
}

int main()
{
    cout << "Hello:" << endl;
    vector<int> v = {0, 1, 0, 3, 12}; // [1,3,12,0,0]

    // moveZeroesLocalTest(v);
    moveZeroesSent(v);
    cout << "Result: ";
    printArray(v);

    return 0;
}
