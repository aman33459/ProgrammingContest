bool cmp(pair < char , int > const& a , pair < char , int > const & b){
        if(a.second  > b.second) return true;
        else return false;
}
class Solution {
public:
    
    string frequencySort(string s) {
        vector < pair < char , int >  > sd;
        unordered_map < char , int > ss;
        for(auto i : s){
            ss[i]++;
        } 
        for(auto i : ss){
            sd.push_back({i.first , i.second});
        }
        sort(sd.begin(),sd.end(),cmp);
        string ans = "";
        for(auto i : sd)
        {
            for(int j = 0  ; j < i.second ; j++) ans += i.first;
        } 
        return ans;
    }
};
