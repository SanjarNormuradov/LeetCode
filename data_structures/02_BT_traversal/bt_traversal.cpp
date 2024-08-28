#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : left(nullptr), right(nullptr) {
        setVal(x);
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : left(left), right(right) {
        setVal(x);
    }
private:
    void setVal(int v) {
        if (v < -1000 || v > 1000) throw std::runtime_error("Constraints for 'value' violated");
        val = v;
    }
};


class Solution {
public:
    // Function to insert nodes level-wise from an array in level-order format
    TreeNode* insertLevelOrder(const vector<int>& arr) {
        if (arr.empty() || arr[0] == -1000) return nullptr;  // Handle empty or root = nullptr case
        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < arr.size()) {
            TreeNode* current = q.front();
            q.pop();
            // Insert the left/right child if it is not -1000
            if (i < arr.size() && arr[i] != -1000) {
                current->left = new TreeNode(arr[i]);
                q.push(current->left);
            }
            i++;  // Move to the next element in the array
            if (i < arr.size() && arr[i] != -1000) {
                current->right = new TreeNode(arr[i]);
                q.push(current->right);
            }
            i++;  // Move to the next element in the array
        }
        return root;
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        recursion(root, result, "preorder");
        return result;
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        recursion(root, result, "inorder");
        return result;
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        recursion(root, result, "postorder");
        return result;
    }
    vector<vector<int>> levelorderTraversal(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
private:
    void recursion(TreeNode *node, vector<int>& result, string type) {
        if (!node) return;
        if (type == "preorder") {
            result.push_back(node->val);
            recursion(node->left, result, type);
            recursion(node->right, result, type);
        } else if (type == "inorder") {
            recursion(node->left, result, type);
            result.push_back(node->val);
            recursion(node->right, result, type);
        } else if (type == "postorder") {
            recursion(node->left, result, type);
            recursion(node->right, result, type);
            result.push_back(node->val);
        }
    }
};