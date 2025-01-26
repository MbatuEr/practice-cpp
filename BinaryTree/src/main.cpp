#include "../header/BinaryTree.h"

int main()
{
    BinaryTree tree;

    // Insertion, lookup and removal.
    std::vector<int> items_to_insert = {10,5,15,3,7,12,10};
    for (int values: items_to_insert)
    {
        tree.insert(values);
    }

    std::vector<int> inorder_result1;
    std::vector<int> inorder_result2;

    std::cout << "Inorder Traversal after Insertions: ";
    inorder_result1 = tree.recursiveInorderTraversal(tree.root, inorder_result1);
    for (int val : inorder_result1)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Lookup for node 7: " << (tree.lookup(7) ? "true" : "false") << "\n"; 
    std::cout << "Lookup for node 12: " << (tree.lookup(14) ? "true" : "false") << "\n"; 

    std::cout << "Removing 15: " << (tree.remove(15) ? "Success" : "Failed") << std::endl;
    std::cout << "Removing 10: " << (tree.remove(10) ? "Success" : "Failed") << std::endl;

    inorder_result2 = tree.recursiveInorderTraversal(tree.root, inorder_result2);
    
    std::cout << "Inorder Traversal after Removals: ";
    for (int val : inorder_result2)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    //Check if the tree is symmetrical.
    TreeNode* root_symmetrical = new TreeNode(1);
    root_symmetrical->left = new TreeNode(2);
    root_symmetrical->right = new TreeNode(2);
    root_symmetrical->left->left = new TreeNode(3);
    root_symmetrical->left->right = new TreeNode(4);
    root_symmetrical->right->left = new TreeNode(4);
    root_symmetrical->right->right = new TreeNode(3);
    
    if(tree.isSymmetric(root_symmetrical)) 
    {
        std::cout << "The tree is symmetric." << std::endl;
    } 
    else 
    {
        std::cout << "The tree is not symmetric." << std::endl;
    }
    std::cout << "----------------------------------------------------------" << std::endl;

    // Find the lowest common ancestor.
    BinaryTree LCA;
    std::vector<int> LCA_order = {8,4,12,2,6,10,14,3,9,11,13,16};

    for (int values : LCA_order)
    {
        LCA.insert(values);
    }   
    int p = 3;
    int q = 6;
    
    TreeNode* lca = tree.findLCA(LCA.root, p, q);
    
    if(lca) 
    {
        std::cout << "The lowest common ancestor of " << p << " and " << q << " is " << lca->val << std::endl;
    } 
    else 
    {
        std::cout << "The lowest common ancestor of " << p << " and " << q << " is not found." << std::endl;
    }
    std::cout << "----------------------------------------------------------" << std::endl;

    // Sum of binary numbers.
    TreeNode* rootsum = new TreeNode(1);
    rootsum->left = new TreeNode(0);
    rootsum->right = new TreeNode(1);
    rootsum->left->left = new TreeNode(0);
    rootsum->left->right = new TreeNode(1);
    rootsum->right->left = new TreeNode(0);
    rootsum->right->right = new TreeNode(0);
    rootsum->left->left->left = new TreeNode(0);
    rootsum->left->left->right = new TreeNode(1);
    rootsum->left->right->right = new TreeNode(1);
    rootsum->right->left->right = new TreeNode(0);
    rootsum->right->right->right = new TreeNode(0);
    rootsum->left->right->right->left = new TreeNode(0);
    rootsum->right->left->right->right = new TreeNode(0);
    rootsum->right->left->right->left = new TreeNode(1);
    rootsum->right->left->right->left->right = new TreeNode(1);

    std::cout << "Sum of binary numbers represented by root-to-leaf paths: "
              << tree.sumRootToLeaf(rootsum) << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    
    // Sum of the weight of from root to a specified node.
    BinaryTree path_weight;
    std::vector<int> path_weight_order = {5,3,8,2,4,7,11,1,13};

    for (int values : path_weight_order)
    {
        path_weight.insert(values);
    }
    
    int num = 20;
    int currentsum = 0;

    if (tree.hasPathWeight(path_weight.root, num, currentsum)) 
    {
        std::cout << "There exists a leaf whose path weight equals " << num << ".\n";
    } 
    else 
    {
        std::cout << "No leaf path weight equals " << num << ".\n";
    }
    std::cout << "----------------------------------------------------------" << std::endl;

    // Inorder traversal without recursion.
    BinaryTree tree_order;
   
    std::vector<int> order_of_tree = {8,6,10,4,7,9,13,5,12,14};
    for (int values : order_of_tree)
    {
        tree_order.insert(values);
    }
    
    /*
         Constructed binary tree:
               8
             /   \
            /     \
           6      10
          / \    /   \  
         4   7  9     13
          \          /  \
           5       12    14    
    */
    int k = 7;
    std::vector<int> inorder_traversal = tree_order.inorderTraversal(tree_order.root, k);
    std::cout << "The inorder traversal of the binary tree: ";
    for (int val : inorder_traversal)
    {
        std::cout << val << " ";
    }
    std::cout << "\n----------------------------------------------------------" << std::endl;
    
    // Preorder traversal without recursion.

    std::vector<int> preorder_traversal = tree.preorderTraversal(tree_order.root);
    std::cout << "The preorder traversal of the binary tree: ";
    for (int val : preorder_traversal)
    {
        std::cout << val << " ";
    }
    std::cout << "\n----------------------------------------------------------" << std::endl;

    // Compute the successor.
    TreeNode* node = tree_order.findValue(12);
    if (node) 
    {
        std::cout << "Node found: " << node->val << std::endl;
        TreeNode* successor = tree_order.computeTheSuccessor(node);
        
        if (successor) 
        {
            std::cout << "Successor of " << node->val << " is: " << successor->val << std::endl;
        } 
        else {
            std::cout << "No successor for " << node->val << std::endl;
        }
    } 
    else {
        std::cout << "Node not found in the tree." << std::endl;
    }
    std::cout << "----------------------------------------------------------" << std::endl;

    // Inorder Traversal with O(1) space.
    std::cout << "The inorder traversal of the binary tree: ";
    tree.inorderTraversalWithO1Space(tree_order.root);
    std::cout << "\n----------------------------------------------------------" << std::endl;

    // Build a binary tree.
    std::vector<int> inorder = {4, 6, 5, 7, 8, 9, 10, 12, 13, 14};
    std::vector<int> preorder = {8, 5, 4, 6, 7, 10, 9, 13, 12, 14};
    

    TreeNode* root_order = tree.buildTree(preorder, inorder);

    std::cout << "Inorder traversal of the reconstructed tree: " << std::endl;
    std::vector<int> inorder_traversal_tree = tree.inorderTraversal(root_order, k);
    for (int val : inorder_traversal_tree)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Preorder traversal of the reconstructed tree: " << std::endl;
    std::vector<int> preorder_traversal_tree = tree.preorderTraversal(root_order);
    for (int val : preorder_traversal_tree)
    {
        std::cout << val << " ";
    }
    std::cout << "\n----------------------------------------------------------" << std::endl;

    // Reconstruct preorder traversal.
    tree_order.reconstructPreOrder(tree_order.root);
    std::cout << "\n----------------------------------------------------------" << std::endl;
    
    // Create list from leaves.    
    ListNode* leafList = tree_order.createsListFromLeaves(tree_order.root);

    std::cout << "Linked list of leaves: ";
    tree.printLinkedList(leafList);
    std::cout << "\n----------------------------------------------------------" << std::endl;

    // Compute exterior.
    BinaryTree exterior;
    std::vector<int> root_exterior = {8,4,13,2,5,11,16,1,3,7,12,14,18,6};

    for (int values : root_exterior)
    {
        exterior.insert(values);
    }

    tree.exteriorOfBinaryTree(exterior.root);
    std::cout << "\n----------------------------------------------------------" << std::endl;

    // Right sibling tree.
    BinaryTree sibling;
    std::vector<int> right_sibling = {8,4,13,2,6,10,16,1,3,5,7,9,11,14,18};
    for (int values : right_sibling)
    {
        sibling.insert(values);
    }
    
    sibling.rightSiblingTree(sibling.root);

    sibling.printLevelNext(sibling.root);
    std::cout << "----------------------------------------------------------" << std::endl;

    // Lock the node.
    BinaryTree locked;
    std::vector<int> root_lock = {4,2,6,1,3,5,7};
    for(int values : root_lock)
    {
        locked.insert(values);
    }
    TreeNode* lock_node1 = locked.findValue(1);
    TreeNode* lock_node3 = locked.findValue(3);
    TreeNode* lock_node2 = locked.findValue(2);

    std::cout << "Locking node 1: " << (locked.lock(lock_node1) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 3: " << (locked.lock(lock_node3) ? "Success" : "Failed") << std::endl;    
    std::cout << "Locking node 2 (parent of 1 and 3): " << (locked.lock(lock_node2) ? "Success" : "Failed") << std::endl;
    std::cout << "Unlocking node 3: " << (locked.unlock(lock_node3) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 2 after unlocking node 3: " << (locked.lock(lock_node2) ? "Success" : "Failed") << std::endl;
    std::cout << "Unlocking node 1: " << (locked.unlock(lock_node1) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 2 after unlocking node 1: " << (locked.lock(lock_node2) ? "Success" : "Failed") << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    
    // Check BST is proper and find first value greater than input_key.
    BinaryTree if_BST;
    std::vector<int> root_BST = {8,4,12,2,6,10,14};
    for (int values : root_BST)
    {
        if_BST.insert(values);
    }
    
    TreeNode* input_key = new TreeNode(13);

    if (tree.isBST(if_BST.root, input_key)) {
        std::cout << "The tree satisfies the BST property." << std::endl;
        std::cout << "First key greater than input value: " << input_key->val << std::endl;
    } else {
        std::cout << "The tree does NOT satisfy the BST property." << std::endl;
        std::cout << "First key greater than input value: " << input_key->val << std::endl;
    }
    std::cout << "----------------------------------------------------------" << std::endl;

    // Largest elements.
    int input_value = 3;
    tree.largestElementsInBST(tree_order.root, input_value);
    std::cout << "----------------------------------------------------------" << std::endl;
    
    // Level order tree traversal.
    tree.levelOrderTraversal(tree_order.root);
    std::cout << "----------------------------------------------------------" << std::endl;
    
    return 0;
}