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

int a[500005];
int suff[500005];
int ans[500005];
int search(int need , int high , int remove){
  int low = 0;
  int ans;
  while(low<=high){
    int mid = (low+high)/2;
    if(suff[mid] - remove >= need ) {
      ans = mid;
      low = mid+1;
    }
    else high = mid-1;
  }
  return ans;
}
int cal(int x){
  return (x*(x+1))/2;
}
int32_t main(){  
  fast;
  int n,x;
  cin >> n >> x;

  //cout << "ok\n";
  for(int i = 0 ; i < n ;i++) cin >> a[i]; 
  for(int i=n ; i < 2*n ; i++) a[i] = a[i-n];
  suff[2*n-1] = a[2*n-1];
  ans[2*n] = 0;
  ans[2*n-1] = cal(a[2*n-1]);
  for(int i = 2*n-2 ; i>=0 ; i--) suff[i] = suff[i+1]+a[i];
  for(int i = 2*n-2 ; i>=0 ; i--) ans[i] = ans[i+1]+cal(a[i]);  
  int sum = 0;
  int res = 0;
  for(int i = 0 ; i < 2*n ; i++){
    //cout << a[i] << " " << sum << "++\n";
    if(a[i] + sum >= x){
        int need = x-(a[i]);
       // cout << need  << "++\n";
        if(need > 0){
          int k = search(need , i-1 , suff[i]);
         // cout << i << " " <<  suff[k] << " "  << suff[i] << " " << need << " " <<  ans[k] - ans[i] << "--\n";
          if(suff[k] - suff[i] > need) {
              int m = need - (suff[k+1] - suff[i]);
              res= max(res , ans[k+1]- ans[i+1] + cal(a[k])-cal(a[k]-m));
          }
          else res = max(res , ans[k] - ans[i+1]);
        } 
      else if(need == 0){
          res = max(res , cal(a[i]));
      }
      else{
          res=max(res , cal(a[i]) - cal(a[i]-x));
      }
    }
    //cout << i << " " << res << "++\n";
    sum+=a[i];
  }
  cout << res << "\n";
  return 0;
} 

