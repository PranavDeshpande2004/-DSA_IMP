#include <bits/stdc++.h>
using namespace std;
int minDiceThrows(vector<int>& board) {
    int n = board.size();
    if (n == 0) return 0;

    vector<bool> visited(n, false);
    queue<pair<int,int>> q; // cell, dice count

    visited[0] = true;
    q.push({0, 0});

    while (!q.empty()) {
       // pair<int,int> p = q.front();
        int pos = q.front().first, dice =q.front().second;
        q.pop();

        // try all dice outcomes 1..6
        for (int i = 1; i <= 6 && pos + i < n; ++i) {
            int dest = pos + i;
            int next = (board[dest] == -1) ? dest : board[dest];

            if (!visited[next]) {
                visited[next] = true;
                // if we've reached the last cell, return dice+1
                if (next == n - 1) return dice + 1;
                q.push({next, dice + 1});
            }
        }
    }

    return -1;
}
int main() {
    int N = 30;
    vector<int> board(N, -1);

    // Ladders
    board[2] = 21;
    board[4] = 7;
    // Snakes
    board[26] = 10;
    board[20] = 8;

    cout << "Minimum dice throws = " << minDiceThrows(board) << endl;
}