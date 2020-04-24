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

class LRUCache
{
private:
    long idx = 0;
    unordered_map<int, int> _cache;
    unordered_map<int, int> _usage;
    int _capacity;

    void flush()
    {
        if (_cache.size() <= _capacity)
            return;

        int minKey = INT_MAX;
        int minIdx = INT_MAX;

        for (auto item : _usage)
        {
            if (item.second < minIdx)
            {
                minKey = item.first;
                minIdx = item.second;
            }
        }

        _cache.erase(minKey);
        _usage.erase(minKey);
    }

public:
    LRUCache(int capacity)
    {
        _capacity = capacity;
    }

    int get(int key)
    {
        ++idx;

        auto cached = _cache.find(key);
        if (cached == _cache.end())
            return -1;

        int v = cached->second;
        int k = cached->first;

        _usage[k] = idx;

        flush();

        return v;
    }

    void put(int key, int value)
    {
        ++idx;

        _cache[key] = value;
        _usage[key] = idx;

        flush();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache *cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl; // returns 1
    cache->put(3, 3);              // evicts key 2
    cout << cache->get(2) << endl; // returns -1 (not found)
    cache->put(4, 4);              // evicts key 1
    cout << cache->get(1) << endl; // returns -1 (not found)
    cout << cache->get(3) << endl; // returns 3
    cout << cache->get(4) << endl; // returns 4
    return 0;
}
