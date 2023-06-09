//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void permutationHelper(vector<string> &res,int index,string &s){
	        if(index==s.length()){
	            if(find(res.begin(),res.end(),s)==res.end())
	                res.push_back(s);
	        }
	        for(int i=index;i<s.length();i++){
	            swap(s[i],s[index]);
	            permutationHelper(res,index+1,s);
	            swap(s[i],s[index]);
	        }
	    }
		vector<string> find_permutation(string s){
		    int n = s.length();
		    vector<string> res;
		    permutationHelper(res,0,s);
		    sort(res.begin(),res.end());
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends