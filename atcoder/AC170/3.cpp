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
inline int max(int a , int  b){
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
  int x,n;
  map < int , int > sd;
  cin >> x >> n;
  for(int i = 0 ; i < n ; i++) {
    int tmp;
    cin >> tmp;
    sd[tmp]++;
  }
  int ans = LLONG_MAX;
  int res;
  for(int i = -100 ; i < 200 ; i++){
    if(sd[i] == 0 && abs(x-i) < ans ){
        ans = abs(x-i);
        res= i;
    } 
  }
  cout << res << "\n";
}

// 2*a + 4*b = Y
// a+b = X
// a = x-b
// 2x - 2b + 4b = y
// 2x +2b = y
//(y/2)-x;

