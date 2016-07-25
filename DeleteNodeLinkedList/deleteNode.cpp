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
    void deleteNode(ListNode* node) {
        ListNode *tmp = node, * tmp1 = NULL, *bef = node;
        while (tmp->next != NULL){
        	tmp1 = tmp->next;
        	tmp->val = tmp1->val;
        	bef = tmp;
        	tmp = tmp->next;
        }
        bef->next = NULL;
        delete tmp;
    }
};