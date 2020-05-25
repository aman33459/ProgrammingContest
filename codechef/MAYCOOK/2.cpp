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

int inv(int a , int m){
  return binpow(a,m-2,m);
}
int32_t main(){  
  int t;
  cin >> t;
 while(t--){
     string s;
     cin >> s;
     int n = s.size();
     const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;
      int ans = 0;
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] +  (s[i] - 'a' + 1) * p_pow[i]) % m;
   for(int i  = 0 ; i < n-2 ; i+=2){
    int l = 0;
    int r = i+1;
     int mid =  (r-l)/2;
     int k = (n - 1 - r- 1)/2;
     k = k + (r+1);
     //cout << mid+1 << " "<< r+1 << " " << k+1 << " " << n << "**\n";
     //cout << h[mid+1] << " ";
     int hash1 = h[mid+1];
     
     int hash2 = (((h[r+1] - h[mid+1] + m) %m) * inv(p_pow[mid+1] , m))%m;
     //cout << hash2 << "++\n";
     int hash3 = (((h[k+1] - h[r+1] + m)%m) * inv(p_pow[r+1] , m))%m;
     int hash4 = (((h[n]-h[k+1] + m) %m) * inv(p_pow[k+1] , m))%m; 
     if((hash1 == hash2) && (hash3 == hash4)) ans++;    
   } 
   cout << ans << "\n";  
  }
  return 0;
} 
