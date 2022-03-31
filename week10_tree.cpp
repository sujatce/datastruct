#include <iostream>
#include <unordered_map>

using namespace std;

class TreeNode{
    public:
        char val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(char x)
        {
            this->val = x;
            this->left = nullptr;
            this->right = nullptr;
        }
        void inorder(TreeNode *node)
        {
            if(node == nullptr)
                return;
            inorder(node->left);
            cout<<node->val<<"\t";
            inorder(node->right);
        }
        void preorder(TreeNode *node)
        {
            if(node == nullptr)
                return;
            cout<<node->val<<"\t";
            preorder(node->left);            
            preorder(node->right);
        }
        void postorder(TreeNode *node)
        {
            if(node == nullptr)
                return;
            postorder(node->left);
            postorder(node->right);
            cout<<node->val<<"\t";
        }
        TreeNode* buildLeft(char x)
        {
            TreeNode* newNode = new TreeNode(x);
            this->left = newNode;
            return newNode;
        }
        TreeNode* buildRight(char x)
        {
            TreeNode* newNode = new TreeNode(x);
            this->right = newNode;
            return newNode;
        }
};

int main()
{
    /* Build a tree*/
    TreeNode* root = new TreeNode('K');
    TreeNode* CNode = root->buildLeft('B')->buildLeft('C');
    CNode->buildLeft('H');
    CNode->buildRight('J');
    TreeNode* TNode = root->buildRight('Z')->buildRight('T');
    TNode->buildLeft('D');
    TNode->buildRight('I');
    /*End building Tree*/
    root->inorder(root);cout<<endl;
    root->preorder(root);cout<<endl;
    root->postorder(root);cout<<endl;
    return EXIT_SUCCESS;
}