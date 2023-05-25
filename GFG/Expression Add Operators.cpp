//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void help(vector<string> &ans,string path,string num,int target,int ind,long p_val,int prev){
        if(ind==num.length()){
            // cout<<ind<<" "<<p_val<<endl;
            if(target==p_val) ans.push_back(path);
            return ;
        }
        for(int i=ind;i<num.length();i++){
            long curr = stoll(num.substr(ind,i-ind+1));
            if(num[ind]=='0') break;
            if(ind==0){
                help(ans,path+to_string(curr),num,target,i+1,curr,curr);
            }
            else{
                
                help(ans,path+"+"+to_string(curr),num,target,i+1,curr+p_val,curr);
                help(ans,path+"-"+to_string(curr),num,target,i+1,p_val-curr,-curr);
                help(ans,path+"*"+to_string(curr),num,target,i+1,p_val-prev+p_val*curr,prev*curr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.empty()) return ans;
        help(ans,"",num,target,0,0,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends