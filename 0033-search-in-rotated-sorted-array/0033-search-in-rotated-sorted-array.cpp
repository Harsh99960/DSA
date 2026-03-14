class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        int pivot = -1;

        // find pivot
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                pivot = mid + 1;
                break;
            }

            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                pivot = mid;
                break;
            }

            if (nums[mid] >= nums[lo]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // if no rotation
        if (pivot == -1) {
            lo = 0;
            hi = n - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }

            return -1;
        }

        // search in first half
        if (target >= nums[0] && target <= nums[pivot - 1]) {

            lo = 0;
            hi = pivot - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }
        }

        // search in second half
        else {

            lo = pivot;
            hi = n - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }
        }

        return -1;
    }
};