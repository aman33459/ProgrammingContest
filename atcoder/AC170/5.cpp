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
inline int max(int a , int  b){
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
int ans= 0;
int divisors[1000005]={0};
void div(int x){
  if(divisors[x] > 1){ ans++;return;}
  if(x!=1 && divisors[1] > 0) {
    ans++;
    return;
  }
  int k = sqrt(x);
  for(int i = 2 ; i <=k ; i++){
    if(x%i == 0) {
      if(divisors[x/i] > 0  || divisors[i] > 0 ){ ans++;break;}

    }
  }
}

vector < int > sd[200005];
vector < multiset < int > > ok;
vector < int > kaunsa,gaya;
int32_t main() 
{ 
  fast;
  int n,q;
  cin >> n >> q;
  multiset < int > final;
 // set < int > a[200005];
  for(int i = 0 ; i < n ; i++){
    int x , y;
    cin >> x >> y;
    y--;
    kaunsa.push_back(x);
    sd[y].push_back(x);
    gaya.push_back(y);
  }
  for(int i = 0 ; i < 200005 ; i++){
    multiset < int > tmp;
    for(int j = 0 ; j < sd[i].size();j++){
      tmp.insert(sd[i][j]);
    }
    ok.push_back(tmp);
  }
  for(int i = 0 ; i < 200005 ; i++){
    if(ok[i].begin() == ok[i].end()) continue;
    auto it = ok[i].end();
    it--;
    final.insert(*it);

  }
  while(q--){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    auto it = ok[gaya[x]].end();
    it--;
    int kk = *it;
    ok[gaya[x]].erase(ok[gaya[x]].lower_bound(kaunsa[x]));
    if(ok[gaya[x]].begin() == ok[gaya[x]].end()) {
        final.erase(final.lower_bound(kk));
        if(ok[y].begin() == ok[y].end()){
            ok[y].insert(kaunsa[x]);
            final.insert(kaunsa[x]);
        }
        else{
        it = ok[y].end();
        it--;
        int k = *it;
        ok[y].insert(kaunsa[x]);
        it= ok[y].end();
        it--;
        if(*it !=k){
          final.erase(final.lower_bound(k));
          final.insert(*it);
        }
        }
    }
    else{
        it = ok[gaya[x]].end();
        it--;
        if(*it != kk){
          final.erase(final.lower_bound(kk));
          final.insert(*it);
        }
        if(ok[y].begin() == ok[y].end()){
            ok[y].insert(kaunsa[x]);
            final.insert(kaunsa[x]);
        }
        else{
        it = ok[y].end();
        it--;
        int k = *it;
        ok[y].insert(kaunsa[x]);
        it= ok[y].end();
        it--;
        if(*it !=k){
          final.erase(final.lower_bound(k));
          final.insert(*it);
        }
        }
    }
    auto am = final.begin();
    cout << *am << "\n";
    gaya[x] = y;
  }
  return 0; 
}

