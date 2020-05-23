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
	int x,n;
	cin >> x >> n;
	if(n >= 5) cout << "1";
	else if(n==1) cout << x%10;
	else if(n==2) {
			x=x*x;
			cout << x%10;
	}
	else{
			int a = x%10;
			int cnt=0;
			if(n==3) cnt=5;
			else cnt=3;
			while(cnt)
			{
				a=a*x;
				a%=10;
				cnt--;
			}
			cout << a << "\n";
	}	
	return 0;
}

/*

....
....
.... 
*/
