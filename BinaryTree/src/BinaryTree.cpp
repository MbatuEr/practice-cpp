#include "../header/BinaryTree.h"

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}

TreeNode* BinaryTree::findLCA(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(!root || root == p || root == q) return root;
    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);
    if(left && right) return root;
    return left ? left : right;
}

bool BinaryTree::isMirror(TreeNode* left, TreeNode* right) 
{
    if(!left && !right) return true;
    if(!left || !right || left->val != right->val) return false;
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool BinaryTree::isSymmetric(TreeNode* root) 
{
    if(!root) return true;
    return isMirror(root->left, root->right);
}

int BinaryTree::sumRootToLeaf(TreeNode* root)
{
    return dfs(root,0);
}

int BinaryTree::dfs(TreeNode* node, int currentsum)
{
    if (!node) return 0; 

    currentsum = (currentsum << 1) | node->val;

    if (!node->left && !node->right) 
    {
        return currentsum;
    }

    return dfs(node->left, currentsum) + dfs(node->right, currentsum);
}