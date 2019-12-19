//
// Created by Mayank Parasar on 2019-12-19.
//

/*
 * You are given an array. Each element represents the price of a stock on that particular day.
 * Calculate and return the maximum profit you can make from buying and selling that stock only once.

    For example: [9, 11, 8, 5, 7, 10]

    Here, the optimal trade is to buy when the price is 5, and sell when it is 10,
    so the return value should be 5 (profit = 10 - 5 = 5).
*/

#include <iostream>
#include <vector>

using namespace std;

int maximum_possible_profit(vector<int>& stocks) {
    vector<int> profit;

    for(int ii = 0; ii < stocks.size(); ++ii) { // bought
        for(int jj = ii; jj < stocks.size(); ++jj) { // sold
            profit.push_back(stocks[jj] - stocks[ii]); // profit : sold - bought
        }
    }

    return(*max_element(profit.begin(), profit.end()));
}

int main() {

    vector<int> stocks = {9, 11, 8, 5, 7, 10};
    cout << maximum_possible_profit(stocks);

    return 0;
}