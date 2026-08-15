#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (root == NULL) return res;

        q.push(root);
        while (!q.empty()) {
            int qusize = q.size();
            vector<int> temp;
            while (qusize > 0) {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if (t->left != NULL) q.push(t->left);
                if (t->right != NULL) q.push(t->right);
                qusize--;
            }
            res.push_back(temp);
        }
        return res;
    }

    // 103. Binary Tree Zigzag Level Order Traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int check = 1;
        vector<vector<int>> res;
        if (root == NULL) return res;
        q.push(root);
        
        while (!q.empty()) {
            int qsize = q.size();
            vector<int> temp(qsize, 0);
            int front = 0;
            int last = qsize - 1;
            while (qsize > 0) {
                TreeNode* t = q.front();
                q.pop();
                if (check == 1) {
                    temp[front] = t->val;
                    front++;
                }
                else {
                    temp[last] = t->val;
                    last--;
                }
                if (t->left != NULL) q.push(t->left);
                if (t->right != NULL) q.push(t->right);
                qsize--;
            }
            if (check == 1) check = 0;
            else if (check == 0) check = 1;
            res.push_back(temp);
        }
        return res;
    }

    // 107. Binary Tree Level Order Traversal II
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> res;
        if (root == NULL) return res;
        qu.push(root);
        while (!qu.empty()) {
            int qsize = qu.size();
            vector<int> temp;
            while (qsize > 0) {
                TreeNode* t = qu.front();
                qu.pop();
                temp.push_back(t->val);
                if (t->left != NULL) qu.push(t->left);
                if (t->right != NULL) qu.push(t->right);
                qsize--;
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};