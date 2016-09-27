#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > verticalOrder(TreeNode* root) {
        vector<vector<int> > res; 
        if (root==NULL)
            return res;
        int left=0, right=0;
        findMinMax(root,0,&left,&right);
        for (int i=left; i<=right;i++){
            res.push_back(vector<int> ());
        }
        // cout << "size: " <<res.size();
        // cout << "before1\n";
        queue<TreeNode*> q;
        // cout << "before2\n";
        for (int i = left;i <= right;i++){
            // cout << "before3\n";
            cout << "loop: " << i << endl;
            traverseVertical(root, root,res,abs(left),i,0,q);
        }
        for (std::vector<vector<int> >::iterator itr = res.begin();itr!=res.end();itr++){
            if (itr->size()==0)
                res.erase(itr);
        }
        return res;
    }
    void traverseVertical(TreeNode* root, TreeNode* cur, vector<vector<int> >& res, int a,int line, int stand, queue<TreeNode*>& q){
        // cout << "in"; 
        cout << cur->val << endl;
        if (cur == NULL)
            return;
        if (line == stand){
            // cout << "line " << line;
            cout << "push: " << cur->val << endl;
            res[line+a].push_back(cur->val);
        }
        // cout << "in1"; 
        if (cur->left!=NULL){
            // cout << "left\n";
            q.push(cur->left);
        }
        if (cur->right!=NULL){
            // cout << "right0\n";
            q.push(cur->right);
        }
        if (q.size()>0){
            TreeNode* temp = q.front();
            // cout << temp->val << endl;;
            q.pop();
            cout << "stand:" << findStand(temp,root,0) << endl;
            traverseVertical(root, temp,res,a,line,findStand(temp,root,0),q);
        }
        else return;
    }
    int findStand(TreeNode *t, TreeNode *root, int level){
        if (root==NULL)
            return 0;
        if (t == root)
            return level;
        else {
            return findStand(t,root->left,level-1) + findStand(t,root->right, level+1);
        }
    }
    void findMinMax(TreeNode* root, int t, int* min, int* max){
        if (root==NULL)
            return;
        if (t < (*min))
            (*min) = t;
        // cout << "int\n";
        if (t > (*max))
            (*max) = t;
        findMinMax(root->left,t-1, min, max);
        findMinMax(root->right,t+1, min, max);
        
    }
};

int main(){
    TreeNode a(3),b(9),c(20),e(15),f(7),g(1),h(4);
    // a.left = &b;
    // b.right = &c;
    // c.left = &e;
    // c.right = &f;
    // f.left = &g;
    a.left = &b;
    a.right = &c;
    c.left=&e;
    c.right=&f;
    e.left = &g;
    f.right = &h;
    int left=0,right=0;
    vector<vector<int> > res;

    Solution s;

    // cout << "lll\n";
    // s.findMinMax(&a, 0, &left,&right);
    // cout << left << " " << right << endl;

    res = s.verticalOrder(&a);
    
    for (int i = 0; i < res.size();i++){

        for (int j =0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        if (res[i].size() == 0){
            cout << "asd";
            continue;
        }
        else
            cout << endl;
    }
}