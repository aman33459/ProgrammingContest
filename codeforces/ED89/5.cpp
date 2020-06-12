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
const int mod= 998244353;
vector < pair < int , int > > sd;
bool cmp(pair < int , int > const & a , pair < int , int > const &b){
  if(a.first < b.first) return true;
  else if(a.first == b.first){
    if(a.second < b.second) return true;
    else return false;
  }
  else return false;
}
int search(int val){
  int low =0;
  int ans = -1;
  int high = sd.size()-1;
  while(low<=high){
    int mid = (low+high)/2;
    if(sd[mid].first <  val) {
      low = mid+1;
      ans = sd[mid].second;
    } 
    else high = mid-1;
  }
  return ans;
}
int32_t main() 
{ 
  fast;
  int n,m;
  cin >> n >> m;
  vector < int > a(n),b(m);
  for(int i = 0 ; i < n ; i++) cin >> a[i];
  for(int i = 0 ; i < m ; i++) cin >> b[i];
  for(int i =0 ; i < n ; i++){
    sd.push_back({a[i],i});
  }
  int ans = 1;
  int prev = 0;
  if(m==1){
      for(int i = 0 ; i < n ; i++){
        if(a[i] < b[0]) {
          ans = 0;
          break;
        }
      }
      int ok=-1;
      for(int i = 0 ; i < n ; i++){
        if(a[i] == b[0]) {
          ok++;
        }
      }
      if(ok==-1) ans= 0;
  }
  else{
  sort(sd.begin(),sd.end(),cmp);
  for(int i = 1 ; i < sd.size() ; i++){
    sd[i].second = max(sd[i].second , sd[i-1].second);
  }
  for(int i = 1 ; i < m ;i++){
    int k = search(b[i]);
    if(k == -1){
      ans = 0;
      break;
    }
   // cout << k << "++\n";
    for(int j  = prev ; j <=k ; j++){
      if(a[j] < b[i-1]) {
        ans = 0;
        break;
      }
    }
      int ok=-1;
      //cout << prev << " " << k << "++\n";
      for(int j = prev ; j <=k ; j++){
       // cout << a[j] << " " << b[i-1] << "**\n";
        if(a[j] == b[i-1]) {
          ok = j;
        }
      }
      if(ok == -1) {
        ans = 0;
        break;
      }
      if(i!=1) ans = (ans * (ok - prev+1))%mod;
    
    prev = k+1;
   // cout << ans << "**\n";
  }
    int ok=-1;
      for(int j = prev ; j < n ; j++){
        if(a[j] == b[m-1]) {
          ok = j;
        }
      }
      if(ok == -1) {
        ans = 0;
        
      }
      ans = (ans * (ok - prev+1))%mod;
    
   }
  cout << ans << "\n";
  return 0;
} 
/*

   
12 10 20 20 10  ....  |  ... 20 20 ..  .. |  |  25 30 | 
10 20 30

*/
 
