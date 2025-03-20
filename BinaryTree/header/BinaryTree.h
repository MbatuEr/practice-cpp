#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x);
};
struct TreeNode 
{
    int val;
    bool locked;
    int locked_descendant_count;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode* level_next_right;
    TreeNode(int x);
};

class BinaryTree 
{
    private:
        bool isMirror(TreeNode* left, TreeNode* right);

        // Apply depth-first search.
        int dfs(TreeNode* node, int currentsum);

        bool insertHelper(TreeNode* node, int key);

        TreeNode* removeHelper(TreeNode* node, int key, bool& removed);

        bool lookupHelper(TreeNode* node, int key);

        TreeNode* findMin(TreeNode* node);

        TreeNode* buildTreeHelper(std::vector<int>& preorder, int preStart, int preEnd,
                          std::vector<int>& inorder, int inStart, int inEnd,
                          std::unordered_map<int, int>& inMap);

        void collectLeaves(TreeNode* root, ListNode*& current);

        bool isBSTHelper(TreeNode* node, int min_value, int max_value, TreeNode* input_key, int first_key_appeared);

        void setLevelNextField(TreeNode* left_tree, TreeNode* right_tree);

    public:
        TreeNode* root;

        BinaryTree();

        bool insert(int key);

        bool remove(int key);

        bool lookup(int key);

        bool isSymmetric(TreeNode* root);

        // Finds the lowest common ancestor.
        TreeNode* findLCA(TreeNode* root, int p, int q);

        int sumRootToLeaf(TreeNode* root);

        // Checks if there exists a leaf whose path weight equals the given integer.
        bool hasPathWeight(TreeNode* node, int targetWeight, int currentWeight);
        
        // Builds a tree from an inorder traversal without a recursion or parent references.
        std::vector<int> inorderTraversal(TreeNode* root, int k);

        // Builds a tree from a preorder traversal without a recursion or parent references.
        std::vector<int> preorderTraversal(TreeNode* root);

        TreeNode* findValue(int value); 

        // Computes the successor of the node in an inorder traversal.
        TreeNode* computeTheSuccessor(TreeNode* wanted);

        void inorderTraversalWithO1Space(TreeNode* root);        

        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
        
        void reconstructPreOrder(TreeNode* root);

        ListNode* createsListFromLeaves(TreeNode* root); 

        void printLinkedList(ListNode* head);

        void exteriorOfBinaryTree(TreeNode* root);

        void rightSiblingTree(TreeNode* root);

        void printLevelNext(TreeNode* root);

        // Checks if any ancestors or descendants are locked.
        bool canLockOrUnlock(TreeNode* node);

        bool lock(TreeNode* node);

        bool unlock(TreeNode* node);

        bool isBST(TreeNode* node, TreeNode* input_key);

        std::vector<int> recursiveInorderTraversal(TreeNode* root, std::vector<int>& result);

        void largestElementsInBST(TreeNode* root, int k);

        void levelOrderTraversal(TreeNode* root);
};

#endif // BINARYTREE_H