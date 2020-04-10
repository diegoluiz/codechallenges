#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *middle = head;
    int currIndex = 0;

    while (head->next != nullptr)
    {
        head = head->next;
        currIndex++;

        if (currIndex % 2 == 0)
        {
            middle = middle->next;
        }
    }

    if (currIndex % 2 == 1)
    {
        middle = middle->next;
    }

    return middle;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node = head;
    for (int i = 2; i <= 5; i++)
    {
        node->next = new ListNode(i);
        node = node->next;
    }

    ListNode *res = middleNode(head);

    // cout << "Result: ";
    while (res->next != nullptr)
    {
        cout << res->val << ", ";
        res = res->next;
    }

    return 0;
}
