class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> prev(n+1);
        for(int i=m-1;i>=0;i--){
            int last = 0;
            for(int j=n-1;j>=0;j--){
                auto temp = prev[j];
                if(text1[i] == text2[j]) prev[j] = 1 + last;
                else prev[j] = max(prev[j], prev[j+1]);
                last = temp;
            }
        }
        return prev[0];        
    }
};