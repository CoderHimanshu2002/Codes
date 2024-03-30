#include <bits/stdc++.h> 
class node{

    public:
    int data;
    int i;
    int j;

    node(int data,int row,int col){
        this->data=data;
        i=row;
        j=col;
    }
};

class compare{

public:

bool operator()(node *a, node *b){
    return a->data > b->data;
}

};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node *,vector<node *>, compare> minHeap;

    //step 1: Insert first element of k arrays into a min Heap...
    for(int i=0;i<k;i++){
        node *temp=new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }

    vector<int> ans;
    //step 2: check for the next element in the same array...if exists...
    while(minHeap.size() >0){
        node *temp=minHeap.top();

        ans.push_back(temp->data);

        minHeap.pop();

        int i=temp->i;
        int j=temp->j;

        if(j+1 < kArrays[i].size()){
            node *next=new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    
   return ans;
}
