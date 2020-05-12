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
int sm[4000005];
int a[100005];
void build(int pos , int l , int r)
{
    
    if(l==r){
    sm[pos]=a[l];
    return;
    }
    if(l>r)
        return;
    int mid=(l+r)/2;
    build(2*pos+1,l,mid);
    build(2*pos+2,mid+1,r);
    sm[pos] = gcd(sm[2*pos+1] , sm[2*pos+2]);
}
int query(int pos,int l ,int r, int x,int y)
{
    if(x<=l && r<=y)
        return sm[pos];
    if(l>y || r<x)
        return 0;
    int mid=(l+r)/2;
    int xx = query(2*pos+1,l,mid,x,y);
    int yy = query(2*pos+2,mid+1,r,x,y);
    if(xx == 0) return yy;
    if(yy == 0) return xx;
    return gcd(xx,yy);
}
int32_t main(){  
  int n;
  cin >> n;
  for(int i = 0 ; i< n ; i++ ) cin >> a[i];
  build(0,0,n-1);
  int x,y;
  int ans = 0;
  for(int i = 0 ; i <n;i++){
    x=0;
    y=0;
    if(i-1 >=0) x=query(0,0,n-1,0,i-1);
    if(i+1 < n) y = query(0,0,n-1,i+1,n-1);
    if(ans == 0){
        if(x == 0) ans = y;
        else if(y == 0) ans=x;
        else ans = gcd(x,y);
    }
    else{
        if(x == 0) ans = (ans * y)/gcd(ans,y);
        else if(y == 0) ans = (ans*x)/gcd(ans,x);
        else{
            ans =(ans * gcd(x,y))/gcd(ans,gcd(x,y));
        }
    }
  }
  cout << ans << "\n";
  return 0;
} 
