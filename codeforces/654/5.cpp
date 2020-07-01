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
int search(vector < int > &a , int val){
  int low = 0;
  int ans  =-1;
  int high =  (int)a.size() - 1;
  while(low <= high){
    int mid = (low+high)/2;
    if(a[mid] <= val ){
      ans = mid;
      low = mid+1;
    } 
    else {
      high = mid-1;
    }
  }
  return ans;
}
vector < int > ans;
int32_t main() 
{ 
  fast;
  int n,p;
  cin >> n >> p;
  vector < int  > a(n);
  for(int i = 0 ; i < n ; i++) cin >> a[i];
  sort(a.begin() , a.end());
  for(int x = 1 ; x <=100000 ; x++){
    int nok = 0;
    int tmp =x;
    int prev = -1;
    int done = 0;
    for(int i = 0 ; i < n ; i++){
      auto it  = search(a,tmp);
      if(it == -1) {
        nok++;
        break;
      }
      int count = it+1;
     // cout << x << " " << count << "++\n";
      if(count < i+1) {
        nok++;
        break;
      }
      if(prev == -1) prev = count;
      else {
        if(prev != count) {
          if(prev - done>=p){
            nok++;
            break;
          }
          done = prev;
          prev = count;
        }
      }
      tmp++;
    }
    if(prev - done >= p) nok++;
    if(!nok) ans.push_back(x);
  }
  cout << ans.size() << "\n";
  for(auto i : ans) cout << i << " ";
    cout << "\n";
  return 0; 
}

