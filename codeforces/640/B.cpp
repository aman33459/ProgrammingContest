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
    int n,k;
    cin >> n >> k;
    if(n%2 == 0){
        if(k%2){
          if(2*k > n) cout << "NO\n";
            else{
            cout << "YES\n";
            for(int i = 0 ; i < k-1 ; i++) cout << "2 ";
             cout << n - 2*(k-1) << "\n";
            }
        }
        else{
              if(k>n) cout << "NO\n";
                else{
            cout << "YES\n";
            for(int i = 0 ; i < k-1 ; i++) cout << "1 ";
               cout << n - (k-1) << "\n";
          }

        }
         
    }
    else{
        if(k > n || k%2 == 0) cout << "NO\n";
        else{
          cout << "YES\n";
          for(int i = 0 ; i < k-1 ; i++) cout << "1 ";
             cout << n - (k-1) << "\n";
        }
    }
  }
  return 0;
}