#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack01(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP table: rows = items (0 to n), cols = capacity (0 to W)
    // dp[i][w] will store the maximum value for 'i' items and capacity 'w'
    vector<vector<int>> dp(n + 1, vector<int>(W + 1)); 

    // Build the table in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Base Case: If no items or 0 capacity, profit is 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // If weight of current item is less than or equal to current capacity 'w'
            else if (weights[i - 1] <= w) {
                // Choice 1: Include the item (current value + value of remaining weight)
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                
                // Choice 2: Exclude the item (value from previous item at same weight)
                int exclude = dp[i - 1][w];

                dp[i][w] = max(include, exclude);
            }
            // If item is too heavy, we must exclude it
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // The bottom-right cell contains the final answer
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<int> values(n), weights(n);
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];
    
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];
    
    cout << "Enter Knapsack capacity: ";
    cin >> W;

    cout << "Maximum Value in Knapsack: " << knapsack01(W, weights, values, n) << endl;

    return 0;
}