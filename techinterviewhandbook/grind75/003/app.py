from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        output = ListNode()
        ini = output
        
        has_item = list1 != None or list2 != None
        
        while has_item:
            if list1 is None:
                output.next = ListNode(list2.val)
                list2 = list2.next
            elif list2 is None:
                output.next = ListNode(list1.val)
                list1 = list1.next
            else:
                if list1.val < list2.val:
                    output.next = ListNode(list1.val)
                    list1 = list1.next
                else:
                    output.next = ListNode(list2.val)
                    list2 = list2.next
            output = output.next
            has_item = list1 != None or list2 != None
            
        return ini.next
            
        
if __name__ == '__main__':
    s = Solution()
    a = ListNode(1, ListNode(2, ListNode(4)))
    b = ListNode(1, ListNode(3, ListNode(4)))
    print(s.mergeTwoLists(a,b))