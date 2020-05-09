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
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    string ans = "";
    int f=1;
    if(n2 > 0) ans = ans + "10";
    for(int i = 0 ; i < n2-1;i++){
      if(f == 1) ans = ans +'1';
      else ans = ans + '0';
      f=f^1;
    }
    if(ans.size() == 0){
      if(n1>0 && n3 > 0) cout << "-1\n";
      else{
        if(n1 > 0) for(int i = 0 ; i <=n1 ; i++) cout << "0";
        else for(int i = 0 ; i <=n3; i++) cout << "1";
      }
    }
    else if(ans.back() == '0'){
          for(int i = 0 ; i < n3 ; i++) ans = '1'+ans;
          for(int i = 0 ; i < n1 ; i++) ans = ans + '0';
          //for(int )
    }
    else{
      int m = ans.size();
      string res = "";
      for(int i = 0 ; i < m-1; i++) res = res + ans[i];
      for(int i = 0 ; i < n1 ; i++) res = res + '0';
      res= res + '1';
      ans = res;
      for(int i = 0 ; i < n3 ; i++) ans = ans + '1';
    }
  cout << ans << "\n";
  }
  return 0;
}

/*
1111110100
*/
