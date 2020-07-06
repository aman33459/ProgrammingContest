class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector < int > dp(m+1,0);
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = 0 ; j < m ; j++){
                if(A[i] == B[j]){
                    dp[j]=1;
                    for(int k = j+1 ; k< m ;k++) dp[j]=max(dp[j] , 1+dp[k]);
                }
            }
        }
        int ans =0 ;
        for(int i = 0 ;  i < m ;i++) ans=max(ans,dp[i]);
        return ans;
    }
};
