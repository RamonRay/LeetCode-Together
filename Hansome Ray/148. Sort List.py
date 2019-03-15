# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        fast = head
        slow = head
        slowAhead = head
        while fast and fast.next:
            slowAhead = slow
            slow = slow.next
            fast = fast.next.next
        slowAhead.next = None
        #分治法递归分解链表
        l1 = self.sortList(head)
        l2 = self.sortList(slow)
        #递归后的链表已经有序
        #合并两个有序链表
        return self.mergeSort(l1, l2)

    def mergeSort(self, l1, l2):
        p = dummy = ListNode(0)
        #合并有序链表
        while l1 and l2:
            if l1.val > l2.val:
                p.next = l2
                l2 = l2.next
            else:
                p.next = l1
                l1 = l1.next
            p = p.next
        #接上没有在循环中穷尽的链表
        p.next = l1 or l2
        return dummy.next
