class Solution {
public:

    bool isValid(vector<int>&arr,int n,int m, int maxallowedpages){
        int students = 1,pages=0;

        for (int i=0;i<n;i++){

            if(arr[i]>maxallowedpages){
                return false;
            }
            if(pages + arr[i]<=maxallowedpages){
                pages +=arr[i];
            }
            else{
                students++;
                pages= arr[i];
            }
        }

        return students <= m;
    }

    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();
        int m = k;

        int sum =0;
        for (int i=0;i<n;i++){
            sum+=nums[i];
        }

        int ans=-1;
        int st=0,end=sum;

        while(st<=end){
            int mid = st + (end-st)/2;

            if(isValid(nums,n,m,mid)){
                ans=mid;
                end=mid-1;
            }

            else{
                st=mid+1;
            }
        }

        return ans;
    }
};