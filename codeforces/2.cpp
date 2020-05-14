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
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int min(int a , int b){
  if(a < b) return a;
  else return b;
}

int32_t main(){  
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    vector < int > a(n);
    vector < int > b(n);
    //cout << k << "++\n";
    
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++) cin >> b[i];
     // cout << k << "++\n";
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    //cout << k << "++\n";
    
    int as = 0;
    //cout << k << "++\n";
    
    for(int i = 0 ; i < k ; i++){
    //  cout << as << " " << a[as] << " " << b[as] << "\n";
      if(a[as] < b[as]) a[as]=b[as]; 
      else break;
      as++;
    }
    int ans = 0;
    for(auto i : a) ans+=i;
    cout << ans << "\n";
  }
  return 0;
} 
