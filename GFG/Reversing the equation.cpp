//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s){
        int n = s.length();
        stack<string> st;
        int i=0;
        while(i<n){
            string num = "";
            num += s[i];
            //cout<<num<<" ";
            if(num>="0" && num<="9"){
                i++;
                while(s[i]>='0' && s[i]<='9'){
                    num+=s[i];
                    i++;
                }
                i-=1;
                //cout<<num<<" ";
            }
            st.push(num);
            i++;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends