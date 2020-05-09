#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
//#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
/*
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
}*/
vector < int > ans;
int32_t main(){
  fast;  
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector < int  > a(n);
    unordered_map < int , int > ans;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++){
      int s = a[i];
      for(int j = i+1 ; j < n ; j++){
        s = s+a[j];
        if(s > n) break;
        ans[s]++;
      }
    }
    int res=0;
    for(int i  = 0 ; i < n ; i++) {
      if(ans[a[i]]) res++;
    }
    cout << res<<"\n";
   }
  return 0;
}

/*
1111110100
*/

