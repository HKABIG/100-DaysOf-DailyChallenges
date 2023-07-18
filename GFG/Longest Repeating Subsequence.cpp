//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
		    string s1 = str;
		    string s2 = str;
		    vector<vector<int>> lcs(n+1,vector<int>(n+1,0));
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=n;j++){
		            if(i==0 || j==0){
		                lcs[i][j] = 0;
		            }
		            else if(s1[i-1]==s2[j-1] && i!=j){
		                lcs[i][j] = 1 + lcs[i-1][j-1];
		            }
		            else{
		                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
		            }
		        }
		    }
		    return lcs[n][n];
		}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends