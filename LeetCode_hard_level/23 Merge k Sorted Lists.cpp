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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int>st;
        for(auto vc:lists)
        for(ListNode* it=vc;it!=NULL;it=it->next)
            st.insert(it->val);
        ListNode *ret = new ListNode(0),*p = ret;
        for(auto it=st.begin();it!=st.end();it++)
        {
            p->next = new ListNode(*it);
            p=p->next;
        }
        return ret->next;
    }
};