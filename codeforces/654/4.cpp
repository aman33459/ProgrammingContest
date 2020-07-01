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
int a[1005][1005];
int32_t main() 
{ 
  fast;
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++) a[i][j]=0;
    }
    int x = k/n;
    int j = 0;
    int ans = x;
    int res=x;
    if(k%n !=0){ res++;}
    int extra = (k-(n*x));
    ans = 2*((res-ans)*(res-ans));
    //cout << x << "++\n"; 
    //cout << extra  << "++\n";
    for(int i = 0 ; i < n ; i++){
      int cnt = 0;
      while(cnt < x){
      a[i][j] = 1;
      j++;
      j= (j %n);
      cnt++;
      //k--;
      }
      if(extra){
      a[i][j] = 1;
      j++;
      j= (j %n);
      extra--;
      }
    }
    cout << ans << "\n";
    for(int i = 0 ; i < n ; i++) {
      for(int j = 0 ; j < n ; j++) cout << a[i][j];
        cout << "\n";
    }
     
  }
  return 0; 
}
