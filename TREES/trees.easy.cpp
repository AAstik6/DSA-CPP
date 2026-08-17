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