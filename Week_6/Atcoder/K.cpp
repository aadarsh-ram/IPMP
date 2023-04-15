#include <iostream>
#include <vector>
using namespace std;

int dp[100001][2];
vector<int> arr;

// Function to switch moves
int opp(int x) {
    if (x == 1) {return 2;}
    if (x == 2) {return 1;}
}

// Aim: To make the other person lose, by not allowing him to play.
int ans(int rem, int move) {
    int who_win = opp(move);

    // Check if the problem of "can current person win" is solved for a value and person.
    if (dp[rem][move-1] != 0) {
        return dp[rem][move-1];
    }

    // The below code checks for all possible ways to reach "rem" using diff stones recursively.
    // If any way is found such that current person wins, his number is returned.
    // If no way is found, the other person's number is returned.
    for (auto j: arr) {
        // Check if stone can be used
        if (rem-j >= 0)  {
            // If problem already solved
            if (dp[rem-j][opp(move)-1] != -1) {
                // If way was been found, that person can win.
                if (dp[rem-j][opp(move)-1] == move) {
                    who_win = move; break;
                }
            }
            // If way was been found, that person can win.
            if (ans(rem-j, opp(move)) == move) {
                who_win = move; break;
            }
        } 
    }
    // Update dp array to who won
    dp[rem][move-1] = who_win;
    return who_win;
}

int main() {
    int n, k;
    cin >> n; cin >> k;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    if (ans(k, 1) == 1) {cout << "First" << '\n';}
    else {cout << "Second" << '\n';} 
    return 0;
}
