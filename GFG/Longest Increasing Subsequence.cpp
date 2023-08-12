//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int ind,int prev,int n,int a[],vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int len = 0 + solve(ind+1,prev,n,a,dp);
        if(prev == -1 || a[ind]>a[prev]){
            len = max(len,1+solve(ind+1,ind,n,a,dp));
        }
        return dp[ind][prev+1] = len;
    }
    int lowerBound(vector<int>& temp,int target){
        int l=0,h=temp.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(temp[mid]>=target){
                h= mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    int longestSubsequence(int n, int a[]){
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solve(0,-1,n,a,dp);
        // vector<int> dp(n,1);
        // int ans = INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(a[j]<a[i]){
        //             dp[i] = max(dp[i],1+dp[j]);
        //         }
        //     }
        //     ans = max(dp[i],ans);
        // }
        // return ans;
        vector<int> temp;
        int len = 1;
        temp.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>temp.back()){
                temp.push_back(a[i]);
                len++;
            }
            else{
                int ind = lowerBound(temp,a[i]);
                temp[ind] = a[i];
            }
        }
        return len;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends