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
    int n , m ,a,b;
    cin >> a >> b >>  n >>m;
    int k1 = max(a,b);
    int k2 = min(a,b);
    if(n+m > a+b){
      cout << "NO\n";
    }
    else{
      int diff = k1-k2;
      n= n - min(n,diff);
      if(n == 0 && k2 >= m ) cout << "YES\n";
      else if(n==0 && k2 < m) cout << "NO\n";
      else{
        int x =  min(n,m);
        if(x > k2) cout << "NO\n";
        else {
          k2-=x;
          n-=x;
          m-=x;
          if(m > 0 && k2 >= m) cout << "YES\n";
          else if(m > 0 && k2 < m ) cout << "NO\n";
         else if(n > 0 && 2*k2 >= n) cout << "YES\n";
          else if(n > 0 && 2*k2 < n ) cout << "NO\n";
          else cout << "YES\n";
        }
      } 


    }
    //cout << "**\n";
  }
  return 0; 
}

