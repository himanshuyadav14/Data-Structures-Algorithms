#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX

using namespace std;

pair<int, int> solve(vector<int>& nums, int L) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int min_diff = INT_MAX;
    int count = 0;

    // Check all pairs
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int curr_sum = nums[i] + nums[j];
            int diff = abs(curr_sum - L);

            if (diff < min_diff) {
                min_diff = diff;
                count = 1;
            } else if (diff == min_diff) {
                count++;
            }
        }
    }

    return make_pair(min_diff, count);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int M, L;
        cin >> M >> L;
        vector<int> vec(M);

        for (int i = 0; i < M; i++) {
            cin >> vec[i];
        }

        pair<int, int> result = solve(vec, L);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
