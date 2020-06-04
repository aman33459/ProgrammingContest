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
bool cmp(pair < int , string >   a , pair < int , string >   b){
  if(a.first < b.first ) return true;
  else return false;
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
map < pair < int, int > , int  > sd;
int32_t main(){  
  fast;
  int t;
  cin >> t;
  while(t--){
      int n,m,x,y;
      sd.clear();
      cin >> n >> m >> x >> y;
      vector < string > s(n);
      int ans = 0;
      for(int i = 0 ; i < n ; i++) cin >> s[i];
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ;j++) {

          if(s[i][j] == '.') ans = ans + x;
          if(s[i][j] == '.' && j-1 >=0 && s[i][j-1] == '.' && 2*x > y  && sd[{i,j-1}] == 0){
            ans = ans +y - 2*x;
            sd[{i,j}]=1;
          }  
        }
      }
      cout << ans << "\n";  
    }
  
  return 0;
} 

/*
[-5,3,-5],-3,1]

[-2,4,2,5,-5]

*/
