#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void print_sol(ListNode *head){
        while (head!=NULL){
            cout << head->val << endl;
            head = head->next;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* pre = head, *now = head->next, *after = head->next->next, * re = head-> next;
        
        while (now !=NULL){
            pre->next = after;
            now -> next = pre;
            // cout << "before" << endl;
            // this->print_sol(now);
            // cout << "after" << endl;
            if (after == NULL || after->next==NULL)
                break;
            now = after -> next;
            pre->next = now;
            pre = after;
            after = after->next->next;
            
        }
        return re;
    }
    
};

int main(){
    ListNode a(1),b(2),c(3),d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution s;
    s.print_sol(s.swapPairs(&a));
}