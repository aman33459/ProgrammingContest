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
int a[123456];
int32_t main(){  
  fast;
  int t;
  cin >> t;
  while(t--){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int k = (x2-x1);
    int x = (y2-y1);
    int a = (k*(k+1))/2;
    int b = ((k-1)*k)/2;
    int mi = b;
    int ma = a+(x-1)*k;
    //cout << ma << " " << mi << "++\n";
    cout << ma-mi+1 << "\n";

  }
  return 0;
} 

