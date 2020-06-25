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
  while(t--){
    int n;
    cin >> n;
    int sum = 0;
    int max_so_far = 0;
    std::vector< int > a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n-1 ; i+=2){
      sum = sum + (a[i+1] - a[i]);
      if(sum < 0) sum = 0;
      max_so_far = max(max_so_far , sum);
      //cout << sum << "++\n";
    } 
    sum = 0;

   // cout << max_so_far << "***\n";
    for(int i = 1 ; i < n -1 ; i+=2){
      sum = sum  + (a[i] - a[i+1]);
      if(sum < 0) sum = 0;
      max_so_far = max(max_so_far , sum);
    }
    //cout << max_so_far << "\n";
    int ans = 0;
    for(int i = 0 ; i < n ; i+=2) ans = ans + a[i];
    cout << ans + max_so_far << "\n";
  }
  return 0; 
}
