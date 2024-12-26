#include "../header/BinaryTree.h"

int main()
{
    BinaryTree tree;
    // check if the tree is symmetric
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

    // find the lowest common ancestor
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

    // sum of binary numbers
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

    return 0;
}