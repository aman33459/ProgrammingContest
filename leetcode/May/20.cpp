bool cmp(pair < pair < int , int > , int > const &a , pair < pair < int , int > , int > const &b){
    if(a.first.first < b.first.first) return true;
    else if(a.first.first == b.first.first) {
        if(a.first.second < b.first.second) return true;
        else return false;
    }
    else return false;
}
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector < vector < int > > ans;
        if(A.size() == 0 || B.size() == 0) return {};
       for(int i = 0 ; i < A.size();i++){
           for(int j = 0 ; j < B.size() ;j++){
               int x1=A[i][0];
               int y1=A[i][1];
                int x2=B[j][0];
               int y2=B[j][1];
               if(x1 <= x2 && x2 <=y1){
                   ans.push_back({x2,min(y1,y2)});
               }
               else if(x2 <= x1 && x1 <=y2){
                   ans.push_back({x1,min(y1,y2)});
               }
           }
       }
        
        return ans;
        
    }
};
