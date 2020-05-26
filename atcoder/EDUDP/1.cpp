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
int32_t main(){  
  fast;
  int n;
  cin >> n;
  vector < int > h(n);
  for(int i = 0 ; i < n ; i++) cin >> h[i];
  vector < int > dp(n,0);
  dp[1] = abs(h[1]-h[0]);
  for(int i = 2; i < n; i++ ){
    dp[i] = min(dp[i-2]+abs(h[i-2] - h[i]) , dp[i-1]+abs(h[i-1]-h[i])); 
  }
  //for(int i = 0 ; i < n ; i++) cout << dp[i] << "**\n";
  cout << dp[n-1] << "\n";
  return 0;
} 

