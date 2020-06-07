#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
//#define int long long
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

bool visited[55][55];
vector < string > s;
int32_t main() 
{ 
  fast;
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    int good = 0;
    s.clear();
    for(int i = 0 ; i < n ; i++){
      string tmp;
      cin >> tmp;
      s.push_back(tmp);
    } 
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(s[i][j] == 'G') good++;
      }
    }
    if(good == 0) cout << "YES\n";
    else{
     // cout << "oo\n";
    
      int nok=0;
      for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(s[i][j] == 'B' ){
          if(i+1 < n && s[i+1][j] == 'G') nok++;
          if(j+1 < m && s[i][j+1] == 'G') nok++;
          if(i-1 >=0 && s[i-1][j] == 'G') nok++;
          if(j-1 >=0 && s[i][j-1] == 'G') nok++; 
        }
      }
    }
    if(n-2 >=0 && s[n-2][m-1] == 'B') nok++;
    if(m-2>=0 && s[n-1][m-2] == 'B') nok++;
    if(nok) cout << "NO\n";
    else{
      nok = 0;
       for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(s[i][j] == 'B' ){
          if(i+1 < n && s[i+1][j] == '.') s[i+1][j]='#';
          if(j+1 < m && s[i][j+1] == '.') s[i][j+1]='#';
          if(i-1 >=0 && s[i-1][j] == '.') s[i-1][j]='#';
          if(j-1 >=0 && s[i][j-1] == '.') s[i][j-1]='#';
        }
      }
    }
      queue<pair < int32_t , int32_t > > sd;
      sd.push({n-1,m-1});
      for(int i = 0 ; i < 55 ; i++) {
        for(int j = 0 ; j < 55 ;j++) visited[i][j]=0;
      }
      
      while(sd.size()){
        auto k = sd.front();
        int i = k.first;
        int j = k.second;
        visited[i][j]=1;
        sd.pop();
        //cout << i << " " << j << "++\n";
          if(i+1 < n && visited[i+1][j] == 0 && (s[i+1][j] == '.' || s[i+1][j]  == 'G' )){sd.push({i+1,j}); visited[i+1][j]=1;}
          if(j+1 < m && visited[i][j+1] == 0 && (s[i][j+1] == '.' || s[i][j+1] == 'G')){sd.push({i,j+1});visited[i][j+1]=1;}
          if(i-1 >=0 && visited[i-1][j] == 0 && (s[i-1][j] == '.' || s[i-1][j] == 'G')){sd.push({i-1,j});visited[i-1][j]=1;}
          if(j-1 >=0 && visited[i][j-1] == 0 && (s[i][j-1] == '.' || s[i][j-1] == 'G')){ sd.push({i,j-1}); visited[i][j-1]=1;}

      }
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++) {
          if(s[i][j] == 'G' && visited[i][j] == 0) nok++;
        }
      }
      if(nok) cout << "NO\n";
      else cout << "YES\n";
    }
    }
  }
  return 0;
} 
/*

 0 0 1 4 5  5 5 
  2 2 10
  l..........r 

  gcd(a,b)
  lcm(a,b) (a*b)/gcd(a,b)
  15-1
  2*7
  8 - 2 = 
  oddnumber -1 %2 
  x + a*b/x
  odd number -1
  even number = 
  x^2 + a*b = y
  y - x^2 = a*b
  17-1 16 = 2,16 =
  100*100 
  1,1 =  2
  2*2 = 2+2 = 4
  2*4 = 4+2 = 6
  2*8 = 8+2 = 10
  2*6 = 6+2 = 8
  1*2 + 1 = 3
  1*3 + 1 = 4
  1*4 + 1 = 5
  1*5 + 1 = 6
  ....... 
  3,2,1,3,2,1
  100
  010
  000
  0000
  0000
  0000
*/

