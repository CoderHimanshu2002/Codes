int getPivot(vector<int> &arr){

        int s=0;
        int e=arr.size()-1;

        while(s<e){
            int mid=s+(e-s)/2;

            if(arr[mid] >= arr[0]){
                s=mid+1;
            }

            else
            e=mid;
        }

        return s;
    }
    
    int binarySearch(vector<int> &arr,int s,int e,int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target){
                return mid;
            }

            else if(arr[mid] < target){
                s=mid+1;
            }
            else if(arr[mid] > target){
                e=mid-1;
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
         int pivot=getPivot(nums);
         int n=nums.size();
         int ans;

         if(target >= nums[pivot] && target <= nums[n-1]){
            ans=binarySearch(nums,pivot,n-1,target);
         }
         else{
         ans=binarySearch(nums,0,pivot-1,target);
         }

         return ans;
    }
