class Solution {
public:
    int ans = 1e9+7;
    map < pair < int , int >  , int  > dp;
    int solve(int city1 , int city2 , int n , vector<vector<int>>& costs){
       // cout << city1 << " " << city2 << "++\n";
       if(city1 == n && city2 == n ) return dp[{city1,city2}] = 0;
       if(dp.find({city1,city2}) != dp.end()) return dp[{city1,city2}];
        if(city1 == n) return dp[{city1,city2}] = costs[city1+city2][1] +solve(city1 , city2 + 1 , n , costs);
        else if(city2 == n ) return dp[{city1,city2}] =  costs[city1+city2][0]+  solve(city1+1 , city2 , n , costs );
        return dp[{city1,city2}] = min( costs[city1+city2][0] + solve(city1+1 , city2 , n , costs)   ,   costs[city1+city2][1]  + solve(city1 , city2+1 , n , costs)   );
        
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //1st person 1 city or 2nd city
        // 2nd person
        
        // nc2 == 100*100
        //
        return solve(0 , 0 , ((int)costs.size())/2 , costs);
        
    }
};
