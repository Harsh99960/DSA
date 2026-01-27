class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n= matrix.size();
        //transpose krna hai 
        for(int i =0; i<n;i++){
            for (int j=i+1;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }

        //reverse ka function likhna hoga 
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};