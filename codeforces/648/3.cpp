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
int fun(int a , int b) 
{ 
    printf("Value of a is %d\n", a); 
} 
int32_t main() 
{ 
  fast;
  int n;
  cin >> n;
  map < int , int > sd;
  vector <int > a(n),b(n);
  vector < int > pos(n+1,0);
  for(int i = 0 ; i < n ; i++) cin >> a[i];

  for(int i = 0 ; i < n ; i++) cin >> b[i];
  for(int i = 0 ; i < n ; i++) pos[a[i]] = i; 
  for(int i = 0 ; i < n ; i++){
    int k;
    if(pos[b[i]] < i) {
        k = (n-i-1 + pos[b[i]] + 1);
    }
    else k = ( pos[b[i]] - i);
    sd[k]++;
  //  cout << k << "**\n";
  }
  int ans = 0;
  for(auto i : sd){
    ans = max(ans , i.second);
  }
  cout << ans << "\n";
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

