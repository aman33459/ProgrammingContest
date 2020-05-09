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
int32_t main(){  
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector < int > candies(n);
    for(int i = 0 ; i < n ; i++) cin >> candies[i];
    int l = 0;
    int r = n-1;
    int a = 0;
    int b  = 0 ;
    int moves=0;
    int prev = 0;
    int curr;
    int f=1;
    while(l<=r  && r>=0 && l< n){
      if(f) {
        curr = candies[l];
        a+=candies[l];
        l++;
        while(curr <= prev){
          if(l > r || l > n) break;
          curr+=candies[l];
          a+=candies[l];
          l++;
        }
      }
      else{
        curr = candies[r];
        b+=candies[r];
        r--;
        while(curr <= prev){
          if(l > r || r < 0 ) break;
          curr+=candies[r];
          b+=candies[r];
          r--;
        }
      }
      //cout << curr << " " << l << " "  << r << " " << a << " " << b << "++\n";
      prev= curr;
      moves++;
      f=f^1;
    }
    cout << moves << " " << a << " " << b << "\n";
  }
  return 0;
}