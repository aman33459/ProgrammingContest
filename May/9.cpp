class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size() == 0 && N==1 ) return 1;
        map < int , int > sd,sk;
        for(auto i : trust){
            sd[i[1]]++;
            sk[i[0]]++;
        }
        int ans = 0;
        int res;
        for(auto i : sd){
            if(i.second == N-1 && sk[i.first] == 0){
                ans++;
                res = i.first;
            }
        }
        if(ans == 0) return -1;
        if(ans > 1) return -1;
        else return res;
    }
};
