class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0;
        int max_so_far = -INT_MAX;
        int last = 0;
        for(auto i : A){
            sum = sum + i;
            if(sum < 0) {
                sum = 0;
                max_so_far = max(max_so_far , i);
            }
           else  max_so_far = max(max_so_far,sum);
        }
        vector< int > pre(A.size());
        pre[0]=A[0];
        for(int i = 1 ; i < A.size() ; i++){
            pre[i] = pre[i-1]+A[i];
            
        }
        for(int i = 1 ; i < A.size() ; i++){
            pre[i] = max(pre[i-1],pre[i]);
            
        }
        vector < int > suff(A.size()+2);
        suff[A.size()]=0;
        suff[A.size()-1] = A.back();
        for(int i = A.size()-2 ; i>=0;i--) suff[i]=suff[i+1]+A[i];
        for(int i = 1 ; i < A.size() ; i++){
          //  cout << A[i] << " " << max_so_far  << " " << pre[i-1] << " " << suff[i+1] << "++\n";
            max_so_far = max(max_so_far, pre[i-1] + A[i]+suff[i+1]);
            
        }
        //cout << "***\n";
        return max_so_far;
    }
};
