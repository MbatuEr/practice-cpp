#include "../header/BinaryTree.h"

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}

ListNode::ListNode(int x) : val(x), next(nullptr) {}

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

void BinaryTree::inorderTraversalWithO1Space(TreeNode* root)
{
    if(!root) return;

    TreeNode* current = root;
    TreeNode* prev = nullptr;

    while (current) 
    {
        if (prev == current->parent) 
        {
            if (current->left) 
            {
                prev = current;
                current = current->left;
            } 
            else 
            {
                std::cout << current->val << " ";
                prev = current;
                current = current->right ? current->right : current->parent;
            }
        } 
        else if (prev == current->left) 
        {
            std::cout << current->val << " ";
            prev = current;
            current = current->right ? current->right : current->parent;
        } 
        else 
        {
            prev = current;
            current = current->parent;
        }
    }
}

TreeNode* BinaryTree::buildTreeHelper(std::vector<int>& preorder, int preStart, int preEnd,
                          std::vector<int>& inorder, int inStart, int inEnd,
                          std::unordered_map<int, int>& inMap) 
{
    if (preStart > preEnd || inStart > inEnd) 
    {
        return nullptr;
    }

    // Root is the first element of preorder traversal
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    // Find the root's index in inorder traversal
    int rootIndex = inMap[rootVal];
    int leftSubtreeSize = rootIndex - inStart;

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                                 inorder, inStart, rootIndex - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                  inorder, rootIndex + 1, inEnd, inMap);

    return root;
}

TreeNode* BinaryTree::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
{
    std::unordered_map<int, int> inMap; 
    for (int i = 0; i < inorder.size(); i++) 
    {
        inMap[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inMap);
}

 void BinaryTree::reconstructPreOrder(TreeNode* root)
 {  
    if(!root) return;

    std::stack<TreeNode*> nodeStack; 
    nodeStack.push(root);

    while (!nodeStack.empty()) 
    {
        TreeNode* current = nodeStack.top();
        nodeStack.pop();

        std::cout << current->val << " ";

        if (current->right != nullptr) 
        {
            nodeStack.push(current->right);
        }
        else
        {
            std::cout << "null" << " ";
        }
        
        if (current->left != nullptr) 
        {
            nodeStack.push(current->left);
        }
        else
        {
            std::cout << "null" << " ";
        }
    }
 }

void BinaryTree::collectLeaves(TreeNode* root, ListNode*& current)
{
     if (!root) return;

    if (!root->left && !root->right) 
    {
        current->next = new ListNode(root->val);
        current = current->next;
        return;
    }

    collectLeaves(root->left, current);
    collectLeaves(root->right, current);
}

 ListNode* BinaryTree::createsListFromLeaves(TreeNode* root)
 {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;

    collectLeaves(root, current);

    return dummy->next;
 }

 void BinaryTree::printLinkedList(ListNode* head) 
 {
    while (head) 
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}