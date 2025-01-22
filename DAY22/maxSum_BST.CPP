// 1373. Maximum Sum BST in Binary Tree
// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 int maxSum = 0; // To store the maximum sum of any BST subtree

    // Helper function to traverse the tree and compute results
    tuple<bool, int, int, int> traverse(TreeNode* node) {
        // Base case: empty node
        if (!node) {
            return {true, 0, INT_MAX, INT_MIN}; // (is_bst, sum, min_val, max_val)
        }

        // Recursively process left and right subtrees
        auto [left_is_bst, left_sum, left_min, left_max] = traverse(node->left);
        auto [right_is_bst, right_sum, right_min, right_max] = traverse(node->right);

        // Check if the current subtree is a BST
        if (left_is_bst && right_is_bst && left_max < node->val && node->val < right_min) {
            // Current subtree is a BST
            int subtree_sum = node->val + left_sum + right_sum;
            maxSum = max(maxSum, subtree_sum); // Update the global maximum sum
            return {true, subtree_sum, min(node->val, left_min), max(node->val, right_max)};
        }

        // Current subtree is not a BST
        return {false, 0, 0, 0};
    }
public:
    int maxSumBST(TreeNode* root) {
     traverse(root);
        return maxSum;  
    }
};