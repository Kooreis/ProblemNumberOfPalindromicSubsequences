```cpp
#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

int countPalindromicSubsequences(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> next(n, 0);
    vector<int> prev(n, 0);
    vector<int> seen(26, -1);

    for (int i = 0; i < n; ++i) {
        if (seen[s[i] - 'a'] >= 0)
            prev[i] = seen[s[i] - 'a'];
        else
            prev[i] = -1;
        seen[s[i] - 'a'] = i;
    }

    seen = vector<int>(26, -1);

    for (int i = n - 1; i >= 0; --i) {
        if (seen[s[i] - 'a'] >= 0)
            next[i] = seen[s[i] - 'a'];
        else
            next[i] = -1;
        seen[s[i] - 'a'] = i;
    }

    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

    for (int size = 1; size < n; ++size) {
        for (int i = 0; i + size < n; ++i) {
            int j = i + size;
            if (s[i] != s[j])
                dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + MOD) % MOD;
            else {
                if (next[i] > prev[j])
                    dp[i][j] = (2 * dp[i + 1][j - 1] + 2) % MOD;
                else if (next[i] == prev[j])
                    dp[i][j] = (2 * dp[i + 1][j - 1] + 1) % MOD;
                else
                    dp[i][j] = (2 * dp[i + 1][j - 1] - dp[next[i] + 1][prev[j] - 1] + MOD) % MOD;
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;
    cout << countPalindromicSubsequences(s) << endl;
    return 0;
}
```