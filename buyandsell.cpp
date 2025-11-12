class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxprofit=0;
        int bestbuy=INT_MAX;

        for(int i=0;i<prices.size;i++){

            bestbuy=min(prices[i],bestbuy);

            maxprofit=max(maxprofit,prices[i]-bestbuy);
        }
        return maxprofit;
    }
};