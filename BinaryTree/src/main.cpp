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

    // sum of the weight of from root to a specified node
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
    return 0;
}