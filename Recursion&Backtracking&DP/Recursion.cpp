#include <iostream>
using namespace std;
// void print(int n, int i){
//     if(i==n) return;
//     cout<<i<<" ";
//     print(n,i+1);
//     cout<<i<<" ";
// }

void print(int arr[], int i, int size)
{
    if (i == size)
        return;
    cout << arr[i] << " ";
    print(arr, i + 1, size);
}

long long int factorial(long long int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void printAllSubsequences(string s)
{
    int n = s.length();
    int totalSubsequences = pow(2, n); // Total number of possible subsets
    for (int mask = 0; mask < totalSubsequences; mask++)
    {
        string subsequence = "";
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {                        // Check if the ith bit is set in the mask
                subsequence += s[i]; // Include the character in the subsequence
            }
        }
        cout << subsequence << " "; // Print the subsequence
    }
}
int main()
{
    // int n  = 6;
    // print(n,1);
    // int arr[] = {2,3,7,8,9,10,0,12};
    // print(arr,0,8);
    // string ans = "";
    printAllSubsequences("abc");
    // long long int ans =  factorial(13);
    // cout<<ans<<endl;
    return 0;
}