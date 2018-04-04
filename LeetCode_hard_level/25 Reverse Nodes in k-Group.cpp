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
    ListNode* p;
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ret,*q = head, *tmp;
        p = ret = new ListNode(1);
        while(q!=NULL)
        {
            int cnt=0;
            for(ListNode *i=q;i!=NULL&&cnt!=k;tmp=i=i->next,cnt++)
                ;
            if(cnt==k)
                dfs(q,k),q=tmp;
            else 
            {
                while(q!=NULL)
                {
                    p->next = q;
                    p=p->next;
                    q=q->next;
                }
                break;
            }
        }
        p->next = NULL;
        return ret->next;
    }
    void dfs(ListNode *x, int k)
    {
        if(k-1)
            dfs(x->next, k-1);
        p->next = x;
        p = p->next;
    }
};