#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* buildTree(){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node* root=new node(d);
	root->left=buildTree();
	root->right=buildTree();
	return root;
}

void print(node* root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

void printIn(node* root){
	if(root==NULL){
		return;
	}
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}

void printPost(node* root){
	if(root==NULL){
		return;
	}
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
}
int height(node* root){
	if(root==NULL)
		return 0;
	int ls=height(root->left);
	int rs=height(root->right);
	return max(ls,rs)+1;
}

void printKthLevel(node* root,int k){
	if(root==NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);

}

void printAllLevels(node* root){
	int H=height(root);

	for(int i=1;i<=H;i++){
		printKthLevel(root,i);
		cout<<endl;
	}
}

void bfs(node* root){//bfs with comma
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* f=q.front();
		cout<<f->data<<",";
		q.pop();

		if(f->left){
			q.push(f->left);
		}

		if(f->right){
			q.push(f->right);
		}
	}
	return;
}

void bfs2(node* root){//bfs with new line
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f=q.front();
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

int count(node *root){
	if(root==NULL){
		return 0;
	}
	return 1+count(root->left)+count(root->right);
}

int diameter(node*root){
	if(root==NULL){
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	int op1=h1+h2;
	int op2=diameter(root->left);
	int op3=diameter(root->right);
	return max(op1,max(op2,op3));
}
//for diameter using optimised approach
class Pair{
public:
	int height;
	int diameter;
};

Pair fastDiameter(node*root){
	Pair p;
	if(root==NULL){
		p.diameter=p.height=0;
		return p;
	}
	Pair left=fastDiameter(root->left);
	Pair right=fastDiameter(root->right);
	p.height=max(left.height,right.height)+1;
	p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
	return p;

}

int replaceSum(node* root){
	if(root==NULL){
		return 0;
	}

	if(root->left==NULL && root->right==NULL)//leaf node..not required to change any value
	{
		return root->data;//only returning its data
	}

	//Recursive part
	int temp=root->data;
	int ls=replaceSum(root->left);//getting sum of left subtree
	int rs=replaceSum(root->right);//getting sum of right subtree
	root->data=ls+rs;//replacing data
	return temp+root->data;//sending current root data + ls + rs
}
//for checking height balanced tree
class HBPair{
public:
	int height;
	bool balance;
};

HBPair isbalanced(node* root){
	HBPair p;
	if(root==NULL){
		p.height=0;
		p.balance=true;
		return p;
	}

	HBPair left=isbalanced(root->left);
	HBPair right=isbalanced(root->right);

	p.height=max(left.height,right.height)+1;
	if(abs(left.height-right.height)<=1 && left.balance && right.balance){
		p.balance=true;
	}
	else{
		p.balance=false;
	}
	return p;
}

node* buildTreeFromArray(int *a,int s,int e){
	if(s>e)
		return NULL;
	int mid=(s+e)/2;
	node* root=new node(a[mid]);
	root->left=buildTreeFromArray(a,s,mid-1);
	root->right=buildTreeFromArray(a,mid+1,e);
	return root;
}
int main(){
	// node* root=NULL;
	// root=buildTree();
	// // print(root);
	// // cout<<endl;
	// // printIn(root);
	// // cout<<endl;
	// // printPost(root);
	// // cout<<endl<<height(root);
	// // cout<<endl;
	// // printAllLevels(root);
	// // cout<<endl;
	// // bfs(root);
	// // cout<<endl;
	// // cout<<count(root);
	// // cout<<endl;
	// // cout<<"DIA : "<<diameter(root);
	// // replaceSum(root);
	// // printAllLevels(root);
	// if(isbalanced(root).balance){
	// 	cout<<"Balanced"<<endl;
	// }
	// else{
	// 	cout<<"Not Balanced"<<endl;
	// }
	int a[]={1,2,3,4,5,6,7};
	int n=7;
	node* tree=buildTreeFromArray(a,0,n-1);
	bfs2(tree);
	return 0;
}