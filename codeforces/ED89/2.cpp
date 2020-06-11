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
    int n,x,m;
    cin >> n >> x >> m;
    x--;
    int l =-1;
    int r=-1;
    int f=0;
    for(int i = 0 ; i < m ; i++){
        int c,d;
        cin >> c >> d;
        c--;
        d--;
        if(f == 0 && c<=x && x<= d) {
          f=1;
          l = c;
          r = d;
        }
        else if(f == 1){
            if(d< l || r<c) continue;
            else{
              l=min(l,c);
              r = max(r,d);
            }
        }

    }
    if(l==-1) cout << "1\n";
    else cout << (r-l+1) << "\n";
  }
  return 0;
} 
/*
*/
 
