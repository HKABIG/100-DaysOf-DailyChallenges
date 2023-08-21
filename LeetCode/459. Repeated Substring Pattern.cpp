class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // int n = s.length();
        // string pat = "";
        // for(int i=0;i<n/2;i++){
        //     pat += s[i];
        //     string ans = "";
        //     while(ans.length()<n){
        //         ans += pat;
        //     }
        //     if(ans==s) return true;
        // }
        // return false;
        string t = s + s;
        if(t.substr(1,t.size()-2).find(s)!=-1) return true;
        return false;
    }
};