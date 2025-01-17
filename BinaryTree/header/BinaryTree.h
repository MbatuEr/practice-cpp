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
        // Check if the tree's both sides mirroring each other.
        bool isMirror(TreeNode* left, TreeNode* right);

        // Apply depth-first search.
        int dfs(TreeNode* node, int currentsum);

        // Helper function for insertion.
        bool insertHelper(TreeNode* node, int key);

        // Helper function for removal.
        TreeNode* removeHelper(TreeNode* node, int key, bool& removed);
        
        // Helper function for lookup.
        bool lookupHelper(TreeNode* node, int key);
        
        // Finds the minimum value node in a subtree.
        TreeNode* findMin(TreeNode* node);

    public:
        // Root node of the BST.
        TreeNode* root;

        // Constructor.
        BinaryTree();

        // Inserts a key into the BST.
        bool insert(int key);

        // Removes a key from the BST.
        bool remove(int key);

        // Looks up for the specified node in the BST.
        bool lookup(int key);

        // Checks if the tree is symmetric.
        bool isSymmetric(TreeNode* root);

        // Finds the lowest common ancestor.
        TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q);

        // Finds the binary numbers that represented by the tree.
        int sumRootToLeaf(TreeNode* root);

        // Checks if there exists a leaf whose path weight equals the given integer.
        bool hasPathWeight(TreeNode* node, int targetWeight, int currentWeight);

        // Builds a tree from an inorder traversal without a recursion or parent references.
        std::vector<int> inorderTraversal(TreeNode* root, int k);

        // Builds a tree from a preorder traversal without a recursion or parent references.
        std::vector<int> preorderTraversal(TreeNode* root);

        // Computes the successor of the node in an inorder traversal.
        void computeTheSuccessor(TreeNode* root, TreeNode* wanted);

        // Does an inorder traversal with a O(1) space complexity.
        void inorderTraversalWithO1Space(TreeNode* root);        

        // Main function to build the binary tree.
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);

        // Helper function to build the binary tree.
        TreeNode* buildTreeHelper(std::vector<int>& preorder, int preStart, int preEnd,
                          std::vector<int>& inorder, int inStart, int inEnd,
                          std::unordered_map<int, int>& inMap);
        
        // Builds a tree from a preorder traversal and uses null to mark empty children.
        void reconstructPreOrder(TreeNode* root);

        // Creates a linked list from leaves of the tree.
        ListNode* createsListFromLeaves(TreeNode* root);

        // Helper function to traverse the tree and collect leaves.
        void collectLeaves(TreeNode* root, ListNode*& current); 

        // Prints the linked list.
        void printLinkedList(ListNode* head);

        // Computes the exterior of a binary tree.
        void exteriorOfBinaryTree(TreeNode* root);

        // Sets the node to its level next right node.
        void rightSiblingTree(TreeNode* root);

        // Helper funtion to set the nodes to next level field.
        void setLevelNextField(TreeNode* left_tree, TreeNode* right_tree);

        // Prints the nodes in order of their level.
        void printLevelNext(TreeNode* root);

        // Checks if any ancestors or descendants are locked.
        bool canLockOrUnlock(TreeNode* node);

        // Function to lock the node.
        bool lock(TreeNode* node);

        // Function to unlock the node.
        bool unlock(TreeNode* node);

        // Checks if a binary tree satisfies the BST property.
        bool isBSTHelper(TreeNode* node, int min_value, int max_value, TreeNode* input_key, int first_key_appeared);

        // Wrapper function for isBSTHelper().
        bool isBST(TreeNode* node, TreeNode* input_key);

        // Finds the k larger elements in a BST.
        void largestElementsInBST(TreeNode* root, int k);

        // Recursive function to get inorder traversal.
        std::vector<int> recursiveInorderTraversal(TreeNode* root, std::vector<int>& result);

        // Prints a binary tree in level-order.
        void levelOrderTraversal(TreeNode* root);
};