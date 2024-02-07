#include<stack>
 vector<int> nextSmallerElement(vector<int> arr,int n)
 {
   stack<int> s;
   s.push(-1);
   vector<int> ans(n);
   
   for(int i=n-1;i>=0;i--)
   {
     int curr=arr[i];
     while(s.top()!=-1 && arr[s.top()]>=curr)
     {
       s.pop();
     }

     ans[i]=s.top();
     s.push(i);
   }

   return ans;
 }

  vector<int> nextPreviousElement(vector<int> arr,int n)
  {
   stack<int> s;
   s.push(-1);
   vector<int> ans(n);
   
   for(int i=0;i<n;i++)
   {
     int curr=arr[i];
     while(s.top()!=-1 && arr[s.top()]>=curr)
     {
       s.pop();
     }

     ans[i]=s.top();
     s.push(i);
   }

   return ans; 
  }
 

 int largestRectangle(vector < int > & heights) 
 {
   // Write your code here.
  int n=heights.size();
  vector<int> next(n);
  next=nextSmallerElement(heights,n);
  vector<int> prev(n);
  prev=nextPreviousElement(heights,n);

  int area=0;

  for(int i=0;i<n;i++)
  {
    int l=heights[i];

    if (next[i] == -1) {
      next[i] = n;
    }
    int b = next[i] - prev[i] - 1;
    int newArea = l * b;
    area = max(area, newArea);
  }

  return area;
 }
