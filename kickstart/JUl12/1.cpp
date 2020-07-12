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
  int cnt = 0;
  cin >> t;
  while(t--){
    cnt++;
    cout << "Case #" << cnt << ": ";
    int n;
    cin >> n;
    vector < int > a(n),pre(n);
    for(int i = 0 ; i < n  ;i++) cin >> a[i];
      pre[0] = a[0];
    int now = -1;
    int ans = 0;
    for(int i = 1 ; i < n ; i++) pre[i] = max(a[i] , pre[i-1]);
    for(int i = n-1 ; i >=0 ; i--){
      //cout << a[i] << " " <<  now  << " " << pre[i-1]  << " ";
      if(i == 0 && a[i] > now) ans++;  
      if(i-1 >= 0 && a[i] > now && pre[i-1] < a[i]) ans++;
     now =a[i];
      //cout << ans << "++\n";
    }
    cout << ans << "\n";
  } 

  return 0; 
}

