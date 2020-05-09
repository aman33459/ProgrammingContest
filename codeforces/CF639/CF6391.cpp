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

int32_t main(){
  int t;
  cin >> t;
  while(t--){
  	int n,m;
  	cin >> n >>m;
  	if(n == 1 || m == 1) cout << "YES\n";
  	else{
  		if(n ==2 && m == 2) cout << "YES\n";
  		else cout << "NO\n";
  	}
  }
  return 0;
}