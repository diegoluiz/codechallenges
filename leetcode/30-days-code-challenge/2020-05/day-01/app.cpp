#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <string>
#include <chrono>

using namespace std;

#define all(x) (x).begin(), (x).end()

class Solution
{
private:
    int _badRevision;

public:
    Solution(int badRevision)
    {
        _badRevision = badRevision;
    }

    bool isBadVersion(int n)
    {
        return n >= _badRevision;
    }

    int firstBadVersion(int ini, int fin)
    {
        int mid = ((long)ini + (long)fin) / 2;
        int r = isBadVersion(mid);

        if (r && mid == ini)
            return ini;

        if (!r && ini + 1 == fin)
            return fin;

        if (r)
        {
            ini = ini;
            fin = mid;
        }
        else
        {
            ini = mid;
            fin = fin;
        }
        return firstBadVersion(ini, fin);
    }

    int firstBadVersion(int n)
    {
        if (isBadVersion(0))
            return 0;

        return firstBadVersion(0, n);
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    auto res = Solution(4).firstBadVersion(5);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    cout << "Case 1 (Expected 4): " << res << ". Took: " << elapsed.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    res = Solution(7).firstBadVersion(10);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    cout << "Case 2 (Expected 7): " << res << ". Took: " << elapsed.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    res = Solution(1).firstBadVersion(3);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    cout << "Case 3 (Expected 1): " << res << ". Took: " << elapsed.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    res = Solution(2).firstBadVersion(3);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    cout << "Case 4 (Expected 2): " << res << ". Took: " << elapsed.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    res = Solution(1702766719).firstBadVersion(2126753390);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    cout << "Case 5 (Expected 2): " << res << ". Took: " << elapsed.count() << endl;

    return 0;
}
