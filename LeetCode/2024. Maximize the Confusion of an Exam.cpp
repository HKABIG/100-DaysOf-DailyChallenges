class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int i=0,j=0,Tc=0,Fc=0;
        int ans = INT_MIN;
        while(i<n){
            if(answerKey[i]=='T') Tc++;
            else Fc++;
            i++;
            while(min(Tc,Fc)>k){
                if(answerKey[j]=='T') Tc--;
                else Fc--;
                j++;
            }
            ans = max(ans,i-j);
        }
        return ans;
    }
};