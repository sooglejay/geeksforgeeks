//
// Created by sooglejay on 17/5/7.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return solve(s, t);
    }
    bool solve(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        bool flag = false;
        if (s->val == t->val) {
            flag = check(s->left, t->left) && check(s->right, t->right);
        }
        return flag || solve(s->left, t) || solve(s->right, t);
    }
    bool check(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        return s->val == t->val && check(s->left, t->left) && check(s->right, t->right);
    }
};


下面是自己写的算法代码

bool doTraversal(TreeNode *s, TreeNode *t) {
    if (t != nullptr && s != nullptr) {
        if (s->val != t->val)return false;
        bool a = true, b = true;
        if (s->left != nullptr && t->left != nullptr)
            a = doTraversal(s->left, t->left);
        else if(s->left!= nullptr) {
            a = false;
        }else if(t->left!= nullptr){
            a = false;
        }
        if (s->right != nullptr && t->right != nullptr)
            b = doTraversal(s->right, t->right);
        else if(s->right!= nullptr){
            b = false;
        }else if(t->right!= nullptr){
            b = false;
        }
        return a && b;
    }
    return false;
}
bool isSubtree2(TreeNode *s, TreeNode *t,bool &res){
    if(res)return true;
    if (s != nullptr) {
        if (s->val == t->val) {
            bool a = doTraversal(s, t);
            if (a){
                res = a;
            }
        }
        isSubtree2(s->left, t,res);
        isSubtree2(s->right, t,res);
    }
    return res;
}
bool isSubtree(TreeNode *s, TreeNode *t) {
    bool res = false;
    return isSubtree2(s,t,res);
}


