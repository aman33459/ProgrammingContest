class Solution {
public:
    vector<int> findAnagrams(string s, string p) {    
        sort(p.begin() , p.end());
        map < int , int > cnt;
        for(auto i :  p) cnt[i-'a']++;
        vector < int > ans;
        string a = s.substr(0,p.size());
        for(auto i : a) {
            cnt[i-'a']--;
        }
        int last = 0;
        int f=0;
            for(int i = 0 ; i < 26 ; i++){
                if(cnt[i]!=0) {
                    f=1;
                    break;
                }
            }
        if(!f) ans.push_back(0);
        for (int i = i+p.size() ; i < s.size(); i++) 
        {
            cnt[s[last] -'a']++;
            cnt[s[i] -'a']--;
            int f=0;
            for(int i = 0 ; i < 26 ; i++){
                if(cnt[i]!=0) {
                    f=1;
                    break;
                }
            }
            if(!f) ans.push_back(last+1);
            last++;
        } 
        return ans;
    }
};
