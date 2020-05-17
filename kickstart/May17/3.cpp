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
bool cmp(pair < int , string >   a , pair < int , string >   b){
  if(a.first < b.first ) return true;
  else return false;
}
int findSubarraySum(int *arr, int n, int sum) 
{ 

  int cum=0; // cumulated sum
      unordered_map<int,int> rec; // prefix sum recorder
      int cnt = 0; // number of found subarray
      rec[0]++; // to take into account those subarrays that begin with index 0
      for(int i=0;i<n;i++){
          cum += arr[i];
          cnt += rec[cum-sum];
          rec[cum]++;
       //   cout << cnt << " " << sum <<  "++\n";
      }
      return cnt;
    /*unordered_map<int, int> prevSum; 
    int res = 0; 
    int currsum = 0; 
    for (int i = 0; i < n; i++) { 
        currsum += arr[i]; 
        if (currsum == sum)  
            res++;         
  
        if (prevSum.find(currsum - sum) !=  
                                  prevSum.end())  
            res += (prevSum[currsum - sum]); 
          
         prevSum[currsum]++; 
    } 
  
    return res; */
}
int a[100005];
using namespace std::chrono;
int32_t main(){  
  fast;
  int t;
  cin >> t;
  int tc = 0;
  vector <int > sq;
  sq.push_back(0);
  for(int i = 1 ; i < 10000 ; i++){
    if(i*i > 10000000) break;
    sq.push_back(i*i);
  }
  while(t--){
      tc++;
      //auto start = high_resolution_clock::now(); 
      cout << "Case #" << tc << ": ";
      int n;
      cin >> n;
      int ans=0;
      int sum = 0;
      int x=0;
      map < int , int > ok;
      for(int i = 0 ; i < n ; i++) {cin >> a[i];
      if(a[i] > 0)
       sum+=(a[i]);
      ok[i] = sum;
     }
      unordered_map < int , int > pre;
//      int sum = 0;
      sum = 0;
      pre[0]++;
      for(int i = 0 ; i < n ; i++){
        sum+=a[i];
        for(auto num : sq){
          if(num > ok[i]) break;
         // cout << num << " " << sum << " " << num-sum << " " <<  pre[num-sum] << "++\n";
          ans+=pre[sum - num];
        }
        pre[sum]++;
      }

     // auto stop = high_resolution_clock::now(); 
      //auto duration = duration_cast<microseconds>(stop - start);
      //cout << duration.count() << "ms\n";
      cout << ans << "\n";
  }
  return 0;
} 
