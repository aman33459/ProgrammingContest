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
bool prime(int n){
  for(int i = 2 ; i  <= sqrt(n);i++){
    if(n%i == 0) return false;
  }
  return true;
}
int fin(int x){
  for(int i = 2 ; i <=sqrt(x);i++){
    if(x%i == 0) return i;
  }
  return x;
}
vector < int > ans;
int a[100005];
void findiv(int n){
  //cout << n << "\n";
  for(int i = 2; i <=sqrt(n);i++){
    if(n%i == 0) {
     // cout << i << "  "<< n << " " << n/i << "**\n";
      if(a[i-1] < a[n-1]) ans[i] = max(ans[i] , ans[n]+1);
      if(a[(n/i)-1] < a[n-1]) ans[n/i] = max(ans[n/i] , ans[n]+1);
    }
  }
  if(a[0] < a[n-1]) ans[1]=max(ans[1],ans[n]+1);
}
int32_t main(){  
  int t;
  cin >> t;
  while(t--){
    ans.clear();
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i=0 ; i<=n ; i++) ans.push_back(0);
    for(int i = n-1 ; i>=0;i--){
        findiv(i+1);
    }
    int res=0;
    //for(auto i : ans ) cout << i << "+++\n";
    for(auto i : ans) res = max(res,i+1);
    cout << res << "\n"; 
    
   }
  return 0;
} 
