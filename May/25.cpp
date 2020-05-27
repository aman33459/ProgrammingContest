class Solution {
public:
    int dp[5505];
    const int INF=1e9+7;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int ans = -INF;
        for(int i = 0 ; i < 1000 ; i++) dp[i] = -INF;
        for(int i = nums1.size()-1 ; i >=0 ;i-- ){
            for(int j = 0 ; j < nums2.size() ; j++){
                int ok = 0;
                for(int k = j+1 ; k < nums2.size(); k++ ){
                   if(dp[k] > 0) ok = max(ok,dp[k]);        
               // else ans= max(ans , d nums1[i]*nums2[j]);
                }
                //cout << ok << " " << nums1[i] << " " << nums2[j] << " " << ans << "++\n";
                ans= max(ans , ok+nums1[i]*nums2[j]);
                dp[j]=max(dp[j],ok+nums1[i]*nums2[j]);
            }
            
          // for(int j = 0 ; j < nums2.size() ; j++)  dp[j] = max(dp[j] , nums1[i] * nums2[j]);
        }
        return ans;
    }
};
