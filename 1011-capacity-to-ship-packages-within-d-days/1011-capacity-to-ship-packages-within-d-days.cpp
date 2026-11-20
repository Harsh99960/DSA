
class Solution {
public:

    int findMax(vector<int>& weights) {
        int maxi = INT_MIN;

        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
        }

        return maxi;
    }

    int findSum(vector<int>& weights) {
        int totalSum = 0;

        for (int i = 0; i < weights.size(); i++) {
            totalSum += weights[i];
        }

        return totalSum;
    }

    bool possible(vector<int>& weights, int capacity, int days) {
        int load = 0;
        int cntDays = 1;

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > capacity) {
                cntDays++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }

        return cntDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = findMax(weights);
        int high = findSum(weights);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(weights, mid, days)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
