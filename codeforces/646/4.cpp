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
bool cmp(pair < int , int > a ,pair < int , int > b){
  if(a.first < b.first ) return true;
  else if(a.first == b.first) {
    if(a.second < b.second) return true;
    else return false;
  }
  else return false;
}
int a[200005];
int b[200005];
int c[200005];
pair < int , int > ok[200005];
vector < int > g[200005];
pair < int , int > dfs(int u , int pr){
  int no = 0 ,ne=0;
  if(b[u] !=c[u]){
    if(b[u] == 0){
        no++;
    }
    else{
      ne++;
    }
  }
  for(int v : g[u]){
    if(v == pr) continue;
    auto i = dfs(v,u);
    no+=i.first;
    ne+=i.second;
  }
  ok[u]={no,ne};
  return {no,ne};
}
int ans=0;
const int INF=1e9+7;
void dfs1(int u , int pr , int prev){
  auto i = ok[u];
  if(pr == -1){
    if(i.first == i.second ){
      ans = ans + (i.first+i.second)*a[u];
    }
  }
  else{
      if(a[u] < prev){
        int am = min(i.first , i.second);
        ans = ans + ((2*am)*a[u]) - ((2*am)*prev);
      }
  }
  int k = min(a[u],prev);
  for(int v : g[u]){
    if(v == pr) continue;
    dfs1(v,u ,k);
  }
}
int32_t main(){  
  fast;
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i++) g[i].clear();
  for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i] >> c[i];
  for(int i = 0 ; i < n-1 ;i++){
    int foo,bar;
    cin >> foo >> bar;
    foo--;
    bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  auto i = dfs(0,-1);
  if(i.first !=i.second) cout << "-1\n";
  else {
    dfs1(0,-1, LLONG_MAX);
    cout << ans << "\n";
  }
  return 0;
} 


/*


15 33


8.99 99
WB14D0028763
9990000000000000
9990000000000000
9990000000000000
9990000000000000

  4
3 5 7
1111
4 4 10
0110
4 3 4
1010
4 3 4
1100

111



3
3 5 4
101

2*k1 <=k2 
11111
8 10
11111 0 
5 5
111
k2 k2 k2 

10 12
126


3 

00001110000

000111000111
1111100
1110011

11101 10 01 00
0
k1 k1 k2 

*/
/*
1
[-5,3,-5],-3,1]

[-2,4,2,5,-5]
5
0 -1 2 -1 3
*/
