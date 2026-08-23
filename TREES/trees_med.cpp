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

// 236. Lowest Common Ancestor of a Binary Tree
class Solution {
public:
    int check(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == NULL) return 0;

        int left = check(root->left, p, q, ans);
        int right = check(root->right, p, q, ans);
        int self = 0;
        if (root == p || root == q) self = 1;

        int total = self + left + right;
        if (total == 2 && ans == NULL) ans = root;

        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        check(root, p, q, ans);
        return ans;
    }
};


// 236. Lowest Common Ancestor of a Binary Tree.
class Solution {
public:
    int check(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == NULL) return 0;
        int left = check(root->left, p, q, ans);
        int right = check(root->right, p, q, ans);

        int self = 0;
        if (root == p || root == q) {
            self = 1;
        }
        int total = self + left + right;
        if (total == 2 && ans == NULL) {
            ans = root;
        }
        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        check(root, p, q, ans);
        return ans;
    }
};


// 653. Two Sum IV - Input is a BST
class Solution {
public:
    TreeNode* getSmall(stack<TreeNode*>& asc) {
        if (asc.empty()) return NULL;
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightchild = small->right;
        while (rightchild != NULL) {
            asc.push(rightchild);
            rightchild = rightchild->left;
        }
        return small;
    }
    TreeNode* getBig(stack<TreeNode*>& desc) {
        if (desc.empty()) return NULL;
        TreeNode* big = desc.top();
        desc.pop();
        TreeNode* leftchild = big->left;
        while (leftchild != NULL) {
            desc.push(leftchild);
            leftchild = leftchild->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> asc;
        stack<TreeNode*> desc;

        if (root == NULL) return false;
        TreeNode* t = root;
        while(t != NULL) {
            asc.push(t);
            t = t->left;
        }
        t = root;
        while (t != NULL) {
            desc.push(t);
            t = t->right;
        }

        TreeNode* i = getSmall(asc);
        TreeNode* j = getBig(desc);
        while (i != NULL && j != NULL && i != j && i->val <= j->val) {
            int sum = i->val + j->val;
            if (sum == k) return true;
            if (sum < k) i = getSmall(asc);
            else if (sum > k) j = getBig(desc);
        }
        return false;
    }
};

// 230. Kth Smallest Element in a BST
class Solution {
public:
    TreeNode* ans_node(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int cnt = 0;
        TreeNode* curr_node = root;

        while (curr_node != NULL) {
            st.push(curr_node);
            curr_node = curr_node->left;
        }
        while (!st.empty()) {
            TreeNode* small = st.top();
            st.pop();
            cnt++;
            if (cnt == k) return small;
            TreeNode* rightchild = small->right;
            while (rightchild != NULL) {
                st.push(rightchild);
                rightchild = rightchild->left;
            }
        }
        return NULL;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* kth_node = ans_node(root, k);
        int ans = kth_node->val;
        return ans;
    }
};

// 
class Solution {
public:
    void leafSum(TreeNode* root, int sum, vector<int>& temp) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            sum = (sum*10)+root->val;
            temp.push_back(sum);
            sum = root->val;
            return;
        }

        sum = sum*10+root->val;
        leafSum(root->left, sum, temp);
        leafSum(root->right, sum, temp);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> temp;
        int sum = 0;
        leafSum(root, sum, temp);

        int ans_sum = 0;
        int n = temp.size();
        for (int i=0; i<n; i++) {
            ans_sum+= temp[i];
        }
        return ans_sum;
    }
};