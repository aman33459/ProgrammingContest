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
const int mod=998244353;
int fac[200005];
void calfac(){
  fac[0]=1;
  fac[1]=1;
  for(int i = 2 ; i < 200005;i++) fac[i]= (fac[i-1]*i)%mod;
}
int inv(int a){
  return binpow(a , mod-2,mod);
}
int comin(int n , int r){
  return (fac[n] * ((inv(fac[r]) * inv(fac[n-r]))%mod))%mod;
}
int32_t main(){  
  int n,m,k;
  cin >> n >> m >> k;
  calfac();
  int ans = 0;
  for(int i = 0 ; i <=k ; i++){
   // cout << ans << " " << comin(n-1,i) << " " << m << " " <<  comin(n-1,i) * m << " " << binpow(m-1,n-1-i  , mod) << " " <<  (((comin(n-1,i) * m)%mod) * binpow(m-1,n-1-i  , mod))%mod << "\n";
      ans = (ans + (((comin(n-1,i) * m)%mod) * binpow(m-1,n-1-i  , mod))%mod)%mod;
  }
  cout << ans << "\n";
  return 0;
} 
/*
10010
01011
11000

16+
*/

