#include<iostream>
using namespace std;
  
//declaration for structure of new bst node
struct node{
    int data;
    struct node *left, *right;
};
  
// create a Binary search tree
struct node *newNode(int data){
    struct node *temp = new struct node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// inorder ： left -> root -> right 

void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// preorder : root -> left -> right 
// its a recursive function
void preorder(struct node *root){
    if (root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// postorder : left -> right -> root
// its a recursive function
void postorder(struct node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}



/*add new node in bts */
struct node* insert(struct node* node, int data){
  //empty situation  
    if (node == NULL) 
    return newNode(data);
  //not empty so add new node in right place
    if (data <= node->data)
       node->left = insert(node->left, data);
    else
       node->right = insert(node->right, data);
    return node;
    }
    // find the inorder successor of the given node
    struct node * inorderSuccessor(struct node* node){
        struct node* current = node;
        while (current && current->left != NULL)
            current = current->left;
            return current;
        }

/*recursive function to delete the node with given data
*/
struct node* deleteNode(struct node* root, int data){
   if (root == NULL) return NULL;    
       if (data < root->data)
          root->left = deleteNode(root->left, data);
    // if data > root, go for right subtree
       else if (data > root->data)
          root->right = deleteNode(root->right, data);


   else{
    // node with only one or no 
      if (root->left == NULL){
         struct node *temp = root->right;
         free(root);
         return temp;
         }
      else if (root->right == NULL){
        struct node *temp = root->left;
        free(root);
        return temp;
        }    
    struct node* temp = inorderSuccessor(root->right);  // node with both children; get successor and then delete the node
    root->data = temp->data;  // Copy the inorder successor's content to this node
    root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
        return root;

}   



int main(){

    struct node *root = NULL;
       root = insert(root, 60);
       root = insert(root, 30);
       root = insert(root, 8);
       root = insert(root, 50);
       root = insert(root, 66);
       root = insert(root, 89);

    cout<<"Binary Search Tree created \nInorder traversal :"<<endl;
        inorder(root);
    cout<<"\npreorder traversal :"<<endl;
        preorder(root);
    cout<<"\npostorder traversal :"<<endl;
        postorder(root);
    cout<<"\nDelete node 66\n";
        root = deleteNode(root, 66);
    cout<<"Inorder traversal for the modified Binary Search Tree:"<<endl;
        inorder(root);

    return 0;
}

