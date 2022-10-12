// Author : Ritik Patil
// Date : 11/10/2022
// Time : 23:19
// Description : Added Famous OA round question with help of DP
/*Given A string, find the length of longest palindrome present in the string .*/

#include <bits/stdc++.h>
using namespace std;

/* Returns length of longest Palindrome Subsequence for a string */
int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    string s;
    cout << "Enter your string : ";
    cin >> s;

    cout << "Length of Longest Palindrome Subsequence is : " << longestPalindromeSubsequence(s);

    return 0;
}
