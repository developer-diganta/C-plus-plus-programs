#include<iostream>
#include<vector>

using namespace std;

class heap{
    vector<int> v;
    bool minHeap;
    bool compare(int a,int b){
        if(minHeap){
          return a<b;
        }
        return a>b;
    }
            void heapify(int idx){//check notes
        int left=2*idx;
        int right=left+1;

        int min_idx=idx;
        int last=v.size()-1;
        if(left<=last && compare(v[left],v[idx])){
            min_idx=left;
        }
        if(right<=last && compare(v[right],v[min_idx])){
            min_idx=right;
        }
        if(min_idx!=idx){
            swap(v[idx],v[min_idx]);
            heapify(min_idx);
        }
    }
public:
    heap(int default_size=10,bool type=true){
        v.reserve(default_size);
        v.push_back(-1);
        minHeap=type;
    }

    void push(int d){
        v.push_back(d);
        int idx=v.size() -1;
        int parent=idx/2;
        //to check if the element pushed is in correct order
        //and make sure to put that if not
        while(idx>1 and compare(v[idx],v[parent])){//check notes
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;

        }
    }
    int top(){
        return v[1];
    }

    void pop(){
        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }
    bool empty(){
        return v.size()==1;    
    }


};

void buildHeap(vector <int> &v){
    for(int i=2;i<v.size();i++){
        int idx=i;
        int parent=i/2;
        while(idx>1 and v[idx]>v[parent]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=idx/2;
        }
    }
}


     void heapifyOpt(vector <int> &v,int idx){//check notes
        int left=2*idx;
        int right=left+1;

        int min_idx=idx;
        int last=v.size()-1;
        if(left<=last && compare(v[left],v[idx])){
            min_idx=left;
        }
        if(right<=last && compare(v[right],v[min_idx])){
            min_idx=right;
        }
        if(min_idx!=idx){
            swap(v[idx],v[min_idx]);
            heapify(min_idx);
        }
    }

    void buildHeapOptimised(vector <int> &v){
    for(int i=v.size()-1/2;i>=1;i--){
        heapifyOpt(v,i);
    }
}

void heapSort(vector<int> &arr){
    buildHeap(arr);
    int n=arr.size();

    while(n>1){
        swap(arr[1],arr[n-1]);
        //last element is sorted so decrease heap size
        n--;
        heapify(arr,1,n);//make new heapify so that it accepts size from call
            }
}

int main(){
    // heap h(10,false);
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int no;
    //     cin>>no;
    //     h.push(no);
    // }
    // while(!h.empty()){
    //     cout<<h.top()<<" ";
    //     h.pop();
    // }
    vector <int> v={-1,10,20,5,6,1,8,9,4};
    buildHeapOptimised(v);//rewrite code in a new program with optimised approach
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}