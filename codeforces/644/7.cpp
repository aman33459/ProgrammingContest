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
const int mod=998244353;
int fac[200005];
void calfac(){
  fac[0]=1;
  fac[1]=1;
  for(int i = 2 ; i < 200005;i++) fac[i]= (fac[i-1]*i)%mod;
}
int inv(int a){
  return binpow(a , mod-2,mod);
}
int comin(int n , int r){
  return (fac[n] * ((inv(fac[r]) * inv(fac[n-r]))%mod))%mod;
}
bool ho;
int cal(int i , int r , int x , int y , int l ){
  int ans = 0;
  for(int ok = 62 ; ok >= 0 ; ok--){
    if(ok < i){
      //if(((r&(1LL<<i)) > 0) && ((l&(1LL<<i)) == 0)) ho = true;

      if(ho) ans = ans + ((x&(1LL<<ok)) | (y&(1LL<<ok)));
      else{
        if(((l&(1LL<<ok)) > 0)) ans = ans + ((l&(1LL<<ok)));
        else{
          ans = ans + ((x&(1LL<<ok)) | (y&(1LL<<ok)));
          if((((x&(1LL<<ok)) | (y&(1LL<<ok)))) > 0 ) ho = true;
        }
      }
    } 
    else if(ok > i){
      ans = ans + (r&(1LL<<ok));
      if(((r&(1LL<<ok)) > 0) && ((l&(1LL<<ok)) == 0)) ho = true;
    } 
    else if(!ho){ ans = ans + (l&(1LL<<ok)); i =-1;}
   // cout << ans << "++\n";
  }
  return ans;
}
bool fun(int tmp , int ans , int x , int y){
  if(((tmp&x) * (tmp&y)) >= ((ans&x) * (ans&y))) return true;
  else return false;
}
vector < string > ans;
int32_t main(){  
  int t;
  cin >> t;
  while(t--){
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    ans.clear();
    int j = 0;
    int f=1;
    for(int i = 0 ; i < n ;i++){
      string tmp="";
      for(int j = 0 ; j < m ; j++) tmp=tmp+'0';
        ans.push_back(tmp);
    }
    //for(auto i : ans) cout << i << "\n";
    int cnt=0;
    j=0;
    for(int i = 0 ; i < m ; i++){
      cnt=0;
      while(cnt <b){
        //cout << j << " " << i << "++\n";
        ans[j][i] = '1';
        j++;
        cnt++;
        if(j>=n) {
        //  f=0;
          j=0;
        }
      }
    }
    int no=0;
    for(int i= 0 ; i < n ;i++){
      int cn=0;
      for(int j = 0 ; j < m ;j++){
        if(ans[i][j] == '1') cn++;
      }
      if(cn != a) no++;
    }
    if(no) cout << "NO\n";
    else {
      cout<<"YES\n";
      for(int i = 0 ; i < n ;i++){
      for(int j = 0 ; j < m ; j++) cout << ans[i][j];
        cout << "\n";
    }
  }
  }
  return 0;
} 
