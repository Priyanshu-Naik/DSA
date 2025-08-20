/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())
            return NULL;

        unordered_map<int, int> inMap; // faster than map
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1, inMap);
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    unordered_map<int, int>& inMap) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        // pick the root from the last element of postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        // index of root in inorder
        int inRoot = inMap[postorder[postEnd]];

        // number of nodes in left subtree
        int numsLeft = inRoot - inStart;

        // build left subtree
        root->left = build(inorder, inStart, inRoot - 1, postorder, postStart,
                           postStart + numsLeft - 1, inMap);

        // build right subtree
        root->right = build(inorder, inRoot + 1, inEnd, postorder,
                            postStart + numsLeft, postEnd - 1, inMap);

        return root;
    }
};