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
int gcd(int a , int b){
  if (b == 0) 
        return a; 
    return gcd(b, a % b);
}
int t[500005];
int nok=0;
vector<int>g[500005];
int visited[500005];
void dfs(int v){
  visited[v] =1;
  int ok  = 1;
  unordered_map < int , int > check;
  for(int u : g[v]){
    if(t[v] == t[u]) nok++;
    check[t[u]]++;
    while(check[ok]) ok++;
    if(visited[u]) continue;
    dfs(u);
  //  cout << nok << " " << u << "\n";
  }
  if(ok!=t[v]) nok++;
}
int32_t main()
{
  fast;
  int n,m;
  cin >> n >> m;
  for(int i = 0 ; i < n ;i++){ g[i].clear();visited[i]=0;}
  for(int i = 0 ; i < m ; i++) {
    int foo,bar;
    cin >> foo >> bar;
    foo--;
    bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
    //Write code here
  }
  for(int i = 0 ; i < n ; i++) cin >> t[i];
  for(int i = 0 ; i < n ; i++){
    if(visited[i] == 0){
      dfs(i);
    }
  }
  if(nok) cout << "-1\n";
  else{
  vector < pair < int , int > > sd;
  for(int i = 0 ; i < n ; i++) sd.push_back({t[i],i});
  sort(sd.begin(),sd.end());
  for(auto i : sd) cout << i.second+1 << " ";
    cout << "\n";
}
return 0;
}

/*

 0 0 1 4 5  5 5 
  2 2 10
  l..........r 
  ....... 
*/

