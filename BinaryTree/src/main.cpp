#include "../header/BinaryTree.h"

int main()
{
    BinaryTree tree;

    // Insertion and removal.
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    
    std::vector<int> inorder_result1;
    std::vector<int> inorder_result2;

    std::cout << "Inorder Traversal after Insertions: ";
    inorder_result1 = tree.recursiveInorderTraversal(tree.root, inorder_result1);
    for (int val : inorder_result1)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Lookup for node 7: " << (tree.lookup(7) ? "true" : "false") << "\n"; // Output: 1
    std::cout << "Lookup for node 12: " << (tree.lookup(14) ? "true" : "false") << "\n"; // Output: 0

    std::cout << "Removing 15: " << (tree.remove(15) ? "Success" : "Failed") << std::endl;
    std::cout << "Removing 10: " << (tree.remove(10) ? "Success" : "Failed") << std::endl;


    std::cout << "Inorder Traversal after Removals: ";
    inorder_result2 = tree.recursiveInorderTraversal(tree.root, inorder_result2);
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
    TreeNode* rootLCA = new TreeNode(8);
    rootLCA->left = new TreeNode(4);
    rootLCA->right = new TreeNode(12);
    rootLCA->left->left = new TreeNode(2);
    rootLCA->left->right = new TreeNode(6);
    rootLCA->right->right = new TreeNode(14);
    rootLCA->right->left = new TreeNode(10);
    rootLCA->left->left->right = new TreeNode(3);
    rootLCA->right->left->left = new TreeNode(9);
    rootLCA->right->left->right = new TreeNode(11);
    rootLCA->right->right->right = new TreeNode(16);
    rootLCA->right->right->left = new TreeNode(13);

    TreeNode* p = rootLCA->left->left->right;
    TreeNode* q = rootLCA->left->right;
    TreeNode* lca = tree.findLCA(rootLCA, p, q);
    
    if(lca) 
    {
        std::cout << "The lowest common ancestor of " << p->val << " and " << q->val << " is " << lca->val << std::endl;
    } 
    else 
    {
        std::cout << "The lowest common ancestor of " << p->val << " and " << q->val << " is not found." << std::endl;
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
    TreeNode* rootsumweight = new TreeNode(5);
    rootsumweight->left = new TreeNode(3);
    rootsumweight->right = new TreeNode(8);
    rootsumweight->left->left = new TreeNode(2);
    rootsumweight->left->right = new TreeNode(4);
    rootsumweight->right->left = new TreeNode(7);
    rootsumweight->right->right = new TreeNode(11);
    rootsumweight->left->left->left = new TreeNode(1);
    rootsumweight->right->right->right = new TreeNode(13);

    int num = 20;
    int currentsum = 0;

    if (tree.hasPathWeight(rootsumweight, num, currentsum)) 
    {
        std::cout << "There exists a leaf whose path weight equals " << num << ".\n";
    } 
    else 
    {
        std::cout << "No leaf path weight equals " << num << ".\n";
    }
    std::cout << "----------------------------------------------------------" << std::endl;

    // Inorder traversal without recursion.
    BinaryTree tree_inorder;
    
    tree_inorder.insert(8);
    tree_inorder.insert(6);
    tree_inorder.insert(10);
    tree_inorder.insert(4);
    tree_inorder.insert(7);
    tree_inorder.insert(9);
    tree_inorder.insert(13);
    tree_inorder.insert(5);
    tree_inorder.insert(12);
    tree_inorder.insert(14);
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
    std::vector<int> inorder_traversal = tree_inorder.inorderTraversal(tree_inorder.root, k);
    std::cout << "The inorder traversal of the binary tree: ";
    for (int val : inorder_traversal)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    
    // Preorder traversal without recursion.

    BinaryTree tree_preorder;

    tree_preorder.insert(8);
    tree_preorder.insert(6);
    tree_preorder.insert(10);
    tree_preorder.insert(4);
    tree_preorder.insert(7);
    tree_preorder.insert(9);
    tree_preorder.insert(13);
    tree_preorder.insert(5);
    tree_preorder.insert(12);
    tree_preorder.insert(14);   

    std::vector<int> preorder_traversal = tree.preorderTraversal(tree_preorder.root);
    std::cout << "The preorder traversal of the binary tree: ";
    for (int val : preorder_traversal)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    // Compute the successor.
    TreeNode* root_successor = new TreeNode(8);
    root_successor->left = new TreeNode(5);
    root_successor->right = new TreeNode(10);
    root_successor->left->parent = root_successor;
    root_successor->right->parent = root_successor;
    root_successor->left->left = new TreeNode(4);
    root_successor->left->right = new TreeNode(7);
    root_successor->left->left->parent = root_successor->left;
    root_successor->left->right->parent = root_successor->left;
    root_successor->right->left = new TreeNode(9);
    root_successor->right->left->parent = root_successor->right;
    root_successor->left->left->right = new TreeNode(6);
    root_successor->left->left->right->parent = root_successor->left->left;
    
    tree.computeTheSuccessor(root_successor, root_successor->left->right);
    std::cout << "----------------------------------------------------------" << std::endl;

    // Inorder Traversal with O(1) space.
    TreeNode* root_inorder_space = new TreeNode(8);
    root_inorder_space->left = new TreeNode(6);
    root_inorder_space->right = new TreeNode(10);
    root_inorder_space->left->parent = root_inorder_space;
    root_inorder_space->right->parent = root_inorder_space;

    root_inorder_space->left->left = new TreeNode(4);
    root_inorder_space->left->right = new TreeNode(7);
    root_inorder_space->left->left->parent = root_inorder_space->left;
    root_inorder_space->left->right->parent = root_inorder_space->left;

    root_inorder_space->right->left = new TreeNode(9);
    root_inorder_space->right->left->parent = root_inorder_space->right;
    root_inorder_space->left->left->right = new TreeNode(5);
    root_inorder_space->left->left->right->parent = root_inorder_space->left->left;

    std::cout << "The inorder traversal of the binary tree: ";
    tree.inorderTraversalWithO1Space(root_inorder_space);
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
    BinaryTree reconstruct;

    reconstruct.insert(8);
    reconstruct.insert(6);
    reconstruct.insert(10);
    reconstruct.insert(4);
    reconstruct.insert(7);
    reconstruct.insert(9);
    reconstruct.insert(13);
    reconstruct.insert(5);
    reconstruct.insert(12);
    reconstruct.insert(14);

    tree.reconstructPreOrder(reconstruct.root);
    std::cout << "\n----------------------------------------------------------" << std::endl;
    
    // Create list from leaves.
    BinaryTree list_from_leaves;

    list_from_leaves.insert(8);
    list_from_leaves.insert(6);
    list_from_leaves.insert(10);
    list_from_leaves.insert(4);
    list_from_leaves.insert(7);
    list_from_leaves.insert(9);
    list_from_leaves.insert(13);
    list_from_leaves.insert(5);
    list_from_leaves.insert(12);
    list_from_leaves.insert(14);
    
    ListNode* leafList = tree.createsListFromLeaves(list_from_leaves.root);

    std::cout << "Linked list of leaves: ";
    tree.printLinkedList(leafList);
    std::cout << "----------------------------------------------------------" << std::endl;

    // Compute exterior.
    TreeNode* root_exterior = new TreeNode(8);
    root_exterior->left = new TreeNode(4);
    root_exterior->right = new TreeNode(13);
    root_exterior->left->left = new TreeNode(2);
    root_exterior->left->right = new TreeNode(5);
    root_exterior->right->right = new TreeNode(16);
    root_exterior->right->left = new TreeNode(11);
    root_exterior->left->left->left = new TreeNode(1);
    root_exterior->left->left->right = new TreeNode(3);
    root_exterior->left->right->right = new TreeNode(7);
    root_exterior->right->left->right = new TreeNode(12);
    root_exterior->right->right->right = new TreeNode(18);
    root_exterior->right->right->left = new TreeNode(14);
    root_exterior->left->right->right->left = new TreeNode(6);

    root_exterior->right->right->right->parent = root_exterior->right->right;
    root_exterior->right->right->parent = root_exterior->right;
    root_exterior->right->parent = root_exterior;

    tree.exteriorOfBinaryTree(root_exterior);
    std::cout << "\n----------------------------------------------------------" << std::endl;

    // Right sibling tree.
    BinaryTree right_sibling;

    right_sibling.insert(8);
    right_sibling.insert(4);
    right_sibling.insert(13);
    right_sibling.insert(2);
    right_sibling.insert(6);
    right_sibling.insert(10);
    right_sibling.insert(16);
    right_sibling.insert(1);
    right_sibling.insert(3);
    right_sibling.insert(5);
    right_sibling.insert(7);
    right_sibling.insert(9);
    right_sibling.insert(11);
    right_sibling.insert(14);
    right_sibling.insert(18);

    tree.rightSiblingTree(right_sibling.root);

    tree.printLevelNext(right_sibling.root);
    std::cout << "----------------------------------------------------------" << std::endl;

    // Lock the node.
    TreeNode* root_lock = new TreeNode(4);
    root_lock->left = new TreeNode(2);
    root_lock->right = new TreeNode(6);
    root_lock->left->parent = root_lock;
    root_lock->right->parent = root_lock;

    root_lock->left->left = new TreeNode(1);
    root_lock->left->right = new TreeNode(3);
    root_lock->left->left->parent = root_lock->left;
    root_lock->left->right->parent = root_lock->left;

    root_lock->right->left = new TreeNode(5);
    root_lock->right->right = new TreeNode(7);
    root_lock->right->left->parent = root_lock->right;
    root_lock->right->right->parent = root_lock->right;

    std::cout << "Locking node 1: " << (tree.lock(root_lock->left->left) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 3: " << (tree.lock(root_lock->left->right) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 2 (parent of 1 and 3): " << (tree.lock(root_lock->left) ? "Success" : "Failed") << std::endl;
    std::cout << "Unlocking node 3: " << (tree.unlock(root_lock->left->right) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 2 after unlocking node 3: " << (tree.lock(root_lock->left) ? "Success" : "Failed") << std::endl;
    std::cout << "Unlocking node 1: " << (tree.unlock(root_lock->left->left) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 2 after unlocking node 1: " << (tree.lock(root_lock->left) ? "Success" : "Failed") << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    
    // Check BST is proper and finds first value greater than input_key.
    BinaryTree if_BST;

    if_BST.insert(8);
    if_BST.insert(4);
    if_BST.insert(12);
    if_BST.insert(2);
    if_BST.insert(6);
    if_BST.insert(10);
    if_BST.insert(14);
    
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
    BinaryTree largest;
    
    largest.insert(8);
    largest.insert(4);
    largest.insert(12);
    largest.insert(2);
    largest.insert(6);
    largest.insert(14);
    largest.insert(10);
    largest.insert(3);
    largest.insert(16);
    largest.insert(13);

    int input_value = 3;

    tree.largestElementsInBST(largest.root, input_value);
    std::cout << "----------------------------------------------------------" << std::endl;
    
    // Level order tree traversal.
    BinaryTree level_order;

    level_order.insert(8);
    level_order.insert(4);
    level_order.insert(12);
    level_order.insert(2);
    level_order.insert(6);
    level_order.insert(14);
    level_order.insert(10);
    level_order.insert(3);
    level_order.insert(16);
    level_order.insert(13);

    level_order.levelOrderTraversal(level_order.root);
    std::cout << "----------------------------------------------------------" << std::endl;
    
    return 0;
}