class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum =0;
        map < int , int > sd;
        sd[0] = 0;
        int cnt = 1;
        int ans = 0;
        for(auto i : nums){
            if(i == 0) sum--;
            else sum++;
            if(sd.find(sum) !=sd.end()) {
                ans = max(ans  ,cnt - sd[sum]);
            }
            else sd[sum] = cnt;
            cnt++;
        }
        return ans;
    }
};
