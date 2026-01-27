class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Step 1: Make first column all 1s
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < cols; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Step 2: Flip columns if zeros > ones
        for (int j = 1; j < cols; j++) {
            int noz = 0;
            for (int i = 0; i < rows; i++) {
                if (grid[i][j] == 0) noz++;
            }

            if (noz > rows - noz) {
                for (int i = 0; i < rows; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Step 3: Calculate score
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            int value = 0;
            for (int j = 0; j < cols; j++) {
                value = value * 2 + grid[i][j];
            }
            sum += value;
        }

        return sum;
    }
};
