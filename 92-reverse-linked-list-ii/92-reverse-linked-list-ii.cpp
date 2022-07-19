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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* nodebeforesublist=&dummy;
        int pos=1;
        while(pos<left){
            nodebeforesublist=nodebeforesublist->next;
            pos++;
        }
        ListNode* workingptr=nodebeforesublist->next;
        while(left<right){
            ListNode* nodetobeextracted=workingptr->next;
            workingptr->next=nodetobeextracted->next;

            nodetobeextracted->next=nodebeforesublist->next;
            nodebeforesublist->next=nodetobeextracted;
            left++;
        }
        return dummy.next;
    }
};