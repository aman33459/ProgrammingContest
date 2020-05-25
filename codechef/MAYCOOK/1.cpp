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
int msb(int n){
  int cn=0;
  while(n){
    n/=2;
    cn++;   
  }
  return cn;
}
int32_t main(){  
  int t;
  cin >> t;
 while(t--){
  int n;
  cin >> n;
  int k = msb(n);
  k--;
  int ans = 0;
  if((1LL<<k) +1 > n ) cout << "-1\n";
  else{
    int cnt = 0;
      for(int i = 30 ; i>=0 ; i--){
        int k = (1LL<<i);
        //cout << k << " " << cnt << " " << n/k << "++\n";
        ans+= k*((n/k)-cnt);
        cnt+=((n/k)-cnt);
      }
      cout << ans-1 << "\n";
  }
  }
  return 0;
} 
