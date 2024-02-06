 
    bool knows(vector<vector<int>> &M,int a ,int b,int n)
    {
        if(M[a][b]==1)
        return true;
        
        else
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(knows(M,a,b,n))
            {
                s.push(b);
            }
            
            else
            {
                s.push(a);
            }
        }
        
        int ans=s.top();
        
        bool rowCheck=0;
        int zeroCount=0;
        
        for(int i=0;i<n;i++)
        {
            if(M[ans][i]==0)
            zeroCount++;
        }
        
        if(zeroCount==n)
        {
            rowCheck=1;
        }
        
        bool colCheck=0;
        int oneCount=0;
        
        for(int i=0;i<n;i++)
        {
            if(M[i][ans]==1)
            oneCount++;
        }
        
        if(oneCount==n-1)
        {
            colCheck=1;
        }
      if(colCheck==true && rowCheck==true)
      return ans;
      
      else
      return -1;
        
        
    }
