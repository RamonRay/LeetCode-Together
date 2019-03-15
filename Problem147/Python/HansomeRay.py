class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
def insertionSortList(head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    p=dummy=ListNode(0)
    cur=dummy.next=head
    while cur and cur.next:
        nextVal=cur.next.val
        if nextVal>cur.val:
            cur=cur.next
            continue
        if p.next.val>nextVal:
            p=dummy
        while p.next.val<nextVal:
            p=p.next
        tmp=cur.next
        cur.next=tmp.next
        tmp.next=p.next
        p.next=tmp
    return dummy.next
def init(ans):
    head=ListNode(ans[0])
    tmp=head
    for i in range(1,len(ans)):
        new=ListNode(ans[i])
        tmp.next=new
        tmp=new
    return head
def read(head):
   print head.val
   head=head.next
   while head!=None:
      print head.val
      head=head.next




newQuickSort(nums)
head=init([4,2,1,3])
head=insertionSortList(head)
read(head)

