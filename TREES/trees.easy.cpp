#include<iostream>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// 101. Symmetric Tree
class Solution {
public:
    bool check_symm(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL) return false;
        if (root1->val != root2->val) return false;

        bool r1 = check_symm(root1->left, root2->right);
        bool r2 = check_symm(root1->right, root2->left);
        return r1 && r2;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return check_symm(root->left, root->right);
    }
};

// 572. Subtree of Another Tree
class Solution {
public:
    bool is_identical(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;
        if (root->val != subRoot->val) return false;

        bool r1 = is_identical(root->left, subRoot->left);
        bool r2 = is_identical(root->right, subRoot->right);
        return r1 && r2;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;   // ran out of tree, no match found
        if (is_identical(root, subRoot)) return true;
        
        bool foundInLeft = isSubtree(root->left, subRoot);
        bool foundInRight = isSubtree(root->right, subRoot);

        if (foundInLeft || foundInRight) return true;
        else return false;
    }
};

// 700. Search in a Binary Search Tree
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if (root->val == val) return root;
        TreeNode* val_node = NULL;

        if (root->val < val) {
            val_node = searchBST(root->right, val);
        }
        else {
            val_node = searchBST(root->left, val);
        }
        
        return val_node;
    }
};

// 112. Path Sum
class Solution {
public:
    void adding_nodes(TreeNode* root, int sum, int targetSum, bool& res) {
        if (root == NULL) return;
        sum+= root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) res = true;
        }
        adding_nodes(root->left, sum, targetSum, res);
        adding_nodes(root->right, sum, targetSum, res);
        return;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        int sum = 0;
        adding_nodes(root, sum, targetSum, res);
        return res;
    }
};
// 100 same tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p ->val != q->val) return false;
        
        bool r1 = isSameTree(p->left, q->left);
        bool r2 = isSameTree(p->right, q->right);

        if (r1 == true && r2 == true) return true;
        else return false;
    }
};

// 104. Maximum Depth of Binary Tree
class Solution {
public:
    int max_depth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = max_depth(root->left);
        int right = max_depth(root->right);

        return 1 + max(left,right);
    }
    int maxDepth(TreeNode* root) {
        int maxHeight = max_depth(root);
        return maxHeight;
    }
};

// 110. Balanced Binary Tree
class Solution {
public:
    int checkValid(TreeNode* root, bool& check) {
        if (root == NULL) return 0;
        int left = checkValid(root->left, check);
        int right = checkValid(root->right, check);

        if (abs(left - right) > 1) check = false;
        return 1 + max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool check = true;
        checkValid(root, check);
        return check;
    }
};