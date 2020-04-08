#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *resHead = nullptr;
    ListNode *res = nullptr;

    while (true)
    {
        int minIndex = INT_MIN;
        int currMin = INT_MAX;
        bool allEmpty = true;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *item = lists[i];
            if (item != nullptr && item->val < currMin)
            {
                minIndex = i;
                currMin = item->val;
                allEmpty = false;
            }
        }

        if (allEmpty)
        {
            break;
        }

        if (res == nullptr)
        {
            res = new ListNode(lists[minIndex]->val);
            resHead = res;
        }
        else
        {
            res->next = new ListNode(lists[minIndex]->val);
            res = res->next;
        }
        lists[minIndex] = lists[minIndex]->next;
    }

    return resHead;
}

int main()
{
    ListNode *item1 = new ListNode(1);
    item1->next = new ListNode(4);
    item1->next->next = new ListNode(5);

    ListNode *item2 = new ListNode(1);
    item2->next = new ListNode(3);
    item2->next->next = new ListNode(4);

    ListNode *item3 = new ListNode(2);
    item3->next = new ListNode(6);

    vector<ListNode *> v{item1, item2, item3};
    ListNode *res = mergeKLists(v); // 1->1->2->3->4->4->5->6

    cout << "Result: " << endl;
    while (res != nullptr)
    {
        cout << res->val << ", ";
        res = res->next;
    }

    return 0;
}
