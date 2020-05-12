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
bool prime(int n){
  for(int i = 2 ; i  <= sqrt(n);i++){
    if(n%i == 0) return false;
  }
  return true;
}
int fin(int x){
  for(int i = 2 ; i <=sqrt(x);i++){
    if(x%i == 0) return i;
  }
  return x;
}
int32_t main(){  
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    if(n%2 == 0){
      n=n+2*k;
      cout << n << "\n";
    }
    else{
      if(prime(n)) n = n + n;
      else n=n+fin(n);
      n = n + 2*(k-1);
      cout << n << "\n";
    } 
   }
  return 0;
} 
