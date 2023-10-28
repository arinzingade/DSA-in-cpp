
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    public:
        int maxProfit (vector<int> & prices) {

            // Basic Logic is to Buy Low and Sell High because in this array, we know the exact future of price movements.
            int profit = 0;
            int len = prices.size();
            
            for (int i = 0; i < len - 1; i++) {
                if (prices[i+1] - prices[i] > 0) {
                    profit = profit + prices[i+1] - prices[i];
                }
            }

            return profit;

        }   
};

int main () {

    vector<int> prices = {7,1,5,3,6,4};
    
    Solution s;
    int sol = s.maxProfit(prices);

    cout << "Max Profit attainable is: " << sol << endl;
}