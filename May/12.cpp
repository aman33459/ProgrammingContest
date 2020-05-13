class Solution {
public:
    string removeKdigits(string num, int k) {
        stack < char > s;
        s.push(num[0]);
        for(int i = 1 ; i < num.size();i++){
            while(s.size() > 0 && k > 0 && s.top() > num[i] ){ s.pop();k--;}
            s.push(num[i]);
        }
        string ans = "";
        while(k > 0) {
            k--;
            s.pop();
        }
        while(s.size() > 0){ ans = s.top()+ans;s.pop();}
        int kk = 0;
        for(auto i : ans) {
            if(i != '0') return ans.substr(kk,ans.size()-kk+1);
            kk++;
        }
        return "0";
    }
};
