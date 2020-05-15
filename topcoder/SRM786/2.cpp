#include<bits/stdc++.h>
using namespace std;
class SmallestRegular{
    public:
    	vector < int > findLexSmallest(string &x){
            bool ok=false;
            vector < int > ans;
            for(int i  = 0; i < x.size() ; i++){
                if(x[i] == ')') ok=true;
               	if(x[i] == '(' && ok){
                    ans.push_back(0);
                    ans.push_back(i-1);
                    ans.push_back(i);
                  }
             }
            return ans;
       }
};
