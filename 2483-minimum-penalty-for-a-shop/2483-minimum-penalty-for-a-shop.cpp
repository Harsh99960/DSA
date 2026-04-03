class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        for(char c : customers){
            if(c == 'Y') totalY++;
        }

        int leftN = 0;   // left side me N
        int leftY = 0;   // left side me Y

        int minPenalty = INT_MAX;
        int answer = 0;

         
        for(int i = 0; i <= n; i++){
            int rightY = totalY - leftY;
            int penalty = leftN + rightY;
            if(penalty < minPenalty){
                minPenalty = penalty;
                answer = i;
            }
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