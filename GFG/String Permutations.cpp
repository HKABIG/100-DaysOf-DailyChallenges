//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int ind,string s,vector<string>& ans){
        if(ind==s.length()){
            ans.push_back(s);
            return ;
        }
        for(int i=ind;i<s.length();i++){
            swap(s[i],s[ind]);
            solve(ind+1,s,ans);
            swap(s[i],s[ind]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> ans;
        solve(0,S,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends