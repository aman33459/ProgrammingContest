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
vector < string > sd;
int visited[105];bool visited1[105];
vector < int > g[1005];
bool check;
int color[105];
void dfs(int u){
  visited[u] = 1;
  color[u]=1;
  for(auto v : g[u]){
    if(color[v] == 1) check=true;
    if(visited[v]) continue;
    dfs(v);
  }
  color[u]=2;
}
vector < int > ans;
void dfs1(int v) {
    visited1[v] = true;
    for (int u : g[v]) {
        if (!visited1[u])
            dfs(u);
    }
    ans.push_back(v);
}
int32_t main(){  
  int t;
  cin >> t;
  int tc = 0;
  while(t--){
    sd.clear();
    tc++;
    ans.clear();
    cout << "Case #" << tc << ": ";
    for(int i = 0 ; i < 100 ; i++){ g[i].clear(); visited[i]=0; color[i]=0; visited1[i]=false;}
      //else i++;
    int r,c;
    cin >> r >> c;
    for(int  i = 0 ; i < r ; i ++) {
      string tmp;
      cin >> tmp;
      sd.push_back(tmp);
    }
    map < char , int > sk;
    for(auto i : sd){
      for(auto j : i) sk[j]++;
    }
    for(int i = r-2 ; i >=0 ; i--){
      for(int j = 0 ; j < c  ;j++){
        if(sd[i][j] != sd[i+1][j]){
          g[sd[i][j]-'A'].push_back(sd[i+1][j]-'A');
        }
      }
    }
    bool fg = false;
   // cout << sk.size() << "++\n";
    for(int i = 0 ; i< 26;i++ ){
      if(!visited[i]){
        check = false;
         dfs(i);
         fg = fg | check;
      }
    }
    if(fg) cout << "-1\n";
    else {
      for(int i = 0 ; i < 26;i++){
        if(!visited1[i]) dfs1(i);
      }
      reverse(ans.begin(),ans.end());
      for(auto i : ans){
        if(sk[char(i+'A')] == 0) continue;
        else  cout << char(i+'A');
      } 
      cout << "\n";
    }
  }
  return 0;
} 
