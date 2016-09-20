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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        	return head;
        ListNode *now = head, *nextp=head->next, *pre=NULL;
        while (now != NULL){
        	now->next = pre;
        	pre = now;
        	now = nextp;
        	if (now!= NULL)
        	    nextp = now->next;
        }
        return pre;
    }
};