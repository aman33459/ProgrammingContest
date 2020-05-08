class Solution {
public:
    int gcd(int a , int b){
        if(a == 0 ) return b;
        return gcd(b%a , a);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        pair < int , int >   slope ={coordinates[1][1] - coordinates[0][1] , coordinates[1][0] - coordinates[0][0]};
        int k = gcd(slope.first , slope.second);
        slope.first = slope.first / k;
        slope.second = slope.second / k;
        for(int i =2 ; i < coordinates.size() ; i++){ 
            int x = coordinates[i][1] - coordinates[i-1][1] ;
            int  y = coordinates[i][0] - coordinates[i-1][0];
            k = gcd(x,y);
            x = x/k;
            y=y/k;
            if(x!=slope.first || y != slope.second) return false;
        }
        return true;
    }
};
