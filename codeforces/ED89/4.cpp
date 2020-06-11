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
bool prime(int a){
  for(int i = 2 ; i <= sqrt(a) ; i++){
    if(a%i == 0) return false;
  }
  return true;
}
const int N=10000005;
bool v[N]={false};
int sp[N];

void Sieve(){
  for (int i = 2; i < N; i += 2)  sp[i] = 2;//even numbers have smallest prime factor 2
  for (long long i = 3; i < N; i += 2){
    if (!v[i]){
      sp[i] = i;
      for (long long j = i; (j*i) < N; j += 2){
        if (!v[j*i])  v[j*i] = true, sp[j*i] = i;
      }
    }
  }
}
void finddivisors(int x){
  vector < int > sd;
  for(int i = 2 ; i <= sqrt(x) ;i++){
    if(x%i == 0){
      sd.push_back(x/i);
      if(x/i != i) sd.push_back(i);
    }
  }
  int f = 0;
  for(int i = 0 ; i < sd.size(); i++) {
    for(int j = i+1 ; j < sd.size();j++){
      if(gcd(sd[i]+sd[j] , x) == 1 ) {
        if(prime(sd[i]) && prime(sd[j]))  cout << x << " " <<  sd[i] << " " << sd[j] << "++\n";
        else cout << x << " " <<  sd[i] << " " << sd[j] << "\n";
        //f++;
        //else cout << x << " " <<  sd[i] << " " << sd[j] << "++\n";
      } //cout << x << " " << sd[i] << " " << sd[j] << "++\n";
    }
  }
//  if(f) cout << x << "\n";
}
int32_t main() 
{ 
  fast;
  int n;
  cin >> n;
  Sieve();
  vector < pair < int  , int >  > ans;
  vector < int > a(n);
 // iota(a.begin(),a.end(),1);
  for(int i = 0 ; i < n ; i++) cin >> a[i];
  for(int i = 0 ; i < n ; i++){
    if(sp[a[i]] == a[i]) ans.push_back({-1,-1});
    else{
      int f = 0;
        int tmp = a[i];
        while(tmp > 1){
          if(gcd(sp[tmp] + (tmp / sp[tmp]) , a[i]) == 1  && tmp/sp[tmp] !=1 && sp[tmp]!=1) {
            f++;
            ans.push_back({sp[tmp] , tmp / sp[tmp]});
            break;
          }
          tmp = tmp / sp[tmp];
        }
        if(!f) ans.push_back({-1,-1});
    }
  }
  for(auto i : ans) cout << i.first << " ";
    cout << "\n";
  for(auto  i : ans) cout << i.second << " ";
    cout << "\n";
  return 0;
} 
/*
*/
 
