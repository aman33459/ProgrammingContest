#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
int max(int a , int  b){
  if(a > b) return a;
  else return b;

}
int min(int a , int b){
  if(a < b) return a;
  else return b;
}
int32_t main(){  
  int t;
  cin >> t;
  while(t--){
      int n;
      cin >> n;
      int cn=0;
      int tmp = n;
      vector < int > s;
      while(n)
      {
        s.push_back(n%10);
        cn++;
        n/=10;
      }
      //for(auto i : s) cout << i << "**\n";
      cn--;
     // cout << cn << "**\n";
      vector 
      < int > ans;
      reverse(s.begin(),s.end());
      int k = 0;
      while(cn >= 0 ){
          int ok=1;
      for(int i   = 1; i <=cn;i++) {
        ok=ok*10;
      }
      //cout << cn <<  " " << s[k] << " " << "---\n";
      if(s[k]*ok != 0)ans.push_back(s[k]*ok);
        cn--;  
        k++;
      }
      cout << ans.size() << "\n";
      for(auto i : ans) cout << i << " ";
        cout << "\n";
  }
  return 0;
}