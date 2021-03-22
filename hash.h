#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
class node{
	public:
	string key;
	T value;
	node<T>* next;

	node(string key,T val){
		this->key=key;
		value=val;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template <typename T>
class Hashtable{
	node<T>** table;
	int current_size;
	int table_size;

	int hashFn(string key){//check notes 
		int idx=0;
		int p=1;
		for(int j=0;j<key.length();j++){
			idx=idx+(key[j]*p)%table_size;
			idx=idx%table_size;
			p=(p*27)%table_size;
		}
		
		return idx;
	}
	void rehash(){
		node<T>**oldTable=table;
		int oldTableSize=table_size;
		table_size=2*oldTableSize;
		table=new node<T>*[table_size];
		for(int i=0;i<table_size;i++)
				table[i]=NULL;
		current_size=0;
		for(int i=0;i<oldTableSize;i++){
			node<T>*temp=oldTable[i];
				while(temp!=NULL){
					insert(temp->key,temp->value);
					temp=temp->next;
				}
				if(oldTable[i]!=NULL){
					delete(oldTable[i]);
				}
			}
				delete [] oldTable;
		}
public:
	Hashtable(int ts=7){
		current_size=0;
		table_size=ts;
		table=new node<T>*[table_size];
		for(int i=0;i<ts;i++){
			table[i]=NULL;
		}
	}

	void insert(string key,T value){
		int idx=hashFn(key);

		node<T>*n=new node<T>(key,value);
		//Insert at head of linked list
		n->next=table[idx];//check notes 
		table[idx]=n;
		current_size++;
		float load_factor=current_size/(1.0*table_size);
		if(load_factor>0.7)
			rehash();
	}

	void print(){
		for(int i=0;i<table_size;i++){
			node<T>*temp=table[i];
			cout<<"Bucket : "<<i<<" -> ";
			while(temp!=NULL){
				cout<<temp->key<<"->";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	T* search(string key){
		int idx=hashFn(key);
		node<T>*temp=table[idx];
		while(temp!=NULL){
			if(temp->key==key){
				return &temp->value;
			}
			temp=temp->next;
		}

		return NULL;
	}
	void erase(string key){
		int idx=hashFn(key);
		node<T>*temp=table[idx];
		if(temp->key==key){
			// node<T>* t=temp;
			table[idx]=temp->next;
			temp->next=NULL;
			delete(temp);
			current_size--;
			return;
		}
		while(temp!=NULL or temp->next!=NULL){
			if(temp->next->key==key){
				node<T>* t=temp->next;
				temp->next=t->next;
				t->next=NULL;
				delete t;
				return;
			}
			temp=temp->next;
		}

		// return NULL;
	}
	
	
};
