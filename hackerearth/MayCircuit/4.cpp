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
int solve(int n , int k){
	int terms = n/k;
	if(terms == 0) return 0;
	int ans = k*((terms*(terms+1))/2);
	ans-=(terms*(terms+1))/2;
	ans+=solve(terms,k);
	//cout << ans << "**" << terms << "++\n";
	return ans;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int ans = (n*(n+1))/2;
		//cout << ans << "++\n";
		ans-=solve(n,k);
		cout << ans << "\n";
	}
	return 0;
}

/*

....
....
.... 
*/
