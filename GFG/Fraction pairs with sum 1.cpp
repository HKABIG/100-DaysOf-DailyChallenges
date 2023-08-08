//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[]){
        int cnt = 0;
        // vector<double> v;
        // for(int i=0;i<n;i++){
        //     auto frac = (double)numerator[i]/denominator[i];
        //     v.push_back(frac);
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(v[i]+v[j]==1.0){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        int j=n-1;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            double frac = (double)numerator[i]/denominator[i];
            double target = 1.0-frac;
            string key = to_string(frac);
            cnt += mp[key];
            mp[to_string(target)]++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends