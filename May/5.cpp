class Solution {
public:
    int firstUniqChar(string s) {
        map < char , int > sd;
        for(auto i : s) sd[i]++;
        for(int  i = 0 ; i < s.size() ;i++){
            if(sd[s[i]] == 1) return i;
        }
        return -1;
    }
};

