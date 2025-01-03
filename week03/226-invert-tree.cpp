// https://leetcode.com/problems/invert-binary-tree/

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
public:
    // Intuition: visit every node and switch left and right

    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Can use any traversal (preorder, in order, postorder)
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};