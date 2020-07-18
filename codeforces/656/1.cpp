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
const int N= 500005;
vector < int > g[N];
int depth[N];
int a,b;
map < int , int > sd,sk;
map < int, int > point1,point2;
void dfs(int v ,int pr){
  if(pr == -1) depth[v] = 0;
  else depth[v] =depth[pr]+1;
  
  for(auto u : g[v]){
    if(u == pr) continue;
    dfs(u,v);
  }

  sd[depth[v]%a]++;
  sk[depth[v]%b]++;
  point1[v] =  sd[depth[v]%a];
  point2[v] = sk[depth[v]%b];
}
int32_t main() 
{ 
  fast;
  int t;
  cin >> t;
  while(t--){
    int x,y,z;
    cin >> x >> y >> z;
    if(x == y || y == z || z == x){
        if(x == y && x >= z){
        //  cout << "YES\n";
          cout << "YES\n";
        
          cout << x << " " << z << " " << z << "\n";
        }
        else if(z == y && z >= x){
        //  cout << "YES\n";
          cout << "YES\n";
        
          cout << x << " " << x << " " << z << "\n";
        }
        else if(x == z && x >= y){
        //  cout << "YES\n";
          cout << "YES\n";
        
          cout << y << " " << x << " " << y << "\n";
        }
        else  cout << "NO\n";
    }
    else {
      cout << "NO\n";
    }
   }
  return 0; 
}

