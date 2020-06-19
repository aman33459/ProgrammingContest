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

typedef struct Trie{

  int a;
  unordered_map < Trie * , int > points; 
} trie;
int cnt[20]={0};
int32_t main() 
{ 
  fast;
  int n;
  cin >> n;
  vector < int > a(n);
  for(int i = 0 ; i < n ; i++){
    cin >> a[i];
    for(int k = 0 ; k < 20 ; k++) {
      if(a[i] & (1LL<<k)) cnt[k]++;
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    int temp = 0;
    for(int j = 0 ; j < 20 ; j++){
      if(cnt[j]){
        cnt[j]--;
        temp = temp + (1LL<<j);
      }
     }
     ans = ans + temp*temp;
  } 
  cout << ans << "\n";

  return 0; 
}

