#include <iostream>
#include <unordered_map>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x)        {
            this->val = x;//nullptr; //THIS IS WRONG????
            this->left = nullptr;
            this->right = nullptr;
        }


        TreeNode* minimalBST(int *arr, int i, int j){ //THIS IS WRONG??? can NOT BE VOID*
            if(i>j) //THIS COULD BE WRONG
                return nullptr;
            int mid = (i+j)/2; //THIS COULD BE WRONG 
            int val = arr[mid]; //THIS COULD BE WRONG
            TreeNode *node = new TreeNode(val); //THIS IS WRONG?? has to pass some value - like val
            node->left = minimalBST(arr,i,mid-1); //THIS COULD BE WRONG, it must be left
            node->right = minimalBST(arr,mid+1,j); //THIS COULD BE WRONG, it must be right.

            return node;//val; //THIS IS WRONG -> HAS TO RETURN TREENODE*?????
        }
        void inorder(TreeNode *node)
        {
            if(node == nullptr)
                return;
            inorder(node->left);
            cout<<node->val<<"\t";
            inorder(node->right);
        }
};

int main()
{
    int arr[] = {1,2,3,4,5,6};
    TreeNode* BSTTree = new TreeNode(0);
    BSTTree = BSTTree->minimalBST(arr,0,5);
    BSTTree->inorder(BSTTree);cout<<endl;
    return EXIT_SUCCESS;
}