#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <list>
#include <stack>
#include <string>
#include <chrono>

using namespace std;

#define all(x) (x).begin(), (x).end()

class FirstUnique
{
public:
    list<int> queue;
    unordered_map<int, bool> uniq;
    FirstUnique(vector<int> &nums)
    {
        for (auto i : nums)
        {
            if (uniq.find(i) == uniq.end())
            {
                queue.push_back(i);
                uniq[i] = true;
            }
            else
            {
                uniq[i] = false;
            }
        }
    }

    int showFirstUnique()
    {
        for (auto it : queue)
        {
            if (uniq[it] == true)
            {
                return it;
            }
        }
        return -1;
    }

    void add(int value)
    {
        if (uniq.find(value) == uniq.end())
        {
            queue.push_back(value);
            uniq[value] = true;
        }
        else
        {
            uniq[value] = false;
        }
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> input = {2, 3, 5};
    FirstUnique *firstUnique = new FirstUnique(input);
    cout << firstUnique->showFirstUnique() << endl; // return 2
    firstUnique->add(5);                            // the queue is now [2,3,5,5]
    cout << firstUnique->showFirstUnique() << endl; // return 2
    firstUnique->add(2);                            // the queue is now [2,3,5,5,2]
    cout << firstUnique->showFirstUnique() << endl; // return 3
    firstUnique->add(3);                            // the queue is now [2,3,5,5,2,3]
    cout << firstUnique->showFirstUnique() << endl; // return -1

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    cout << "Case 1 Took: " << elapsed.count() << endl;

    start = std::chrono::high_resolution_clock::now();

    input = {7, 7, 7, 7, 7, 7};
    firstUnique = new FirstUnique(input);
    cout << firstUnique->showFirstUnique() << endl; // return -1
    firstUnique->add(7);                            // the queue is now [7,7,7,7,7,7,7]
    firstUnique->add(3);                            // the queue is now [7,7,7,7,7,7,7,3]
    firstUnique->add(3);                            // the queue is now [7,7,7,7,7,7,7,3,3]
    firstUnique->add(7);                            // the queue is now [7,7,7,7,7,7,7,3,3,7]
    firstUnique->add(17);                           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
    cout << firstUnique->showFirstUnique() << endl; // return 17
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    cout << "Case 2 Took: " << elapsed.count() << endl;

    input = {1, 2, 3};

    return 0;
}
