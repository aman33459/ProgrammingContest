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
int a[200005];
map < int , int > sd;
map < int , int > ok;
int32_t main(){  
  int n,k;
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++) cin >> a[i];
  for(int i = 0 ; i < n ; ++i) a[i]--;
  int i = 0 ;
  int ans = -1;
  int cn=0;
  int last;
  while(sd[i] == 0){
      sd[i]++;
      ok[i]=cn;
      if(cn == k) ans = i;
      i = a[i];
      cn++;
      last =i;
      //cout << i << " " << last << "++\n";
      
  }
  //cout << last << "\n";
  if(ans !=-1) cout << ans+1 << "\n";
  else{
      sd.clear();
      i = last;
      cn=0;
      while(sd[i] == 0){
        sd[i]++;
        i = a[i];
        cn++;
      }
      k = k - ok[last];
      int m  = k /cn;
      k = k - m*cn;
      sd.clear();
      i = last;
      cn = 0;
      while(sd[i] == 0){
        sd[i]++;
        if(cn == k) break;
        i = a[i];
        cn++; 
      }
      cout << i+1 << "\n";
  }
  return 0;
} 
/*
10010
01011
11000

16+
*/

