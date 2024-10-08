class Solution {
public:
    /*
    int solve(vector<vector<int>>& matrix, int i, int j){
        int n = matrix.size();
        if(i >= n){
            return 0;
        }
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
        if(j-1 > -1){
            op1 = solve(matrix,i+1,j-1);
        } 
        op2 = solve(matrix,i+1,j);
        if(j+1 < n){
            op3 = solve(matrix,i+1,j+1);
        } 
        return matrix[i][j] + min(op1,min(op2,op3));
    }
    */
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        int n = matrix.size();
        if(i >= n){
            return 0;
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
        if(j-1 > -1){
            op1 = solve(matrix,i+1,j-1,dp);
        } 
        op2 = solve(matrix,i+1,j,dp);
        if(j+1 < n){
            op3 = solve(matrix,i+1,j+1,dp);
        } 
        return dp[i][j] = matrix[i][j] + min(op1,min(op2,op3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int j=0; j<n; j++){
            int temp = solve(matrix,0,j,dp);
            ans = min(ans,temp);
        }
        return ans;
    }
};