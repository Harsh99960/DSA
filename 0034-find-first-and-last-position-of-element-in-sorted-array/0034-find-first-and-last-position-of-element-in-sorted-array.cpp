class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int lo = 0, hi = n - 1;
        int mid;
        vector<int> ans(2, -1);

        // First Occurrence
        while(lo <= hi){
            mid = lo + (hi - lo) / 2;

            if(nums[mid] == target){
                if(mid == 0 || nums[mid-1] != target){
                    ans[0] = mid;
                    break;
                }
                else{
                    hi = mid - 1;
                }
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        lo = 0;
        hi = n - 1;

        // Last Occurrence
        while(lo <= hi){
            mid = lo + (hi - lo) / 2;

            if(nums[mid] == target){
                if(mid == n-1 || nums[mid+1] != target){
                    ans[1] = mid;
                    break;
                }
                else{
                    lo = mid + 1;
                }
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};