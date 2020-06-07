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
    vector < int > pow;
    pow.push_back(1);
    pow.push_back(2);
    for(int i = 2 ; i <=60 ;i++){
      pow.push_back(2*pow[i-1]);
    }
    while(t--){
      int a , b;
      int ans = 0;
      cin >> a >> b;
      int k = gcd(a,b);
      if(k !=a && k !=b) cout << "-1\n";
      else{
        if(k == a) k = b/k;
        else k = a/k;
      while(k%8 == 0) {
        k=k/8;
        ans++;
      }  
      while(k%4 == 0) {
        k = k /4;
        ans++;
      }
      while(k%2 == 0){
        k = k /2;
        ans++;
      }
      if(k == 1) cout << ans << "\n";
      else cout << "-1\n";
    }}
    
    return 0;
    //Write code here
}

/*

 0 0 1 4 5  5 5 
  2 2 10
  l..........r 
  ....... 
*/

