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
int inv(int a , int b){
  return binpow(a,b-2,b);
}
bool cmp(pair < int , pair  <int , int > >   a , pair < int , pair < int , int > > b){
  if(a.first < b.first) return true;
  else return false;
}
int b[1005][1005];
int sum[1005][1005];
bool search(int x , int n , int i , int j){
  int low = 0; 
//  int high = n-1;
  int high  = min(n-i-1 , n-j-1);
  while(low<=high){
    int mid = (low+high)/2;
    int l = i+mid;
    int r = j+mid;
    int m = 0 , c = 0 , d = 0;
    if(i > 0) m = sum[i-1][r];
    if(j > 0) c = sum[l][j-1];
    if(i > 0 && j > 0) d = sum[i-1][j-1];
    if(sum[l][r] -m-c+d  == x ) return true;
    else if(sum[l][r] -m-c+d > x) high = mid-1;
    else low = mid+1;
  }
  return false;
}
vector < int > g[10005];
int visited[10005];
int p[10005];
int rank1[10005];
void make_set(int xi)
{
    p[xi]=xi;
    rank1[xi]=0;
}
int find_set(int a)
{
    if(a==p[a])
        return a;
    p[a]=find_set(p[a]);
    return p[a];
}
void merge(int xi,int yi)
{
    int px=find_set(xi);
    int py=find_set(yi);
    if(px==py){
    return;}
    if(rank1[px]>rank1[py])
    {
        p[py]=px;
        
    }
    else{
        p[px]=py;
        
    }
    if(rank1[px]==rank1[py])
        rank1[py]+=1;
}

int32_t main() 
{ 
  fast;
  int n,k;
  cin >> n >> k;
  vector < int > alice , both,bob;
  for(int i = 0 ; i < n ; i++){
    int x,y,z;
    cin >> x >> y >> z;
    if(y == 1 && z == 1) both.push_back(x);
    else if(y == 1) alice.push_back(x);
    else if(z == 1) bob.push_back(x); 
  }
  sort(both.begin() , both.end());
  sort(alice.begin() , alice.end());
  sort(bob.begin() , bob.end());
  int cn = 0 , cn1  =0 , cn2=0;
  int ans = 0;
  while(k && ((cn1 < alice.size() && cn2 < bob.size() )||cn < both.size())){ 
      k--;
      if(cn1 >= alice.size() || cn2 >= bob.size()){
        ans+=both[cn];
        cn++;
      }
      else if(cn >=both.size()){
        ans+=alice[cn1];
        ans+=bob[cn2];
        cn1++;cn2++;
      } 
      else{
        if(alice[cn1] + bob[cn2] < both[cn]) {
          ans+=alice[cn1];
          ans+=bob[cn2];
          cn1++;
          cn2++;
        }
        else{
          ans+=both[cn];
          cn++;
        }
      }
  }
  if(k) cout << "-1\n";
  else cout << ans << "\n";

  return 0; 
}

