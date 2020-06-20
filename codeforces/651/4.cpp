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
int a[200005];
vector< int > sd;
bool possible(int x , int n , int k){
    int last = -2;
    int cnt = 0;
    int first;
    if(k%2){
      for(int i = 1 ; i < n-1 ; i++) {
          if(a[i] <= x &&  (i - last) > 1){ cnt++;last = i;}
      }
      if(cnt >= (k/2)) return true;
      else{
        last = -2;
        cnt = 0;
        for(int i = 0 ; i < n ; i++) {
          if(a[i] <= x &&  (i - last) > 1){ cnt++;last = i;}
        }
        int ok = k/2;
        ok++;
        if(cnt>=ok) return true;
        else return false;
      }
    }
    else{

      for(int i = 0 ; i < n-1 ; i++) {
          if(a[i] <= x &&  (i - last) > 1){ 
            if(last == -2) first = i;
            cnt++;last = i;}
      }

      if(cnt >= (k/2)) return true;
      else  {
        cnt = 0;
        last = -2;
          for(int i = 1 ; i < n ; i++) {
          if(a[i] <= x &&  (i - last) > 1){ 
            if(last == -2) first = i;
            cnt++;last = i;}
        }
        if(cnt >= (k/2)) return true;
        else return false; 
      }
 
    }
}
int search(int n , int k){
  int low = 0;
  int high = n-1;
  int ans = -1;
  while(low<=high){
    int mid = (low+high)/2;
    if(possible(sd[mid] , n , k)) {
      ans = sd[mid];
      high = mid-1;
    }
    else low = mid+1;
  }
  return ans;
}
int32_t main() 
{ 
  fast;
  int n , k;
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++) cin >> a[i];
  for(int i = 0 ; i < n ; i++) {
      sd.push_back(a[i]);
  }
  sort(sd.begin(), sd.end());
  cout << search(n,k) << "\n";
  return 0; 
}

