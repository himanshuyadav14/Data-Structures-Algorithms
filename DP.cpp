#include <iostream>
#include <vector>
using namespace std;

// Rec+Mem
// Step1 : Create DP Array + pass in function
// Step2 : Store the ans in DP Array
// Step3 : check is dp array already has ans, If yes then return just after the base cases
int fibonacciMem(int n, vector<int> &dp)
{
    // Base case
    if (n <= 1)
        return n;

    // Step3
    if (dp[n] != -1)
        return dp[n];

    int ans = fibonacciMem(n - 1, dp) + fibonacciMem(n - 2, dp);
    // Step 2
    dp[n] = ans;
    return ans;
}

// Bottom up Approach
// Step1: Dp Array Creation
// Step2: Base case Analysis of recursion Code and update the dp array accordingly
// Step3: Find the range for the changing variable and copy paste the logic code accordingly
int fibonacciTab(int n)
{
    // Step1:  Create a Dp Array
    vector<int> dp(n + 1, 0);

    // Step2: Base Case and update the dp array
    dp[0] = 0;
    dp[1] = 1;

    // Step3
    for (int i = 2; i <= n; i++)
    {
        int ans = dp[n - 1] + dp[n - 2];
        dp[n] = ans;
    }

    return dp[n];
}

int fibonacciTabSO(int nthTerm)
{
    //Replace dp array with optimised storage structures && remove the dp array creation and updation part
    int prev1 = 1;
    int prev2 = 0;
    int curr;

    // Step2: DP values -> replace -> prev1, prev2
    for (int i = 2; i <=nthTerm; i++)
    {
        int ans = prev1 + prev2;
        curr = ans;
        //Step3: Take care of the movement and updation
        prev2 = prev1;
        prev1 = curr;
    }

    return nthTerm == 1 ? 1 : nthTerm == 0 ? 0 : curr;
}

// Recursive solution
int fibonacci(int n)
{
    // Base case
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    //Top - Down Approach
    // Step1
    // vector<int> dp(n + 1, -1);
    // int ans = fibonacciMem(n, dp);


    //Bottom up approach
    int ans = fibonacciTabSO(n);
    cout << "Ans is -> " << ans << endl;
    return 0;
}