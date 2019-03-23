/*
This problem was asked by Dropbox.

Given the root to a binary search tree, 
find the second largest node in the tree.
*/

//only the function is defined.
void kthLargest(Node *root)
{
    Node *res = NULL;
    

    //go to the largest node to the rightmost node, 
    //keeping its parent as second largest.
    while(root->right){
        res = root;
        root = root->right;
    }
    
    //if the rightmost node(largest) has any left node,
    // then it is greater than its parent, so becomes second largest.
    if(root->left){
        res = root->left;
        root= root->left;
    }
    
    //now if this left node has right node then its rightmost node is largest of all,
    //and is hence our second largest node.
    while(root->right){
        root = root->right;
        res = root;
    }
    
    return res;
    
}