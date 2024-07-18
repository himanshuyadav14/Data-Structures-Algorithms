#include <iostream>
#include <vector>

using namespace std;

bool isValid(const vector<vector<int> >& board, int row, int col, int N) {
    // Check if there's already a bishop on the diagonal positions
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    return true;
}

void placeBishopsUtil(vector<vector<int> >& board, int K, int idx, int N, int& count) {
    // If all bishops are placed, increment the count
    if (K == 0) {
        count++;
        return;
    }

    // If we have considered all positions, return
    if (idx == N * N) {
        return;
    }

    int row = idx / N;
    int col = idx % N;

    // If the current position is valid for placing a bishop
    if (isValid(board, row, col, N)) {
        // Place the bishop
        board[row][col] = 1;
        // Recur for the next bishop
        placeBishopsUtil(board, K - 1, idx + 1, N, count);
        // Backtrack
        board[row][col] = 0;
    }

    // Recur for the next position
    placeBishopsUtil(board, K, idx + 1, N, count);
}

int placeBishops(int N, int K) {
    // Initialize the chessboard
    vector<vector<int> > board(N, vector<int>(N, 0));
    int count = 0;
    // Recursively place bishops
    placeBishopsUtil(board, K, 0, N, count);
    return count;
}

int main() {
    int N = 2, K = 2;
    cout << placeBishops(N, K) << endl;  // Output: 4

    N = 4, K = 3;
    cout << placeBishops(N, K) << endl;  // Output: 232

    N = 5, K = 5;
    cout << placeBishops(N, K) << endl;

    return 0;
}
