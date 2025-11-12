#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxprofit(vector<int>& prices) {
    int maxprofit = 0;
    int bestbuy = prices[0];

    for (int i = 1; i < prices.size(); i++) {

        // Update bestbuy if we find a smaller price
        bestbuy = min(bestbuy, prices[i]);

        // Calculate profit if selling today
        maxprofit = max(maxprofit, prices[i] - bestbuy);
    }
    return maxprofit;
}

int main() {
    vector<int> bestbu = {7, 1, 5, 3, 6, 4};
    cout << maxprofit(bestbu);
    return 0;
}
