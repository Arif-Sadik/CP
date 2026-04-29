#include <bits/stdc++.h>
using namespace std;

/**
 * Function: lcs
 * ----------------------------
 * Finds the length of the Longest Common Subsequence using Dynamic Programming.
 * This implementation uses vectors for dynamic memory allocation.
 * * s: The first input string (size n)
 * t: The second input string (size m)
 */
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    // Create a 2D vector (DP table) of size (n+1) x (m+1)
    // dp[i][j] will store the LCS of s1[0...i-1] and s2[0...j-1]
    // All elements are initialized to 0.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialization: The LCS of any string with an empty string is 0.
    // Fill the first row (i=0) with zeros.
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    // Fill the first column (j=0) with zeros.
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    // Iteratively fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            
            // Case 1: Characters match
            // We take the result from the diagonal (dp[i-1][j-1]) and add 1.
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            
            // Case 2: Characters do NOT match
            // We take the maximum value from either the cell above or the cell to the left.
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The result for the full strings s1 and s2 is in the last cell
    return dp[n][m];
}

int main() {
    // Example usage
    string s1 = "ABCDG";
    string s2 = "BDCAG";

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;

    int result = lcs(s1, s2);

    cout << "Length of LCS: " << result << endl;

    return 0;
}