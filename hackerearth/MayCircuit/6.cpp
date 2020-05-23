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
vector < int > g[500005];
map < pair < int , int > ,int > w;
struct comparator{
	bool operator()(const pair < pair < int , int > , priority_queue < int, vector<int>, greater<int> > > &a ,const pair < pair < int , int > , priority_queue < int, vector<int>, greater<int>> > &b){
		//cout << a.first.first << " " << b.first.first << " " << a.first.second << " " << b.first.second << "***\n";
		if(a.first.second < b.first.second) return true;
		else return false;
	}
};
int ans[500005];
int cal(priority_queue < int , vector<int>, greater<int>> tmp){
	int ans = 0;
	while(tmp.size()){
		ans+=tmp.top();
		tmp.pop();
	}
	return ans;
}
map < int , int > visited;
map < int , priority_queue < int, vector<int>, greater<int> > > ok;
void dijktras(int k){
	multiset < pair < pair < int , int > , priority_queue < int, vector<int>, greater<int> > >  , comparator > pq;
	priority_queue < int, vector<int>, greater<int>  > tmp;
	pq.insert({{0,0},tmp});
	//cout << "ayo \n";
	ans[0]=0;
	while(pq.size()){
		auto it = pq.begin();
		visited[(*it).first.first]=1;
		//cout << (*it).first.first << " " << cal((*it).second) << " " <<  (*it).first.second << "+++\n";
		//ans[(*it).first.first] = min(ans[(*it).first.first] , (*it).first.second);
		int u = (*it).first.first;
		int ww = (*it).first.second;
		priority_queue < int, vector<int>, greater<int> > tmp = (*it).second;

		pq.erase(pq.begin());
		for(auto v : g[u]){
			if(visited[v]) continue;
			//cout << v << "----\n";
			priority_queue < int, vector<int>, greater<int> > tmp1=tmp;
			int aa=0;
			tmp1.push(w[{u , v}]);
			if(tmp1.size() > k){
				aa+=tmp1.top();
				tmp1.pop();
			}
			if(ans[v] >  ww+aa){
				if(ans[v]!=LLONG_MAX) {
					pq.erase(pq.find({{v,ans[v]} , ok[v]}));
				}
				ans[v] = ww+aa;
				pq.insert({{v,ww+aa} ,tmp1});
				ok[v]=tmp1;
			}
		} 
	}
}
int32_t main(){
	int n,m,k;
	cin >> n >> m >> k;
	//cout << n << m << k << "--\n";
	for(int i = 0 ; i < m ; i++){
			int foo,bar,wi;
			cin >> foo >> bar >> wi;
			foo--;
			bar--;
			if(foo == bar) continue;
			//cout << i << "---\n";
			//cout << foo << bar << wi << "++\n";
			if(w[{foo,bar}]){
				w[{foo,bar}] = min(wi,w[{foo,bar}]);
				w[{bar,foo}] = min(wi,w[{bar,foo}]);
			}
			else{
				g[foo].push_back(bar);
				g[bar].push_back(foo);
				w[{foo,bar}] = wi;
				w[{bar,foo}] = wi;
			}
	}
	for(int i=  0 ; i < n ; i++) ans[i]=LLONG_MAX;
	dijktras(k);
	for(int i = 0 ; i < n ; i++) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}

/*

....
....
.... 
*/ 
