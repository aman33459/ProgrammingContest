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
vector < int > g[123456];
int a[123456];
int decrease[123456],increase[123456];
int l;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
int depth[123456];
void dfs(int u , int pr){
    if(pr >= 0) depth[u] = depth[pr]+1;
    else depth[u] = 0;
    tin[u] = ++timer;
    if(pr >= 0 )up[u][0] = pr;
    else up[u][0] = u;
    for (int i = 1; i <= l; ++i)
        up[u][i] = up[up[u][i-1]][i-1];
  if(pr >= 0){
    if(a[u] < a[pr] )
    {
      increase[u]=increase[pr];
      decrease[u]=u;
    }
    else if(a[u] > a[pr])
    {
      decrease[u] = decrease[pr];
      increase[u]=u;
    }
    else {
      increase[u]=u;
      decrease[u]=u;
    }
  }
  else increase[u]=decrease[u]=u;
  for(auto v : g[u]){
    if( v== pr) continue;
    dfs(v,u);
  }
  tout[u] = ++timer;
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int32_t main(){  
  int t;
  fast;
  cin >> t;

 while(t--){
  int n,q;
  cin >> n >> q;
  for(int i = 0 ; i < n ; i++) g[i].clear();
  for(int i = 0 ; i < n -1 ; i++){
    int foo,bar;
    cin >> foo >> bar;
    foo--;
    bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
   l = ceil(log2(n));
  up.clear();
   up.assign(n, vector<int>(l + 1));
   tin.clear();
   tout.clear();

   tin.resize(n);
    tout.resize(n);
    timer = 0;
  for(int i = 0 ; i < n ; i++) cin >> a[i];
  dfs(0,-1);
  string ans = "";
  while(q--){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    int lc = lca(x,y);
    int ok = increase[x];
    int ok1 = decrease[x];
    int f=0;
    if(is_ancestor(ok1,lc)){
      int k = increase[y];
      if(is_ancestor(k,lc)) f++;
    }
    if(is_ancestor(ok ,lc)){
    int am = increase[y];
    int k = decrease[am];
    int sa = decrease[y];
    if(is_ancestor(am ,lc) || is_ancestor(k ,lc) || is_ancestor(sa,lc)) f++;
    }
    else{
      //int am = decrease[y];
      int ama = decrease[ok];
      int sa = increase[y];
      if(is_ancestor(ama ,lc) &&is_ancestor(sa,lc)) f++;
    }  
    if(f) ans+='1';
    else ans+='0';
    //cout << ok << " " << depth[ok] << " " << depth[lc] << "++\n"; 
    
  }
  cout << ans << "\n";
 }
  return 0;
} 
