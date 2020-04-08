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

ListNode *merge(ListNode *list1, ListNode *list2)
{
    ListNode *output = new ListNode(INT_MIN);
    ListNode *outputHead = output;

    while (list1 != nullptr || list2 != nullptr)
    {
        int val = 0;
        if (list2 == nullptr)
        {
            val = list1->val;
            list1 = list1->next;
        }
        else if (list1 == nullptr)
        {
            val = list2->val;
            list2 = list2->next;
        }
        else if (list1->val < list2->val)
        {
            val = list1->val;
            list1 = list1->next;
        }
        else
        {
            val = list2->val;
            list2 = list2->next;
        }

        output->next = new ListNode(val);
        output = output->next;
    }

    return outputHead->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *resHead = nullptr;
    ListNode *res = nullptr;

    for (int i = 0; i < lists.size(); i++)
    {
        res = merge(res, lists[i]);
    }
    return res;
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
