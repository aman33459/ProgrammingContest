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
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int min(int a , int b){
  if(a < b) return a;
  else return b;
}
vector < int > ans;
int k = 1;
struct Compare { 
    bool operator()(pair < int , int > a, pair < int,  int > b) 
    { 
      //cout << a.first << " " << a.second << " " << b.first << " " << b.second <<  "++\n";
      if((a.second - a.first) < (b.second - b.first)) return true;
      else if((a.second - a.first)  ==  (b.second - b.first)){

        if(a.first > b.first){
          ///cout << "ok\n";
          return true;
        } 
        else return false;
      }
      else return false;
    } 
}; 
void solve(int l , int r){
  priority_queue<pair < int , int >  ,  vector<pair < int , int > >, Compare > sd;
  sd.push({l,r});  
  while(sd.size()){
    auto tmp = sd.top();
    int l = tmp.first;
    int r = tmp.second;
   // cout << l << " " << r << "+++\n";
    sd.pop();
    int mid = (r-l)/2;
    mid = l+mid;
    ans[mid]=k;
    k++;
    if(l <= mid-1) sd.push({l,mid-1});
    if(mid+1 <= r) sd.push({mid+1,r});
  }
}
int32_t main(){  
  int t;
  cin >> t;
  while(t--){
    int n;
    k=1;
    cin >> n;
    ans.clear();

  //cout << "ok**\n";
    for(int i = 0 ; i < n ; i++) ans.push_back(0); 
    solve(0,n-1);
  for(auto i : ans ) cout << i << " ";
    cout << "\n";
  }
  return 0;
} 
