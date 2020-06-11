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

int32_t main() 
{ 
  fast;
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector < vector < int > > a(n , vector < int > (m));
    for(int i = 0 ; i < n ;++i){
      for(int j = 0 ; j  < m ; j++) cin >> a[i][j];
    }
  vector < pair < int , int > > sd;
    for(int sum = 0 ; sum <= n+m-2; sum++ ){
      int zeros =0 , ones= 0;
      for(int i = 0 ; i < n ; i++){
          int j = sum - i;
          if(j < 0 || j >=m ) continue;
          if(a[i][j] == 0) zeros++;
          else ones++;
      }
      sd.push_back({zeros,ones});
    }
    int k = sd.size();
    int ans = 0;
    for(int i = 0 ; i < (((int)sd.size())/2) ; i++){
      ans += min(sd[i].first + sd[k-i-1].first , sd[i].second + sd[k-i-1].second);
    }
    cout << ans << "\n";
  }
  return 0;
} 
/*
*/
 
