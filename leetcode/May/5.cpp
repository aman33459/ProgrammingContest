class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map< int , int > sd;
        for(auto i:nums) sd[i]++;
        for(auto i : sd){
            if(i.second > (nums.size()/2)) return i.first;
        }
        return 0;
    }
};
