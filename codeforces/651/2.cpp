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
    int n;
    cin >> n;
    vector < int > a(2*n);
    int prevo = -1 , preve = -1;
    int cnt = 0;
    int cn = 0;
    vector < pair < int , int > > ans;
    for(int i = 0 ; i < 2*n ; i++) cin >> a[i];
    for(int cnt = 0 ; cnt < 2*n ; cnt++){
      int i = a[cnt];
      if(i%2) {
        if(prevo == -1) prevo=cnt;
        else {
          ans.push_back({prevo+1 , cnt+1});
          prevo=-1;
        }
      }
      else{
        if(preve == -1) preve=cnt;
        else {

          ans.push_back({preve+1 , cnt+1});
          preve=-1;
        }
      }
      //cout << preve << " " << prevo << " " << cnt << "**\n";
     }
     for(int i = 0 ; i < n-1 ; i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
     }
  }
  return 0; 
}

