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
    ans.clear();
    cin >> n;
    if(n%2){
    for(int  i = n ; i >=1 ; i=i-2) {
      ans.push_back(i);
    }
  }
  else{
    for(int  i = n-1 ; i >=1 ; i=i-2) {
      ans.push_back(i);
    } 
  }
    if(ans.size() == 0) cout << "-1\n";
    else if(ans.back() + 3 > n) cout << "-1\n";
    else{
      ans.push_back(ans.back()+3);
      ans.push_back(ans.back()-2);
      for(int i = ans.back()+4; i <= n  ; i=i+2) ans.push_back(i);
      for(auto i :ans)  cout << i << " ";
        cout << "\n";
    }
  }
  return 0;
}