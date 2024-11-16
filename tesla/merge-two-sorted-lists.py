class ListNode:
    def __init__(self, val = 0,next = None):
        self.val = val
        self.next = next

def mergeTwoLists(self, list1, list2):
    ptr1 = list1
    ptr2 = list2
    new_list = ListNode(0)
    current = new_list
    while(ptr1 and ptr2):
        if ptr1.val <= ptr2.val:
            current.next = ptr1
            ptr1 = ptr1.next
        else:
            current.next = ptr2
            ptr2 = ptr2.next
        current = current.next
    current.next = ptr1 if ptr1 else ptr2
    return new_list.next