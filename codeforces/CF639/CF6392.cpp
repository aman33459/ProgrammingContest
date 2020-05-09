#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
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
int cal(int val){
    val = ((3*val+1)*val);
    val = val/2;
    return val;
}
int search(int val){
    int low = 1;
    int high = 1e9;
    int ans = -1;
    while(low <= high){
      int mid=  (low+high)/2;
      if(cal(mid) > val  ) high = mid-1;
      else {
        //cout <<  mid << " " << cal(mid) <<  "++\n";
        ans = cal(mid);
        low = mid+1;
      }
    }
    return ans;
}
int32_t main(){
  int t;
  cin >> t;
  while(t--){
  	 int n;
     cin >> n;
     int ans = 0;
     while(n > 1){
      int y = search(n);
      //cout << y << " " << n << "**\n";
      if(y == -1) break;
      n = n -y;
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}