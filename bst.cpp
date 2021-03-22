#include <iostream>
#include<climits>
#include<algorithm>

#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//Accepts the old root node & data and returns the new root node 
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}
//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
//Inorder Print
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}

bool search(node* root,int data){
    if(root==NULL){
        return false;
    }

    if(root->data=data){
        return true;
    }

    if(root->data>data){
        return search(root->right,data);
    }
    else{
        return search(root->left,data);

    }
}

node* deleteInBST(node*root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBST(root->left,data);
        return root; 
    }
    else if(data==root->data){
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
            if(root->left!=NULL && root->right==NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right!=NULL && root->left==NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
        //3. Case 2 children
            node *replace = root->right;
            //Find the inorder successor from right subtree
            while(replace->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            return root;
    }
    else{
        root->right = deleteInBST(root->right,data);
        return root;
    }
}


bool isBST(node* root,int minV=INT_MIN,int maxV=INT_MAX){//IDE 23090
    if(root==NULL){
        return true;
    }

    if(root->data>=minV and root->data<=maxV and isBST(root->left,minV,root->data)and isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}


node* buildTree(int pre[],int in[],int s,int e ){

    if(s>e){
        return NULL;
    }

    static int i=0;
    int index=-1;
     for(int j=s;j<=e;j++){
        if(pre[i]==in[j]){
            index=j;
            break;
        }
     }
     node* root=new node(pre[i]);
     i++;
     // root=pre[i];
     root->left=buildTree(pre,in,s,index-1);
     root->right=buildTree(pre,in,index+1,e);
     return root;
}




int main(){ 
    // node*root = build();
    // inorder(root);
    // cout<<endl;
    // bfs(root);
    int arr[]={5,3,1,7,6,8};
    int b[]={5,3,1,7,6,8};
    int n=6;
    sort(b,b+n);
    node* root=buildTree(arr,b,0,5);
    // preorder(root);
    inorder(root);
return 0;
}










