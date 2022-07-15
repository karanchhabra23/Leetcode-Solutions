/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class cmp{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        for(auto &it:lists){
            if(it!=NULL)
                q.push(it);
        }
        
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        
        while(!q.empty()){
            ListNode* temp = q.top();
            q.pop();
            if(temp->next!=NULL){
                q.push(temp->next);
            }
            ans->next = new ListNode(temp->val);
            ans = ans->next;
        }
        return head->next;
    }
};