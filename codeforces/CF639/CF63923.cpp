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
unordered_map < int , int > sd;
int32_t main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    sd.clear();
    int f=0;
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    for(int i = 0 ; i < n ; i++) a[i]=a[i]+i;
    for(int i = 0 ; i < n ; i++){
      a[i]=((a[i]%n)+n)%n;
      //cout << a[i] << " " << sd[a[i]] << "**\n";
      if(sd[a[i]]>0) {
        f=1;
        break;
      }
      sd[a[i]]++;
    }
    if(f) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}