class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size(), c = s3.size();
        if (c != a + b) return false;
        bool dp[a+1][b+1];
        memset(dp, false, (a+1)*(b+1)*sizeof(bool));
        for(int i=0; i<=a; i++) {
            for(int j=0; j<=b; j++) {
                if(i == 0 and j == 0) 
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] and s2[j-1] == s3[i+j-1];
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] and s1[i-1] == s3[i+j-1];
                else
                    dp[i][j] = (dp[i][j-1] and s2[j-1] == s3[i+j-1]) or 
                    (dp[i-1][j] and s1[i-1] == s3[i+j-1]);
            }
        }
        return dp[a][b];
    }
};