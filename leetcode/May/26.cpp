class Solution {
public:
    vector<int> countBits(int num) {
        vector < int > dp(num+1,0);
        long long  next = 2;
        long long curr =1 ;
        dp[0] = 0;
        if(num == 0) return {0};
        dp[1] = 1;
        for(int i = 2 ; i <=num; i++ ) {
            if(i == next){ dp[i] = 1+dp[i-next];
                         curr = next;
                          next = next*2LL;
                         }
        else{
            dp[i] = 1+dp[i-curr];
        }
        }
        return dp;
    }
};
