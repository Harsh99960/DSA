class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            int correctidx = nums[i];
            if(correctidx == i || nums[i]==n) i++;
            else swap(nums[i], nums[correctidx]);
        }

        for(int i = 0; i<n;i++){
            if(nums[i]!=i) return i;
        }

        return n ;
    }
};



// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();

//         int actualSum = n * (n+1)/2 ;

//         int realSum = 0;
//         for(int i =0 ; i<n ; i++){
//             realSum += nums[i];
//         }

//         return actualSum - realSum;
//     }
// };


// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> check(n+1 , false);
//         for(int i =0;i<n;i++){
//              int ele = nums[i];
//             check[ele]=true;
//         }


//         for(int i = 0; i<=n ; i++){
//             if(check[i]==false) return i;
//         }

//         return 0;
//     }
// };