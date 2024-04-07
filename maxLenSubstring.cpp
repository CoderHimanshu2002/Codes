int maximumLengthSubstring(string s) {
        vector<int> maxLen;
        unordered_map<char,int> count;
         
        for(int i=0;i<s.length();i++){
            int sum=0;
            char ch=s[i];
            count[ch]++;
            int len=1;
            for(int j=i+1;j<s.length();j++){
              char c=s[j];
              count[c]++;

              if(count[c]<=2){
                sum=len+1;
                maxLen.push_back(sum);
                len++;
              }
              else{
                break;
              }
            }

            count.clear();
        }

        int maxi=*max_element(maxLen.begin(),maxLen.end());

        return maxi;
    }
