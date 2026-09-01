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


// 235. Lowest Common Ancestor of a Binary Search Tree
class Solution {
public:
    void checkLCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == NULL) return;
        if (root == p || root == q) {
            ans = root;
            return;
        }
        if (root->val < p->val) {
            checkLCA(root->right, p, q, ans);
        }
        else if (root->val > q->val) {
            checkLCA(root->left, p, q, ans);
        }
        else {
            ans = root;
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        if (p->val < q->val) checkLCA(root, p, q, ans);
        else checkLCA(root, q, p, ans);
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

// 129. Sum Root to Leaf Numbers
class Solution {
public:
    void findNum(TreeNode* root, vector<int>& temp, int sum) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            sum = (sum*10)+root->val;
            temp.push_back(sum);
            sum = 0;
        }
        
        sum = (sum*10)+root->val;
        findNum(root->left, temp, sum);
        findNum(root->right, temp, sum);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int ans_sum = 0;
        vector<int> temp;
        findNum(root, temp, sum);

        int n = temp.size();
        for (int i=0; i<n; i++) {
            ans_sum+= temp[i];
        }
        return ans_sum;
    }
};

// 958. Check Completeness of a Binary Tree
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        bool nullFound = false;

        while(!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            if (node == NULL) nullFound = true;
            else {
                if (node != NULL && nullFound == true) return false;
                qu.push(node->left);
                qu.push(node->right);
            }
        }
        return true;
    }
};

// 113. Path Sum II
class Solution {
public:
    void findSum(TreeNode*& root, int& targetSum, int sum, vector<int> ans, vector<vector<int>>& final_ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            sum+= root->val;
            if (sum == targetSum) {
                ans.push_back(root->val);
                final_ans.push_back(ans);
            }
            return;
        }

        sum+= root->val;
        ans.push_back(root->val);

        findSum(root->left, targetSum, sum, ans, final_ans);
        findSum(root->right, targetSum, sum, ans, final_ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        int sum = 0;
        vector<vector<int>> final_ans;

        findSum(root, targetSum, sum, ans, final_ans);
        return final_ans;

    }
};

// 98. Validate Binary Search Tree
class Solution {
public:
    void check(TreeNode*& root, TreeNode*& prev, bool& ans) {
        if (root == NULL) return;
        check(root->left, prev, ans);
        if (prev == NULL) {
            prev = root;
        }
        else if (root->val <= prev->val) {
            ans = false;
        }
        prev = root;
        check(root->right, prev, ans);
        return;
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool ans = true;
        check(root, prev, ans);
        return ans;
    }
};

// 99. Recover Binary Search Tree
class Solution {
public:
    void checkBST(TreeNode* root, TreeNode*& first_wr_1st, TreeNode*& first_wr_2nd, TreeNode*& second_wr_1st,
                TreeNode*& second_wr_2nd, TreeNode*& prev, int& wrg_cnt) {

        if (root == NULL) return;
        checkBST(root->left, first_wr_1st, first_wr_2nd, second_wr_1st, second_wr_2nd, prev, wrg_cnt);
        if (prev == NULL) prev = root;
        else {
            if (root->val <= prev->val && wrg_cnt == 0) {
                wrg_cnt++;
                first_wr_1st = prev;
                first_wr_2nd = root;
            }
            else if (root->val <= prev->val && wrg_cnt == 1) {
                wrg_cnt++;
                second_wr_1st = prev;
                second_wr_2nd = root;
            }
            prev = root;
        }
        checkBST(root->right, first_wr_1st, first_wr_2nd, second_wr_1st, second_wr_2nd, prev, wrg_cnt);
        return;
    }

    void recoverTree(TreeNode* root) {
        int wrg_cnt = 0;
        TreeNode* prev = NULL;

        TreeNode* first_wr_1st = NULL;
        TreeNode* first_wr_2nd = NULL;

        TreeNode* second_wr_1st = NULL;
        TreeNode* second_wr_2nd = NULL;

        checkBST(root, first_wr_1st, first_wr_2nd, second_wr_1st, second_wr_2nd, prev, wrg_cnt);
        if (wrg_cnt == 1) {
            swap(first_wr_1st->val, first_wr_2nd->val);
        }
        else swap(first_wr_1st->val, second_wr_2nd->val);
        return;
    }
};


// 105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
public:
    TreeNode* makeTree(vector<int>& preorder, int low, int high, map<int,int>& in_index, int& indx) {
        if (low > high) return NULL;
        TreeNode* node = new TreeNode(preorder[indx]);
        indx++;
        int id = in_index[node->val];
        node->left = makeTree(preorder, low, id-1, in_index, indx);
        node->right = makeTree(preorder, id+1, high, in_index, indx);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> in_indx;
        int n = inorder.size();
        for (int i=0; i<n; i++) {
            in_indx[inorder[i]] = i;
        }
        int low = 0;
        int high = n-1;
        int indx = 0;
        return makeTree(preorder, low, high, in_indx, indx);
    }
};

// 106. Construct Binary Tree from Inorder and Postorder Traversal
class Solution {
public:
    TreeNode* makeTree(vector<int>& postorder, map<int,int>& in_mpp, int& idx, int low, int high) {
        if (low > high) return NULL;
        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;
        int id = in_mpp[node->val];

        node->right = makeTree(postorder, in_mpp, idx, id+1, high);
        node->left = makeTree(postorder, in_mpp, idx, low, id-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> in_mpp;
        for (int i=0; i<inorder.size(); i++) {
            in_mpp[inorder[i]] = i;
        }
        int idx = postorder.size()-1;
        int low = 0;
        int high = inorder.size()-1;

        return makeTree(postorder, in_mpp, idx, low, high);
    }
};