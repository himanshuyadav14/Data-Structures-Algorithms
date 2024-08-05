#include <iostream>
#include <climits>
using namespace std;

bool isUgly(int n)
{
    if (n <= 0) return false;  // Adding a check to handle non-positive numbers
    while (n % 2 == 0) n = n / 2;
    while (n % 3 == 0) n = n / 3;
    while (n % 5 == 0) n = n / 5;
    return n == 1;
}

int main()
{
    int n = 10;
    int cnt = 0;
    for (int i = 1; i < INT_MAX; i++) // Start from 1, as 0 is not considered an ugly number
    {
        if (isUgly(i)) cnt++;
        if (cnt == n)
        {
            cout << i << endl;
            break;  // Exit the loop once the nth ugly number is found
        }
    }
    return 0;
}
