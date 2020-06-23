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
int gcd(int a , int b){
  if (b == 0) 
        return a; 
    return gcd(b, a % b);
}
const int mod = 1e9+7;
int dp[2000005];
int ans[2000005];
int32_t main() 
{ 
  fast;
  int t;
  cin >> t;
  dp[1]=0;
  dp[2] = 0;
  dp[3] = 1;

  ans[1]=0;
  ans[2] = 0;
  ans[3] = 1;
  int one = 1;
  int zeros = 3;
  for(int i = 4 ; i <=2000000 ; i++){
    dp[i] = (dp[i-1]+one)%mod;
    ans[i] = one + ans[i-3];
    int tmp = zeros;
    zeros = (zeros + one*2)%mod;
    one = tmp % mod;
    //cout << ans[i] << " " << dp[i] << "\n";
    //cout << dp[i] << " " << one << " " << zeros << "++\n";
  }

  while(t--){
    int n;
    cin >> n;
    int res  =(4*ans[n])%mod;
    cout << res<< "\n";
  }
  return 0; 
}

