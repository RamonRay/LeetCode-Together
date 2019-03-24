# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#divide and conquer, 260ms
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
        #���η��ݹ�ֽ�����
        l1 = self.sortList(head)
        l2 = self.sortList(slow)
        #�ݹ��������Ѿ�����
        #�ϲ�������������
        return self.mergeSort(l1, l2)

    def mergeSort(self, l1, l2):
        p = dummy = ListNode(0)
        #�ϲ���������
        while l1 and l2:
            if l1.val > l2.val:
                p.next = l2
                l2 = l2.next
            else:
                p.next = l1
                l1 = l1.next
            p = p.next
        #����û����ѭ�����������
        p.next = l1 or l2
        return dummy.next
# using qs, recording all values 106ms
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        listValue=[]
        tmp=head
        while tmp:
            listValue.append(tmp.val)
            tmp=tmp.next
        listValue.sort()
        tmp=head
        i=0
        while tmp:
            tmp.val=listValue[i]
            i=i+1
            tmp=tmp.next
        return head