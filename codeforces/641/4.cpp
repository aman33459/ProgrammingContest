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
int a[100005];
int32_t main(){  
  int t;
  cin >> t;
  while(t--){
      int n,k;
      cin >> n >> k;
      //vector < int > pos;
      for(int i = 0 ; i < n ; i++) cin >> a[i];
      int ans = 0;
      int f=0;
      bool ok=false;
      if(n == 1 && a[0] == k) cout << "yes\n";
      else if(n==1 && a[0]!=k) cout << "no\n";
      else{
      for(int i = 0 ; i < n ; i++) {
        //cout << f << " " << ans << " " << a[i] << "++\n";
        if(a[i] < k) ans--;
        else if(a[i] >= k){
          //cout << ans << "\n";
          if(a[i] == k ) f=1;
            if(ans < 0) {ans =1;}
            else{
              if(i > 0) ok=true;
               ans++;
            }
        } 

      }
      if(!ok || f==0) cout << "no\n";
      else cout << "yes\n";
    }   
  }
  return 0;
} 
