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
int ans=0;
void solve(int n , int val , int r , int x  , int y){
  //cout << n << " " << val << "++\n";
  if(val > r) return;
  if(n == -1) {
    int k = val&x;
    int kk = val&y;
    //cout << val << " " << k << " " << kk  << "+++\n";
    if(((val&x) !=0) && ((val&y)!=0)){
      if(ans==0) ans =val;
      else if(log(ans&x) + log(ans&y) < log(val&x) + log(val&y)) ans=val;
      else if(log(ans&x) + log(ans&y) == log(val&x) + log(val&y)){
       // cout << ans << " " << val << "++\n";
        if(ans > val) ans=val;
      }
    }
    return;
  }
  int m = val + (1LL<<n);
  solve(n-1,m,r , x,y);
  solve(n-1,val,r,x,y);
}
int32_t main(){  
  int a,b,c,k;
  int ans = 0;
  cin >> a >> b >> c >> k;
  ans+=min(a,k);
  k = k - min(a,k);
  k = k - min(b,k);
  ans-=min(c,k);
  cout << ans << "\n";
}
/*
10010
01011
11000

16+
*/

