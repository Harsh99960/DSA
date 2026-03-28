class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        //insertion sort 
        for(int i = 1; i<n; i++){
            int j = i;
            while(j>=1){
                if(nums[j]>=nums[j-1]) break;
                else swap(nums[j],nums[j-1]);
                j--;
            }
        }

        //counting logic can be used here as per my choice

        int count = 1;
        int ans = nums[0];
        for(int i =1 ; i<n; i++){
            if(nums[i]==nums[i-1]){
                count ++;
            } else{
                count =1;
            }

            if(count>n/2){
                ans = nums[i];
                break;
            }
        }

        return ans;
    } 
};



