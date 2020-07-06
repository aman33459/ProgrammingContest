class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map < char , int > sd;
        for(auto i : magazine) sd[i]++;
        for(auto i: ransomNote){
            if(sd[i] == 0) return false;
            else sd[i]--;
        }
        return true;
    }
};
