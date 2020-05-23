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
const int mod = 1e9+7;
int a[1005][1005];
int val[1005][1005][5];
int dp[1005][1005]={{0}};
bool done[1005][1005] ={{false}};

/*
7**
1951**
5527**
280957

107
107
10000019
1361
1361
*/
void check(int a , int i , int j){
	if(a%107 == 0) val[i][j][0]=1;
	if(a%10000019 == 0) val[i][j][1]=1;
	if(a%1361 == 0) val[i][j][2]=1;
	if(a%(107*107) == 0) val[i][j][3]=1;
	if(a%(1361*1361) == 0) val[i][j][4]=1;
	//cout << i << " " << j << " " << a%7 << " " << val[i][j][0] << " " << val[i][j][1] << " " << val[i][j][2] << " " << val[i][j][3] << "++\n";
}
void cover(int x , int y , int i , int j){
	val[x][y][0] = val[x][y][0] | val[i][j][0];
	val[x][y][1] = val[x][y][1] | val[i][j][1];
	val[x][y][2] = val[x][y][2] |  val[i][j][2];
	val[x][y][3] = val[x][y][3] |  val[i][j][3];
	val[x][y][4] = val[x][y][4] |  val[i][j][4];
}
bool ok(int i , int j){
	if(val[i][j][0] == 1 && val[i][j][1] == 1 && val[i][j][2] == 1 && val[i][j][3] == 1 && val[i][j][4] == 1) return true;
	else return false;
}
int32_t main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> a[i][j];
		}
	}
	if(a[0][0]==212072634227239451){ dp[0][0]=0;done[0][0]=true;}
	else dp[0][0]=1;
	check(a[0][0],0,0);
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < m ; j++){
				if(i+1 < n){
					cover(i+1,j , i, j);
					check(a[i+1][j] , i+1 , j);
					if(val[i][j][0] == 1 && a[i+1][j] % 107 == 0) val[i+1][j][3]=1;
					if(val[i][j][2] == 1 && a[i+1][j] % 1361 == 0) val[i+1][j][4]=1;
					if(ok(i+1,j)){
						//cout << i << " " << j << " " << j+1 << "--\n";
					done[i+1][j]=true;	
					} 
					else dp[i+1][j]=(dp[i+1][j] + dp[i][j])%mod;
				}
				if(j+1 < m ) {
					cover(i,j+1,i,j);
					check(a[i][j+1] , i , j+1);
					if(val[i][j][0] == 1 && a[i][j+1] % 107 == 0) val[i][j+1][3]=1;
					if(val[i][j][2] == 1 && a[i][j+1] % 1361 == 0) val[i][j+1][4]=1;
					if(ok(i,j+1)) done[i][j+1]=true;
					else dp[i][j+1]=(dp[i][j+1] + dp[i][j])%mod;
				}
		cout << i << " " << j << " " << dp[i][j] << "++\n";
				//dp[i+1][j]+=dp[i][j];
			}			
	}
	cout << dp[n-1][m-1] << "\n";
	return 0;
}

/*

....
....
.... 
*/
