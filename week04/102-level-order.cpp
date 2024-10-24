// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    // Iterative solution
    // Intuition: we can find the nodes at the next level by iterating through
    // the current level and pushing left and right of each node, if they exist
    // Note: this is basically "breadth-first search" (covered later in the
    // course)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> toExplore;
        if (root)
            toExplore.push_back(root);

        vector<TreeNode*> newToExplore;
        vector<int> level;

        while (toExplore.size()) {
            for (TreeNode* node : toExplore) {
                level.push_back(node->val);

                if (node->left)
                    newToExplore.push_back(node->left);

                if (node->right)
                    newToExplore.push_back(node->right);
            }

            result.push_back(level);
            level.clear();

            toExplore = newToExplore;
            newToExplore.clear();
        }

        return result;
    }

    // Recursive solution
    // Intuition: we keep track of levels in recursion by adding 1 to the level
    // every time we recurse. Then, use the level to insert directly into the
    // result. Use a preorder traversal (root left right) to insert nodes into
    // each level from left to right. This does not traverse one level after
    // another.
private:
    void levelOrderHelper(TreeNode* root, vector<vector<int>>& result, int level) {
        if (!root) return;

        // Ensure result[level] exists
        if (level >= result.size()) {
            result.push_back({});
        }

        result[level].push_back(root->val);

        // Increment level
        levelOrderHelper(root->left, result, level + 1);
        levelOrderHelper(root->right, result, level + 1);
    }
public:
    vector<vector<int>> levelOrderRecursive(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderHelper(root, result, 0);
        return result;
    }
};