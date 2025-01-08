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

bool BinaryTree::hasPathWeight(TreeNode* node, int targetWeight, int currentWeight)
{
    if (!node)  return false;

    currentWeight += node->val;

    if (!node->left && !node->right) 
    {
        return currentWeight == targetWeight;
    }

    return hasPathWeight(node->left, targetWeight, currentWeight) ||
           hasPathWeight(node->right, targetWeight, currentWeight);
}

std::vector<int> BinaryTree::inorderTraversal(TreeNode* root, int k) 
{
    int counter = 0;
    std::vector<int> result; 
    std::stack<TreeNode*> nodeStack; 
    TreeNode* current = root; 

    while (current != nullptr || !nodeStack.empty()) 
    {
        while (current != nullptr) 
        {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();
        nodeStack.pop();
        result.push_back(current->val); 
        counter++;
        
        if(counter == k)
        {
            std::cout <<"The " << k <<"th node in the inorder traversal is: " << current->val << std::endl;
        }
        
        current = current->right;
    }

    return result;
}

std::vector<int> BinaryTree::preorderTraversal(TreeNode* root)
{
    std::vector<int> result; 
    if (root == nullptr) return result;

    std::stack<TreeNode*> nodeStack; 
    nodeStack.push(root);

    while (!nodeStack.empty()) 
    {
        TreeNode* current = nodeStack.top();
        nodeStack.pop();

        result.push_back(current->val);

        if (current->right != nullptr) 
        {
            nodeStack.push(current->right);
        }
        
        if (current->left != nullptr) 
        {
            nodeStack.push(current->left);
        }
    }

    return result;
}

void BinaryTree::computeTheSuccessor(TreeNode* root, TreeNode* wanted)
{
    int successor_node;   
    std::vector<int> result; 
    std::stack<TreeNode*> nodeStack; 
    TreeNode* current = root; 

    while (current != nullptr || !nodeStack.empty()) 
    {
        while (current != nullptr) 
        {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();
        nodeStack.pop();
        result.push_back(current->val); 
        
        if(wanted->val == current->val)
        {
            if(current->right && !current->right->left)
            {
                successor_node = current->right->val;
                std::cout << "The successor of " << wanted->val << " is: " << successor_node << std::endl;
            }
            else if(current->right && current->right->left)
            {
                successor_node = current->right->left->val;
                std::cout << "The successor of " << wanted->val << " is: " << successor_node << std::endl;
            }
            else if(!current->right && !current->left)
            {
                TreeNode* temp = nodeStack.top();
                successor_node = temp->val;
                std::cout << "The successor of " << wanted->val << " is: " << successor_node << std::endl;
            }
            else
            {
                std::cout << wanted->val << " is the last node in the order." << std::endl;
            }

            break;
        }
        
        current = current->right;
    }
}
