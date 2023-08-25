class Solution {
public:
    map<string,bool> dp;
    bool check(string s1,string s2,string s3,int len1,int len2,int len3,int p1,int p2,int p3){
        if(p3==len3)
            return (p1==len1 and p2==len2)?true:false;
        string key = to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(dp.find(key)!=dp.end())
            return dp[key];
        if(p1==len1){
            return dp[key] = s2[p2]==s3[p3]?check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1):false;
        }
        if(p2==len2){
            return dp[key] = s1[p1]==s3[p3]?check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1):false;
        }
        bool one=false,two=false;
        if(s1[p1]==s3[p3])
            one = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3])
            two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
        return dp[key] = one || two;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len3 != len1+len2){
            return false;
        }
        //return check(s1,s2,s3,len1,len2,len3,0,0,0);
        vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,false));
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                int l = i+j-1;
                if(i==0 && j==0){
                    dp[i][j] = true;
                }
                else if(i==0){
                    if(s3[l]==s2[j-1]){
                        dp[i][j] = dp[i][j-1];
                    }
                }
                else if(j==0){
                    if(s3[l]==s1[i-1]){
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else{
                    dp[i][j] = (s3[l]==s1[i-1]?dp[i-1][j]:false) || (s3[l]==s2[j-1]?dp[i][j-1]:false);
                }
            }
        }
        return dp[len1][len2];
    }
};