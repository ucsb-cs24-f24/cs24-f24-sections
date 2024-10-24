// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    // Intuition: A unique structure is found by comparing the preorder and
    // inorder traversals as below. The key is that the root is always first in
    // the preorder traversal, and the root divides the left and right sides of
    // the inorder traversal.

    // Example:
    // pre  3 9 20 15 7
    // in   9 3 15 20 7
    // Root is 3
    // Left inorder: 9
    // Right inorder: 15 20 7
    // Left pre: 9
    // Right pre: 20 15 7

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // We know the first entry in a preorder traversal is the root
        int rootNum = preorder[0];

        // We find the root in the inorder traversal
        // We know that all entries before the root are left of the root,
        // and all entries after the root are right of the root due to
        // the properties of inorder traversal
        int rootIdxIO = 0;
        while (inorder[rootIdxIO] != rootNum) {
            rootIdxIO++;
        }

        // Divide the inorder array into left and right (skip root)
        vector<int> inorderLeft(
            inorder.begin(),
            inorder.begin() + rootIdxIO
        );

        vector<int> inorderRight(
            inorder.begin() + rootIdxIO + 1,
            inorder.end()
        );

        // Create the root
        TreeNode* node = new TreeNode{rootNum, nullptr, nullptr};

        // Recurse if the left/right subtrees are empty
        // Implicit base case: just return the above node
        // when both subtrees are empty
        if (inorderLeft.size()) {
            // Find the part of preorder that corresponds to the left subtree
            // based on the lenfth of the inorder array
            vector<int> preorderLeft(
                preorder.begin() + 1,
                preorder.begin() + inorderLeft.size() + 1
            );

            node->left = buildTree(preorderLeft, inorderLeft);
        }

        if (inorderRight.size()) {
            // Find the part of preorder that corresponds to the right subtree
            // based on the lenfth of the inorder
            // array
            vector<int> preorderRight(
                preorder.begin() + inorderLeft.size() + 1,
                preorder.end()
            );

            node->right = buildTree(preorderRight, inorderRight);
        }

        return node;
    }
};