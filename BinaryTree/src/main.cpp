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
    TreeNode* rootLCA = new TreeNode(3);
    rootLCA->left = new TreeNode(5);
    rootLCA->right = new TreeNode(1);
    rootLCA->left->left = new TreeNode(6);
    rootLCA->left->right = new TreeNode(2);
    rootLCA->right->left = new TreeNode(0);
    rootLCA->right->right = new TreeNode(8);
    rootLCA->left->right->left = new TreeNode(7);
    rootLCA->left->right->right = new TreeNode(4);

    TreeNode* p = rootLCA->right->right;
    TreeNode* q = rootLCA->right;
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
    return 0;
}