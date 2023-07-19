//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n = A.length();
        string s = A;
        string r = "";
        for(int i=n-1;i>=0;i--){
            r += A[i];
        }
        vector<vector<int>> lcs(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    lcs[i][j] = 0;
                }
                else if(s[i-1]==r[j-1]){
                    lcs[i][j] = 1+lcs[i-1][j-1];
                }
                else{
                    lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
                }
            }
        }
        return lcs[n][n];
    }
};


//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends