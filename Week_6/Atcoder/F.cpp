#include <bits/stdc++.h>
using namespace std;

string s,t;
int n,m;
int dp[3001][3001];
int best[3001][3001];

string total_ans;

// Aim: To find the longest common substring (LCS)
int ans(int i,int j) {
  // Base case
  if (i >= n || j >= m)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  
  int res = 0;
  // If index matches, then it is present in LCS
  // Leave first character of both suffixes and recur
  if (s[i]==t[j]) {
    res = 1 + ans(i+1,j+1);
    best[i][j] = 1;
  }
  else {
    // Leave first character of current suffix of s, and recur
    int val1 = ans(i+1,j);
    // Leave first character of current suffix of t, and recur
    int val2 = ans(i,j+1);
    // Check which gives maximum common characters
    res = max(val1,val2);
    if (val1 > val2) {
        best[i][j] = 2;
    }
    else
        best[i][j] = 3;
  }
  
  return dp[i][j]=res;
}

// Generates the string by reconstructing the recursion
// Appends the common characters to the answer
void string_gen (int i,int j) {

    if (i >= n || j >= m) {
        return;
    }
    if (best[i][j] == 1) {
        total_ans.push_back(s[i]);
        string_gen(i+1,j+1);
    }
    else if (best[i][j] == 2) {
        string_gen(i+1,j);
    }
    else if(best[i][j] == 3) {
        string_gen(i,j+1);
    }

}

int main() {
  cin >> s;
  cin >> t;
  n=s.length();
  m=t.length();

  memset(dp, -1, sizeof(dp));
  memset(best, 0, sizeof(best));
  
  int max_len = ans(0,0);
  string_gen(0,0);

  cout << total_ans << endl;
}