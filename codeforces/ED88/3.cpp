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
bool cal(int k , int  h ,  int c , int  t){
  double ans;
  double res;
  ans = double(k *1.00* h);
  res = double((k-1.00) * 1.00 *c);
 // cout << ans << " " << res << "--\n";
  double tmp = ((ans + res + 0.00) / (double)(1.00*(2*k-1)*1.00));
  k++;
  ans = double(k *1.00* h);
  res = double((k-1.00) * 1.00 *c);
  double tmp1 = ((ans + res + 0.00) / (double)(1.00*(2*k-1)*1.00));
 //cout << tmp << " " << t << " " << tmp1 << "***\n";
  if(fabs(tmp-t) <= fabs(tmp1-t)) return true;
  else return false;
     
}

int32_t main(){  
  fast;
  int t;
  cin >> t;
  while(t--){
      int h,c,t;
      cin >> h >> c >> t;
      int x = h+c - 2*t ; 
      int y = -1*(c-t);
      int ans;
      int ok = (h+c)/2;
      if(x == 0 || y == 0){
          if(abs(h-t) <= abs(ok - t)) ans = 1;
        else ans = 2;
      }
      else if((x < 0 && y > 0) || (x > 0 && y < 0)){
            int k = abs(y)/abs(x);
            if(k== 0){
              if(abs(h-t) <= abs(ok - t)) ans = 1;
              else ans = 2;
            }
            else{
             // cout << k << " " << x  << " " << y <<  "\n";
              if(cal(k ,h , c , t)) ans = 2*k-1;
              else ans = 2*(k+1)-1;
            }
      } 
      else{
        if(abs(h-t) <= abs(ok - t)) ans = 1;
        else ans = 2;
      }
      //cout << res << "++\n";
      cout << ans << "\n";
    }
  
  return 0;
} 

/*
1
[-5,3,-5],-3,1]

[-2,4,2,5,-5]

*/
