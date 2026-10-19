class Solution {
public:  //Tc- O(n log n)
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        return nums[n / 2];
    }
};