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
      int cnt[1024]={0};
      vector < int  >a(n);
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        cnt[a[i]]++;
      }
      int ans = -1;
      for(int i = 1 ; i < 1024 ; i++){
        int tmp[1024]={0};
          for(int j =  0 ; j < n ;j++){
            //int am = a[j]^i;
            //cout << am << "++\n";
            tmp[a[j]^i]++;
          }
          int f =0 ;
          for(int j = 0; j < 1024;j++){
            if(cnt[j] != tmp[j]){
              f++;break;
            }
          }
          if(!f) {
            ans = i;
            break;
          }
      }
      cout << ans << "\n";
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
