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
bool cmp(pair < int , int > a ,pair < int , int > b){
  if(a.first < b.first ) return true;
  else if(a.first == b.first) {
    if(a.second < b.second) return true;
    else return false;
  }
  else return false;
}
int32_t main(){  
  fast;
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int f=0;
    int res=0;
    int ans = LLONG_MAX;
    vector < int > pre(s.size()+2,0);
    pre[0] = s[0]-'0';
    int n = s.size();
    for(int i = 1 ; i < s.size() ; i++){
        if(s[i] == '1') pre[i] = pre[i-1]+1;
        else pre[i]=pre[i-1];
    }
    for(int i = 0 ; i < s.size() ; i++){
      //cout << (i+1 - pre[i]) << " " << pre[s.size()-1] - pre[i] << "****\n";
     // cout << pre[i]  << " " << n-i-1 - pre[s.size()-1] + pre[i] << " " << pre[s.size()-1] << "++\n";
      ans = min(ans , (i+1 - pre[i]) + pre[s.size()-1] - pre[i]);
      ans = min(ans , pre[i] +  n-i -1 - pre[s.size()-1] + pre[i]);
    }    cout << ans << "\n";
  }
  return 0;
} 


/*


15 33


8.99 99
WB14D0028763
9990000000000000
9990000000000000
9990000000000000
9990000000000000

  4
3 5 7
1111
4 4 10
0110
4 3 4
1010
4 3 4
1100

111



3
3 5 4
101

2*k1 <=k2 
11111
8 10
11111 0 
5 5
111
k2 k2 k2 

10 12
126


3 

00001110000

000111000111
1111100
1110011

11101 10 01 00
0
k1 k1 k2 

*/
/*
1
[-5,3,-5],-3,1]

[-2,4,2,5,-5]
5
0 -1 2 -1 3
*/
