


#include <bits/stdc++.h>
using namespace std;

void solve(int row, int n, vector<string>& board,
           vector<vector<string>>& ans,
           vector<int>& col,
           vector<int>& diag1,
           vector<int>& diag2) {

    // All queens placed successfully
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        // Check if the column or diagonals are occupied
        if (col[c] || diag1[row - c + n - 1] ||
            diag2[row + c]) {
            continue;
        }

        // Place queen
        board[row][c] = 'Q';
        col[c] = 1;
        diag1[row - c + n - 1] = 1;
        diag2[row + c] = 1;

        // Recur for the next row
        solve(row + 1, n, board, ans, col, diag1, diag2);

        // Backtrack: remove queen
        board[row][c] = '.';
        col[c] = 0;
        diag1[row - c + n - 1] = 0;
        diag2[row + c] = 0;
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans(n);
    vector<int> col(n, 0);
    vector<int> diag1(2 * n - 1, 0);
    vector<int> diag2(2 * n - 1, 0);

    solve(0, n, board, ans, col, diag1, diag2);

    cout << "Total solutions: " << ans.size() << "\n\n";

    for (const auto& solution : ans) {
        for (const auto& row : solution) {
            cout << row << '\n';
        }
        cout << '\n';
    }

    return 0;
}




