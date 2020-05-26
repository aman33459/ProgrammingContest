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
bool cmp(pair < int , string >   a , pair < int , string >   b){
  if(a.first < b.first ) return true;
  else return false;
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int dp[3005][3005];
pair < int , int  >  point[3005][3005];
int pos[3005][3005];
int32_t main(){  
  fast;
  string s,t;
  cin >> s >> t;
  for(int i = 0 ; i <= s.size();i++){
    for(int j = 0 ; j<=t.size();j++) pos[i][j]=-1;
  }
  for(int i = 1 ; i <=  s.size() ; i++){
    for(int j = 1 ; j <= t.size() ; j++){
      if(s[i-1] == t[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];
        pos[i][j] = i;
        point[i][j] = {i-1,j-1}; 
      }
      else{
       dp[i][j] = max(dp[i-1][j] , dp[i][j-1]); 
        if(dp[i-1][j] > dp[i][j-1]) {
            point[i][j] = {i-1,j};
        }
        else{
          point[i][j] = {i,j-1};
        }
    }
  }
}
  int i  = s.size();
  int j = t.size();
  string ans = "";
  while(i>=1 && j>=1){
    if(pos[i][j] !=-1) ans = s[i-1]+ans;
    auto tmp = point[i][j];
    i = tmp.first;
    j = tmp.second; 
  }
  cout << ans << "\n";
  return 0;
} 

/*
1 -- 0
2 -- 

...
30 -- 3
..
49- --3
50 -- 4
60 -- 5
--
69 - 
70 -- 

subset sum = 100
100
100 - 

x  <=ww

*/

