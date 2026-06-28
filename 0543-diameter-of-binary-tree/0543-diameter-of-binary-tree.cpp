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
    int dia = 0;

    int calcHeight(TreeNode* root){
        if(root==nullptr) return 0;

        int lh = calcHeight(root->left);
        int rh = calcHeight(root->right);
        dia = max(dia,lh + rh);
        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        calcHeight(root);
        return dia;
    }
};