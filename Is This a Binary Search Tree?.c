/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
bool fun(Node*root,int l,int h)
{
        if(root==NULL)return true;
        if(root->data<=l || root->data>=h)return false;
        return fun(root->left,l,root->data)  && fun(root->right,root->data,h);
}
	bool checkBST(Node* root) 
    {
        int l=0,h=10001;
        return fun(root,l,h);
	}
