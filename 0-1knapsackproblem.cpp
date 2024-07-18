#include <iostream>
#include <vector>

using namespace std;

// Recursion
int solve(vector<int> &val, vector<int> &wt, size_t index, int capacity)
{
    // Base case
    if (index == val.size() || capacity == 0)
        return 0;

    // Include
    int include = 0;
    if (capacity >= wt[index])
        include += val[index] + solve(val, wt, index + 1, capacity - wt[index]);

    // Exclude
    int exclude = solve(val, wt, index + 1, capacity);

    return max(include, exclude);
}

// Recursion + Memoization 2D-DP
int solveMem(vector<int> &val, vector<int> &wt, size_t index, int capacity, vector<vector<int> > &dp)
{
    // Base case
    if (index == val.size() || capacity == 0)
        return 0;

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // Include
    int include = 0;
    if (capacity >= wt[index])
        include += val[index] + solveMem(val, wt, index + 1, capacity - wt[index], dp);

    // Exclude
    int exclude = solve(val, wt, index + 1, capacity);

    return dp[index][capacity] = max(include, exclude);
}

// Recursion + Tabulation 2D DP
int solveTab(vector<int> &val, vector<int> &wt, int capacity, int n)
{
    // Create DP Array
    vector<vector<int> > dp(n + 1, vector<int>(capacity + 1, 0));
    for (int index = n - 1; index >= 0; index--){
        for (int c = 1; c <= capacity; c++){
            // Include
            int include = 0;
            if (c >= wt[index]) include += val[index] + dp[index + 1][c - wt[index]];

            // Exclude
            int exclude = dp[index + 1][c];

            dp[index][c] = max(include, exclude);
        }
    }
    return dp[0][capacity];
}

int main()
{
    int n = 3;
    vector<int> val, wt;

    val.push_back(60);
    val.push_back(100);
    val.push_back(120);

    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);

    int capacity = 50;

    // vector<vector<int> >dp(n+1, vector<int>(capacity+1,-1));
    int ans = solveTab(val, wt, capacity, n);

    cout << "ans is " << ans << endl;

    return 0;
}