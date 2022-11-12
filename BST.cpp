#include "BST.h"

using namespace std;

BST::BST() {
    root = NULL;
}
BST::~BST() {
//    clear();
}

//Please note that the class that implements this interface must be made
 //of objects which implement the NodeInterface

 /*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
 Node *BST::getRootNode() const {
     return root;
 }

 /*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
 bool BST::add(int data) {
     return insert(data, root);
 }

bool BST::insert(int val, Node *&T){ //pass by reference, important!
    if(T==NULL) {
        T = new Node(val);
        return true;
    }
    if(T->value == val)
        return false;
    else if (T->value > val)
        return insert(val, T->left);
    else
        return insert(val,T->right);
}

 /*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
 bool BST::remove(int data) {
     return removeRec(data, root);
 }

 bool BST::removeRec(int val, Node *&T) {
     if(T == NULL)
         return false;

     //continues to move down tree if value is not found
      if(T->value != val){
          //returns false if bottom of branch is reached w/o value
          if(T->left == NULL && T->right == NULL)
              return false;

          //determines left/right movement
          else if(T->value > val)
              return removeRec(val, T->left);
          else
              return removeRec(val,T->right);
      }

      //if value is found, go through removal steps
      else {
          //if deleting root, call removeRoot function (less cluttered)
          if(T == root)
              removeRoot();

          //if 2 children...
          else if(T->left != NULL && T->right != NULL){
              Node *findSmallest = T->left;
              while(findSmallest->right != NULL)
                  findSmallest = findSmallest->right;
              int newVal = findSmallest->value;
              remove(newVal);
              T->value = newVal;
          }

          //PREVIOUS 2CHILD CODE IF IT GETS MESSED UP
//          else if(T->left != NULL && T->right != NULL){
//              Node *findSmallest = T->right;
//              while(findSmallest->left != NULL)
//                  findSmallest = findSmallest->left;
//              int newVal = findSmallest->value;
//              remove(newVal);
//              T->value = newVal;
//          }

          //if 1 left child...
          else if(T->left != NULL){
              Node *newNode = T->left;
              delete T;
              T = newNode;
          }
          //if 1 right child...
          else if(T->right != NULL){
              Node *newNode = T->right;
              delete T;
              T = newNode;
          }

          //if no children...
          else {
              delete T;
              T = NULL;
          }

          return true;
      }
 }

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear(){
    recursiveClear(root);
    root = NULL;
}

void BST::recursiveClear(Node *curr){
    cout << "inside clear function" << endl;
    if(curr != NULL){
        recursiveClear(curr->left);
        recursiveClear(curr->right);
        delete curr;
    }
}

void BST::removeRoot(){
    if(root->left != NULL){
        Node *findVal = root->left;
        //goes right until reaching null
        while(findVal->right != NULL)
            findVal = findVal->right;
        int newVal = findVal->value;
        remove(newVal);
        root->value = newVal;
    }
    else if(root->right != NULL){
        Node* newRoot = root->right;
        delete root;
        root = newRoot;
    }
    else {
        delete root;
        root = NULL;
    }
}