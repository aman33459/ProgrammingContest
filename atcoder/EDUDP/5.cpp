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
int dp[105][100005];
const int INF=1e9+7;
int32_t main(){  
  fast;
  int n,ww;
  cin >> n >> ww;
  vector < int > w(n) , v(n);
  for(int i  = 0 ; i < n ; i++) cin >> w[i] >> v[i];
    //cout << "ok\n";
  for(int i = 0 ; i < n ; i++){
    for(int j = 0; j < 100005; j++) dp[i][j]=INF;
  }
      dp[0][v[0]] = w[0];
      dp[0][0] = 0;
  //cout << "ok\n";
 for(int i = 1 ; i < n ; i++){
    for(int j = 0 ; j < 100005 ; j++){
        if(j>= v[i]){
            if(w[i] + dp[i-1][j-v[i]]  <= ww) dp[i][j] = min(dp[i-1][j] , dp[i-1][j-v[i]] + w[i]);
            else dp[i][j]= dp[i-1][j];
        }
        else dp[i][j] = dp[i-1][j];
    }
  }
  int ans = 0;
  for(int i = 0  ; i < n ; i++){
    for(int j = 0 ; j < 100005 ; j++){
      if(dp[i][j] !=INF) ans= max(ans,j);
    }
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

