// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int n = arr.size();
//         vector<int>ans(k);
//         if(x<arr[0]){
//             for(int i=0;i<k;i++){
//                 ans[i] = arr[i];
//             }

//             return ans;
//         }
//         if(x>arr[n-1]){
//             int i=n-1;
//             int j=k-1;
//             while(j>=0){
//                 ans[j]=arr[i];
//                 j--;
//                 i--;
//             }

//             return ans;
//         }

//         int lo=0;
//         int hi=n-1;
//         bool flag = false;
//         int idx = 0;
//         int mid=-1;
//         //binary search
//         while(lo<=hi){
//             int mid = lo + (hi-lo)/2;
//             if(arr[mid]==x){
//                 flag =true;
//                 ans[idx] = arr[mid];
//                 idx++;
//                 break;
//             }
//             else if(arr[mid]>x) hi= mid-1;
//             else lo= mid+1;
//         }
//         int lb = arr[hi];
//         int ub = arr[lo];
//         if(flag==true){
//             lb = mid-1;
//             ub = mid+1;
//         }

//         while(idx<k && lb>=0 && ub<=n-1){
//             int dn1 = abs(x-arr[lb]);
//             int dn2 = abs(x-arr[ub]);

//             if(dn1<=dn2){
//                 ans[idx]=arr[lb];
                
//                 lb--;
//             }
//             else{ // d1<d2
//                 ans[idx] = arr[ub];
//                 ub++;
//             }
//             idx++;
//         }

//         if(lb<0){
//             while(idx<k){
//                 ans[idx] = arr[ub];
//                 ub++;
//                 idx++;
//             }
//         }

//         if(ub>=n-1){
//             while(idx<k){
//                 ans[idx]=arr[lb];
//                 lb--;
//                 idx++;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();
        vector<int> ans(k);

        if (x < arr[0]) {
            for (int i = 0; i < k; i++) {
                ans[i] = arr[i];
            }
            return ans;
        }

        if (x > arr[n - 1]) {
            int i = n - 1;
            int j = k - 1;

            while (j >= 0) {
                ans[j] = arr[i];
                j--;
                i--;
            }

            return ans;
        }

        int lo = 0;
        int hi = n - 1;
        bool flag = false;
        int idx = 0;
        int mids = -1;

        // binary search
        while (lo <= hi) {
            mids = lo + (hi - lo) / 2;

            if (arr[mids] == x) {
                flag = true;
                ans[idx] = arr[mids];
                idx++;
                break;
            }
            else if (arr[mids] > x) {
                hi = mids - 1;
            }
            else {
                lo = mids + 1;
            }
        }

        int lb = hi;
        int ub = lo;

        if (flag == true) {
            lb = mids - 1;
            ub = mids + 1;
        }

        while (idx < k && lb >= 0 && ub <= n - 1) {

            int dn1 = abs(x - arr[lb]);
            int dn2 = abs(x - arr[ub]);

            if (dn1 <= dn2) {
                ans[idx] = arr[lb];
                lb--;
            }
            else {
                ans[idx] = arr[ub];
                ub++;
            }

            idx++;
        }

        if (lb < 0) {
            while (idx < k) {
                ans[idx] = arr[ub];
                ub++;
                idx++;
            }
        }

        if (ub > n - 1) {
            while (idx < k) {
                ans[idx] = arr[lb];
                lb--;
                idx++;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};