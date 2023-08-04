class Solution {
public:
    bool help(int ind,string s,set<string>& ans,vector<int>& dp){
        if(ind==s.length()) return true;
        string temp;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<s.length();i++){
            temp += s[i];
            if(ans.find(temp)!=ans.end()){
                if(help(i+1,s,ans,dp)) return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string> ans;
       for(auto it:wordDict) ans.insert(it);
       vector<int> dp(s.length()+1,-1);
       return help(0,s,ans,dp); 
    }
};