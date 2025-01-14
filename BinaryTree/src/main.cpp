#include "../header/BinaryTree.h"

int main()
{
    BinaryTree tree;

    // Check if the tree is symmetric.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    if(tree.isSymmetric(root)) 
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
    rootsumweight->left = new TreeNode(4);
    rootsumweight->right = new TreeNode(8);
    rootsumweight->left->left = new TreeNode(11);
    rootsumweight->right->left = new TreeNode(13);
    rootsumweight->right->right = new TreeNode(4);
    rootsumweight->left->left->left = new TreeNode(7);
    rootsumweight->left->left->right = new TreeNode(2);
    rootsumweight->right->right->right = new TreeNode(1);
    int num = 22;
    int currentsum = 0;

    if (tree.hasPathWeight(rootsumweight, num, currentsum)) {
        std::cout << "There exists a leaf whose path weight equals " << num << ".\n";
    } else {
        std::cout << "No leaf path weight equals " << num << ".\n";
    }
    std::cout << "----------------------------------------------------------" << std::endl;

    // Inorder traversal without recursion.
    TreeNode* root_inorder = new TreeNode(8);
    root_inorder->left = new TreeNode(5);
    root_inorder->right = new TreeNode(10);
    root_inorder->left->left = new TreeNode(4);
    root_inorder->left->right = new TreeNode(7);
    root_inorder->right->right = new TreeNode(13);
    root_inorder->right->left = new TreeNode(9);
    root_inorder->left->left->right = new TreeNode(6);
    root_inorder->right->right->right = new TreeNode(14);
    root_inorder->right->right->left = new TreeNode(12);

    /*
    // Constructed binary tree:
               8
             /   \
            /     \
           5      10
          / \    /   \  
         4   7  9     13
          \          /  \
           6       12    14    
    */
    int k = 7;
    std::vector<int> inorder_traversal = tree.inorderTraversal(root_inorder, k);
    std::cout << "The inorder traversal of the binary tree: ";
    for (int val : inorder_traversal)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    
    // Preorder traversal without recursion.
    TreeNode* root_preorder = new TreeNode(8);
    root_preorder->left = new TreeNode(5);
    root_preorder->right = new TreeNode(10);
    root_preorder->left->left = new TreeNode(4);
    root_preorder->left->right = new TreeNode(7);
    root_preorder->right->right = new TreeNode(13);
    root_preorder->right->left = new TreeNode(9);
    root_preorder->left->left->right = new TreeNode(6);
    root_preorder->right->right->right = new TreeNode(14);
    root_preorder->right->right->left = new TreeNode(12);

    std::vector<int> preorder_traversal = tree.preorderTraversal(root_preorder);
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
    root_inorder_space->left = new TreeNode(5);
    root_inorder_space->right = new TreeNode(10);
    root_inorder_space->left->parent = root_inorder_space;
    root_inorder_space->right->parent = root_inorder_space;

    root_inorder_space->left->left = new TreeNode(4);
    root_inorder_space->left->right = new TreeNode(7);
    root_inorder_space->left->left->parent = root_inorder_space->left;
    root_inorder_space->left->right->parent = root_inorder_space->left;

    root_inorder_space->right->left = new TreeNode(9);
    root_inorder_space->right->left->parent = root_inorder_space->right;
    root_inorder_space->left->left->right = new TreeNode(6);
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
    TreeNode* root_reconstruct = new TreeNode(8);
    root_reconstruct->left = new TreeNode(5);
    root_reconstruct->right = new TreeNode(10);
    root_reconstruct->left->left = new TreeNode(4);
    root_reconstruct->left->right = new TreeNode(7);
    root_reconstruct->right->right = new TreeNode(13);
    root_reconstruct->right->left = new TreeNode(9);
    root_reconstruct->left->left->right = new TreeNode(6);
    root_reconstruct->right->right->right = new TreeNode(14);
    root_reconstruct->right->right->left = new TreeNode(12);

    tree.reconstructPreOrder(root_reconstruct);
    std::cout << "\n----------------------------------------------------------" << std::endl;
    
    // Create list from leaves.
    TreeNode* list_from_leaves = new TreeNode(8);
    list_from_leaves->left = new TreeNode(5);
    list_from_leaves->right = new TreeNode(10);
    list_from_leaves->left->left = new TreeNode(4);
    list_from_leaves->left->right = new TreeNode(7);
    list_from_leaves->right->right = new TreeNode(13);
    list_from_leaves->right->left = new TreeNode(9);
    list_from_leaves->left->left->right = new TreeNode(6);
    list_from_leaves->right->right->right = new TreeNode(14);
    list_from_leaves->right->right->left = new TreeNode(12);
    
    ListNode* leafList = tree.createsListFromLeaves(list_from_leaves);

    std::cout << "Linked list of leaves: ";
    tree.printLinkedList(leafList);
    std::cout << "----------------------------------------------------------" << std::endl;

    // Compute exterior.
    TreeNode* root_exterior = new TreeNode(8);
    root_exterior->left = new TreeNode(5);
    root_exterior->right = new TreeNode(10);
    root_exterior->left->left = new TreeNode(4);
    root_exterior->left->right = new TreeNode(7);
    root_exterior->right->right = new TreeNode(13);
    root_exterior->right->left = new TreeNode(9);
    root_exterior->left->left->left = new TreeNode(3);
    root_exterior->left->left->right = new TreeNode(6);
    root_exterior->left->right->right = new TreeNode(22);
    root_exterior->right->left->right = new TreeNode(17);
    root_exterior->right->right->right = new TreeNode(14);
    root_exterior->right->right->left = new TreeNode(12);
    root_exterior->left->right->right->left = new TreeNode(20);

    root_exterior->right->right->right->parent = root_exterior->right->right;
    root_exterior->right->right->parent = root_exterior->right;
    root_exterior->right->parent = root_exterior;

    tree.exteriorOfBinaryTree(root_exterior);
    std::cout << "\n----------------------------------------------------------" << std::endl;

    // Right sibling tree.
    TreeNode* root_right_to_next = new TreeNode(8);
    root_right_to_next->left = new TreeNode(4);
    root_right_to_next->right = new TreeNode(13);
    root_right_to_next->left->left = new TreeNode(2);
    root_right_to_next->left->right = new TreeNode(6);
    root_right_to_next->right->left = new TreeNode(10);
    root_right_to_next->right->right = new TreeNode(16);
    root_right_to_next->left->left->left = new TreeNode(1);
    root_right_to_next->left->left->right = new TreeNode(3);
    root_right_to_next->left->right->left = new TreeNode(5);
    root_right_to_next->left->right->right = new TreeNode(7);
    root_right_to_next->right->left->left = new TreeNode(9);
    root_right_to_next->right->left->right = new TreeNode(11);
    root_right_to_next->right->right->left = new TreeNode(14);
    root_right_to_next->right->right->right = new TreeNode(18);

    tree.rightSiblingTree(root_right_to_next);

    tree.printLevelNext(root_right_to_next);
    std::cout << "----------------------------------------------------------" << std::endl;

    // Lock the node.
    TreeNode* root_lock = new TreeNode(1);
    root_lock->left = new TreeNode(2);
    root_lock->right = new TreeNode(3);
    root_lock->left->parent = root_lock;
    root_lock->right->parent = root_lock;

    root_lock->left->left = new TreeNode(4);
    root_lock->left->right = new TreeNode(5);
    root_lock->left->left->parent = root_lock->left;
    root_lock->left->right->parent = root_lock->left;

    root_lock->right->left = new TreeNode(6);
    root_lock->right->right = new TreeNode(7);
    root_lock->right->left->parent = root_lock->right;
    root_lock->right->right->parent = root_lock->right;

    std::cout << "Locking node 4: " << (tree.lock(root_lock->left->left) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 5: " << (tree.lock(root_lock->left->right) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 2 (parent of 4 and 5): " << (tree.lock(root_lock->left) ? "Success" : "Failed") << std::endl;
    std::cout << "Unlocking node 5: " << (tree.unlock(root_lock->left->right) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 2 after unlocking node 5: " << (tree.lock(root_lock->left) ? "Success" : "Failed") << std::endl;
    std::cout << "Unlocking node 4: " << (tree.unlock(root_lock->left->left) ? "Success" : "Failed") << std::endl;
    std::cout << "Locking node 2 after unlocking node 4: " << (tree.lock(root_lock->left) ? "Success" : "Failed") << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    
    // Check BST is proper and finds first value greater than input_key.
    TreeNode* root_BST = new TreeNode(8);
    root_BST->left = new TreeNode(4);
    root_BST->right = new TreeNode(12);
    root_BST->left->left = new TreeNode(2);
    root_BST->left->right = new TreeNode(6);
    root_BST->right->left = new TreeNode(10);
    root_BST->right->right = new TreeNode(14);

    TreeNode* input_key = new TreeNode(13);
    if (tree.isBST(root_BST, input_key)) {
        std::cout << "The tree satisfies the BST property." << std::endl;
        std::cout << "First key greater than input value: " << input_key->val << std::endl;
    } else {
        std::cout << "The tree does NOT satisfy the BST property." << std::endl;
        std::cout << "First key greater than input value: " << input_key->val << std::endl;
    }
    std::cout << "----------------------------------------------------------" << std::endl;

    // Largest elements.
    TreeNode* root_largest = new TreeNode(8);
    root_largest->left = new TreeNode(4);
    root_largest->right = new TreeNode(12);
    root_largest->left->left = new TreeNode(2);
    root_largest->left->right = new TreeNode(6);
    root_largest->right->right = new TreeNode(14);
    root_largest->right->left = new TreeNode(10);
    root_largest->left->left->right = new TreeNode(3);
    root_largest->right->right->right = new TreeNode(16);
    root_largest->right->right->left = new TreeNode(13);
    
    int input_value = 3;

    tree.largestElementsInBST(root_largest, input_value);
    std::cout << "----------------------------------------------------------" << std::endl;
    return 0;
}