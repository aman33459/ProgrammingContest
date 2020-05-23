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

	int n;
	cin >> n;
	int ans = 20000;
	vector < int > ok;
	unordered_map < int , int > done;
	for(int i = 0 ; i < min(n,350) ; i++){
		//cout << ans << " ";
		ok.push_back(ans);
		ans--;
	}
	vector < int > pre(n);
	bool oo = true;
	pre[0]=ok[0];
	pair < int , int >  kaunsa;
	for(int i = 1; i < n ; i++) pre[i]=pre[i-1]+ok[i];
	for(int i = 0 ; i < n ; i++){
		//cout << i << "++\n";
		for(int j = i ; j < n ; j++){
			//cout << i << " " << j << "++\n";
			if(i == 0){
					if(done[pre[j]]){
						kaunsa = {i,j};
						oo = false;	
					} 
					done[pre[j]]++;
			}
			else{
				if(done[pre[j]-pre[i-1]]) {
					oo=false;
					kaunsa ={i,j};
				}
				done[pre[j]-pre[i-1]]++;
			}
		}
	}
	cout << oo << " " << kaunsa.first << " " << kaunsa.second  <<  "\n";
	cout << "\n";
	return 0;
}
