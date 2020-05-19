 
class StockSpanner {
public:
    stack < pair < int , int >  > sd;
    StockSpanner() {
    bool ok;   
    }
    
    int next(int price) {
        int ans =1;
        while(sd.size() > 0 && sd.top().first <= price){
            ans+=sd.top().second;
            sd.pop();
        }
        sd.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
