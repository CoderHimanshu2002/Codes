//Simple intuition is to use two pointer's approach and use Binary Search Algo to do it in O(sqrt(number)) complexity and constant space...

bool judgeSquareSum(int c) {
        long long int high=sqrt(c);
        long long int low=0;

        // IF number is less than 2 it's true case...
        if(c<2)
        return 1;
          
        while(low<=high){
          //If found return true...
          if((low*low+high*high)==c)
          return true;

          //If resultant is greater than number decrement high ...
          else if((low*low+high*high)>c)
          {
            high--;
          }

          //If the resultant is less than number then increment low...
          else{
            low++;
          }
        }

        return false;
    }
