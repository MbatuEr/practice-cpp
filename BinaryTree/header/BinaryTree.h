#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x);
};

class BinaryTree 
{
    private:
        // check if the tree's both sides mirroring each other.
        bool isMirror(TreeNode* left, TreeNode* right);

        // apply depth-first search.
        int dfs(TreeNode* node, int currentsum);

    public:
        // check if the tree is symmetric.
        bool isSymmetric(TreeNode* root);

        // find the lowest common ancestor.
        TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q);

        // find the binary numbers that represented by the tree.
        int sumRootToLeaf(TreeNode* root);

        // checks if there exists a leaf whose path weight equals the given integer.
        bool hasPathWeight(TreeNode* node, int targetWeight, int currentWeight);

        // does an inorder traversal without a recursion or parent references.
        std::vector<int> inorderTraversal(TreeNode* root, int k);

        // does an preorder traversal without a recursion or parent references.
        std::vector<int> preorderTraversal(TreeNode* root);

        // computes the successor of the node in an inorder traversal.
        void computeTheSuccessor(TreeNode* root, TreeNode* wanted);

        // does an inorder traversal with a O(1) space complexity.
        void inorderTraversalWithO1Space(TreeNode* root);        

        // Main function to build the binary tree.
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);

        // Helper function to build the binary tree.
        TreeNode* buildTreeHelper(std::vector<int>& preorder, int preStart, int preEnd,
                          std::vector<int>& inorder, int inStart, int inEnd,
                          std::unordered_map<int, int>& inMap);
};