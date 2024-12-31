#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// mahmoudadam5555@gmail.com
// The main concept is to use a 2D DP table to store the maximum value that can be obtained
// by considering that it has been reuse again during finding the comption result 'memoization'
// The DP table is
// filled in a bottom-up manner "tapular". The answer is stored in dp[numbags][max_weight].
// The time complexity is O(n * W) where n is the number of bags and W is the maximum weight
// the truck can handle.

int main() {
    int testcase; 
    cin >> testcase;

    while (testcase--) {
        int max_weight, numbags; // Maximum weight the truck can handle and number of bags
        cin >> max_weight >> numbags;

        vector<int> weight(numbags), value(numbags);
        for (int i = 0; i < numbags; i++) {
            cin >> weight[i] >> value[i]; // Input weights and values
        }

        // DP table
        vector<vector<long long>> dp(numbags + 1, vector<long long>(max_weight + 1, 0));

        // Fill the DP table
        for (int item = 1; item <= numbags; item++) {
            for (int item_weight = 0; item_weight <= max_weight; item_weight++) {
                if (weight[item - 1] <= item_weight) {
                    // Max of excluding or including the current item
                    dp[item][item_weight] = max(
                        dp[item - 1][item_weight], // Exclude item
                        dp[item - 1][item_weight - weight[item - 1]] + value[item - 1] // Include item
                    );
                } else {
                    dp[item][item_weight] = dp[item - 1][item_weight]; // Exclude item
                }
            }
        }

        // The answer is stored in dp[numbags][max_weight]
        cout << "Hey stupid robber, you can get " << dp[numbags][max_weight] << ".\n";
    }

    return 0;
}
