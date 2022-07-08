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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        
        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;
        
        while(l1 || l2){
            if(l1==NULL){
                dummy->next = l2;
                break;
            }
            if(l2==NULL){
                dummy->next = l1;
                break;
            }
            
            if(l1->val<l2->val){
                dummy->next = l1;
                l1 = l1->next;
                dummy = dummy->next;
            }
            else{
                dummy->next = l2;
                l2 = l2->next;
                dummy = dummy->next;
            }
        }
        return head->next;
    }
};