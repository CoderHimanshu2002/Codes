//APPROACH 1:-O(N^2)...

#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int> sumStore;
	int n=arr.size();

	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(),sumStore.end());

	return sumStore[sumStore.size()-k];
}

//APPROACH 2-: Using Min Heap...

#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int ,vector<int> ,greater<int>> pq;
    int n=arr.size();

	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
             sum+=arr[j];
			 if(pq.size() < k){
				 pq.push(sum);
			 }
			 else
			 {
				 if(sum > pq.top()){
					 pq.pop();
					 pq.push(sum);
				 }
			 }
		}
	}

	return pq.top();
}
