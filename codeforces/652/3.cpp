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
bool prime(int n){
  for(int i =2 ; i <=sqrt(n) ; i++){
    if(n%i == 0) return false;
  }
  return true;
}
int32_t main() 
{ 
  fast;
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    vector <int > a(n);
    vector < int > b(k);
    for(int i = 0 ; i < n ; i++) cin >> a[i]; 
    for(int i = 0 ; i < k ; i++) cin >> b[i];
    sort(a.begin() , a.end());
    sort(b.begin(),b.end());
    reverse(a.begin() , a.end());
    int ans = 0;
    int j = k-1;
    int ok = 0;
    for(int i = 0 ; i < b.size() ; i++) ans = ans + a[i];
   // cout << ans << "++\n";
    for(int  i = 0 ; i < k ; i++){
        if(b[i] == 1){
          ans = ans + a[ok];
          //cout << a[ok] << "***\n";
          ok++;
        }
        else {
          ans = ans + a[j+(b[i]-1)];
          //cout << a[j+(b[i]-1)] << "***+++\n";
          j = j + b[i]-1;
        }
    }
    cout << ans << "\n";

  }
  return 0; 
}

