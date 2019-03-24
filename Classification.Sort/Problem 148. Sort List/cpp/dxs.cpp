/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
        {
            return head;
        }
        ListNode* pstL=head;
        ListNode* pstR=head->next;
        while(pstR&&pstR->next)
        {
            pstL=pstL->next;
            pstR=pstR->next->next;
        }
        ListNode* pstS;
        pstS=pstL->next;
        pstL->next=NULL;
        return mergeSortedList(sortList(head), sortList(pstS));
    }
private:
    ListNode* mergeSortedList(ListNode* pstH1, ListNode* pstH2)
    {
        if (!pstH1&&!pstH2)
        {
            cout<<"Two NULL inputs"<<endl;
            return NULL;
        }
        
        if(!pstH1||!pstH2)return pstH1?pstH1:pstH2;
    
        if(pstH1->val<pstH2->val)
        {
            pstH1->next=mergeSortedList(pstH1->next, pstH2);
            return pstH1;
        }
        else
        {
            pstH2->next=mergeSortedList(pstH1, pstH2->next);
            return pstH2;
        }
    }
};