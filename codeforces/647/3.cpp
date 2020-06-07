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
int ans;
int res[64];
int solve( int n){
  int ok;

  for(int i = 0 ; i <= 60; i++){
    int k = 1LL<<i;
    if(k-1>=n){
      //cout << i << "++\n";
      if(i-2 >= 0)ans +=res[i-2]+i;
      else ans+=i;
      ok=(1LL<<(i-1));
     // cout << ok << " " << n << "++\n";
      break;
    }

  }
  return n-ok;
}
int32_t main()
{
  fast;
    int t;
    cin >> t;
    res[0]=1;
    res[1] = 2+res[0]+res[0];
    int sum=res[1];
    for(int i = 2;i<=60;i++){
      res[i] = (i+1)+sum+ sum;
      sum=res[i];
    }
    ///for(int i = 0 ; i < 61;i++) cout << res[i] << "**\n";
    
    while(t--){
    int n;
      ans=0;
      cin >> n;
      while(n!=0){
        n=solve(n);
       //cout << n << " " << ans <<  "**\n";
      }
      cout << ans << "\n";
      //}*/
    }
    return 0;
    //Write code here
}

/*

 0 0 1 4 5  5 5 
  2 2 10
  l..........r 
  ....... 
*/

