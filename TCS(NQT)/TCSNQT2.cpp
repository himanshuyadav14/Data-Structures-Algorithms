#include <iostream>
#include <vector>

using namespace std;

// Function to find the ball's position after shuffles
int findBallPosition(vector<pair<int, int> >& shuffles, int N) {
    // Initialize the position of the ball
    int ballPosition = N;

    // Perform each shuffle
    for (const auto& shuffle : shuffles) {
        // If the ball is in one of the shuffled glasses, swap its position
        if (ballPosition == shuffle.first) {
            ballPosition = shuffle.second;
        } else if (ballPosition == shuffle.second) {
            ballPosition = shuffle.first;
        }
    }

    // Return the final position of the ball
    return ballPosition;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<pair<int, int> > shuffles(3);
        for (int i = 0; i < 3; ++i) {
            cin >> shuffles[i].first >> shuffles[i].second;
        }

        int finalPosition = findBallPosition(shuffles, N);
        cout << finalPosition << endl;
    }

    return 0;
}
