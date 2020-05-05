class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map < char , int > sd;
        int ans=0;
        for(auto i : J) sd[i]++;
        for(auto i : S){
            if(sd[i] >  0) ans++;
        }
        return ans;
    }
};
