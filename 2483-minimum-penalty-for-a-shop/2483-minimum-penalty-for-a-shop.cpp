class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // STEP 1: total Y count karo
        int totalY = 0;
        for(char c : customers){
            if(c == 'Y') totalY++;
        }

        int leftN = 0;   // left side me N
        int leftY = 0;   // left side me Y

        int minPenalty = INT_MAX;
        int answer = 0;

        // STEP 2: har closing time try karo
        for(int i = 0; i <= n; i++){

            // STEP 3: right side Y nikaalo
            int rightY = totalY - leftY;

            // STEP 4: penalty calculate
            int penalty = leftN + rightY;

            // STEP 5: minimum track karo
            if(penalty < minPenalty){
                minPenalty = penalty;
                answer = i;
            }

            // STEP 6: next iteration ke liye update
            if(i < n){
                if(customers[i] == 'Y'){
                    leftY++;
                } else {
                    leftN++;
                }
            }
        }

        return answer;
    }
};