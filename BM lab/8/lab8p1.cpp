#include <iostream>
#include <vector>
using namespace std;

int countCombinations(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // there is one way to make the amount zero
    for (int coin : coins) {
        //update the combinations all amounts that can be reached with this coin
        for (int x = coin; x <= amount; x++) {
            dp[x] += dp[x - coin];
        }
    }
    return dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter the number of coin: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coins: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    cout << "Enter total amount: ";
    cin >> amount;

    int result = countCombinations(coins, amount);
    cout << "Number of combinations is " << result << endl;

    return 0;
}

/*
Time Complexity: O(number of coins * target amount)
Space Complexity: O(target amount)
*/