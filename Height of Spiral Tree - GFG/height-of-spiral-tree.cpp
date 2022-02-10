// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


void saveLeafNodes(Node* root, vector<Node*> &leaf)
{
    if(!root)return;
    saveLeafNodes(root->left, leaf);
    if(root->left==NULL && root->right==NULL)leaf.push_back(root);
    saveLeafNodes(root->right, leaf);
}

void linkLeafNodes(Node* root)
{
    vector<Node*> leaf;
    saveLeafNodes(root, leaf);
    if(leaf.size()<=1)return;
    for(int i=0; i<leaf.size(); i++)
    {
        if(i==0)
        {
            leaf[i]->right=leaf[i+1];
            leaf[i]->left=leaf[leaf.size()-1];
        }
        else if(i==leaf.size()-1)
        {
            leaf[i]->right=leaf[0];
            leaf[i]->left=leaf[i-1];
        }
        else
        {
            leaf[i]->right=leaf[i+1];
            leaf[i]->left=leaf[i-1];
        }
    }
    return;
}

int findTreeHeight(Node* node);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        linkLeafNodes(root);
        int h = findTreeHeight(root);
        cout<<h<<endl;
    }
    return 1;
}// } Driver Code Ends


/*Structure of the node of the binary tree

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Return the height of the given special binary tree

bool isLeaf(Node *root){
    if(root->left && root->left->right && root->left->right != root){
        return false;
    }
    if(root->right && root->right->left && root->right->left != root){
        return false;
    }
    return true;
}

int findTreeHeight(Node* root)
{
	if(root){
	    if(isLeaf(root)){
	        return 1;
	    }
	    int left = findTreeHeight(root->left);
	    int right = findTreeHeight(root->right);
	    
	    return max(left,right) + 1;
	}
	return 0;
}