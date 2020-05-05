class Solution {
public:
    int findComplement(int num) {
        int ans= 0;
        string s = "";
        while(num){
            int a = num%2;
            s = s + char(a+'0');
            num = num/2;
        }
        //cout << s << "\n";
      for(int i = 0 ; i < s.size() ; i++ ){
          int k = s[i]-'0';
          ans = ans + (1<<i)*(k^1);
      }
        return ans;
    }
};
