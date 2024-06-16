#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* node, int val){
    if(node == NULL){
        return new TreeNode(val);
    }

    if(val < node->val){
        node->left = insert(node->left, val);
    }
    else if(val > node->val){
        node->right = insert(node->right, val);
    }
    return node;
}

void preorderTraversal(TreeNode* node){
    if(node != NULL){
        cout<<node->val<<" ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void inorderTraversal(TreeNode* node){
    if(node != NULL){
        inorderTraversal(node->left);
        cout<<node->val<<" ";
        inorderTraversal(node->right);
    }
}

void postorderTraversal(TreeNode* node){
    if(node != NULL){
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout<<node->val<<" ";
    }
}

int main(){
    TreeNode* root = NULL;
    int ch;
    cout<<"1. Insert into Binary Search Tree"<<endl;
    cout<<"2. Preorder Traversal"<<endl;
    cout<<"3. Inorder Traversal"<<endl;
    cout<<"4. Postorder Traversal"<<endl;
    do{
        cout<<"Enter your choice, 0 to stop: ";
        cin>>ch;
        switch(ch){
            case 1:
                int val;
                cout<<"Enter the value to insert: ";
                cin>>val;
                root = insert(root, val);
                break;
            case 2:
                cout<<"Preorder Traversal: ";
                preorderTraversal(root);
                cout<<endl;
                break;
            case 3: 
                cout<<"Inorder Traversal: ";
                inorderTraversal(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Postorder Traversal: ";
                postorderTraversal(root);
                cout<<endl;
                break;
            case 0:
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid option, please enter again"<<endl;
        }
    }while(ch!=0);

    return 0;
}

