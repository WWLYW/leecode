/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, profit = 0;
        vertor<int> day_profit;
        day_profit.push_back(0);
        for(int i = 1; i < prices.size(); i++){
                int temp_profit = prices[i] - prices[i-1];
                day_profit.push_back(temp_profit);
        }

        for(int i = 0; i < day_profit.size(); i++){
                if ( profit + day_profit[i] >= 0){
                        profit = profit + day_profit[i];
                }
                else{
                        profit = 0;
                }

                if(day_profit[i] > 0){
                        if (profit > max_profit) max_profit = profit;
                }
        }
        return max_profit;

    }
};
