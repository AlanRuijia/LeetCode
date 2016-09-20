#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1==NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* res=NULL, *pre=NULL, *head=l1->val < l2->val? l1:l2;
        // cout << "in " << head->val << endl;
        while(l1!=NULL && l2!=NULL){
            if (l1->val < l2->val){
                pre = res;
                res = l1;
                if (pre)
                    pre->next = res;
                l1 = l1->next;
            }
            else{
                pre = res;
                res = l2;
                if (pre)
                    pre->next = res;
                l2 = l2->next;
            }
        }
        if (l1 != NULL)
            res->next = l1;
        if (l2 != NULL)
            res->next=l2;
        
        return head;
    }
};

int main(){
    Solution s;
    ListNode a(2),b(1);
    s.mergeTwoLists(&a,&b);
}