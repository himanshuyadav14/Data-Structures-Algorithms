#include <iostream>
#include <vector>
using namespace std;

// Recursion + Memoization
int minCoin(int target, vector<int> &arr, vector<int> &dp)
{
    // Base case
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;

    // DP
    if (dp[target] != -1)
        return dp[target];

    int mini = INT_MAX;
    for (size_t i = 0; i < arr.size(); i++)
    {
        int ans = minCoin(target - arr[i], arr, dp);

        // If ans is valid then update mini
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }

    return dp[target] = mini;
}

// Recursion + Tabulation
int minCoinTab(int t, vector<int> &arr)
{
    // Create DP array
    vector<int> dp(t + 1, INT_MAX);

    // update on the basis of base cases of Recursion + Memoization
    dp[0] = 0;

    //For loop and keep note of the range in mind
    for (int target = 1; target <= t; target++){
        //Then copy paste the code and convert the fucntion call into dp
        int mini = INT_MAX;
        for (size_t i = 0; i < arr.size(); i++){
            if (target - arr[i] >= 0){
                int ans = dp[target - arr[i]];

                // If ans is valid then update mini
                if (ans != INT_MAX) mini = min(mini, 1 + ans);
            }
        }
        dp[target] = mini;
    }

    //return
    return dp[t];
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    int target = 7;
    // DP array
    //  vector<int>dp(target+1,-1);
    cout << minCoinTab(target, arr) << endl;
    return 0;
}