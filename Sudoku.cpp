#include <bits/stdc++.h>
using namespace std;

bool check(int ch, int row, int col, int n, int** board) {
    // check in row
    for (int c = 0; c < n; c++) {
        if (c != col && board[row][c] == ch) {
            return false;
        }
    }
    // check in col
    for (int r = 0; r < n; r++) {
        if (r != row && board[r][col] == ch) {
            return false;
        }
    }
    // check in square
    int sqrt_n = sqrt(n);
    int str = (row / sqrt_n) * sqrt_n;
    int stc = (col / sqrt_n) * sqrt_n;
    for (int dx = 0; dx < sqrt_n; dx++) {
        for (int dy = 0; dy < sqrt_n; dy++) {
            if (str + dx == row && stc + dy == col)
                continue;
            if (board[str + dx][stc + dy] == ch)
                return false;
        }
    }
    return true;
}

void rec(int row, int col, int n, int** board, int& ans) {
    if (col == n) {
        rec(row + 1, 0, n, board, ans);
        return;
    }
    if (row == n) {
        // base case
        ans++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    if (board[row][col] == 0) {
        // we need to fill.
        for (int ch = 1; ch <= n; ch++) {
            if (check(ch, row, col, n, board)) {
                board[row][col] = ch;
                rec(row, col + 1, n, board, ans);
                board[row][col] = 0;
            }
        }
    } else {
        // pre-filled.
        if (check(board[row][col], row, col, n, board)) {
            rec(row, col + 1, n, board, ans);
        }
    }
}

void solve(int n) {
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    rec(0, 0, n, board, ans);

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
