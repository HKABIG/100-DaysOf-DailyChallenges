//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution{
  public:
    /*You are required to complete below function */
    string sumResults(vector<vector<int>>& results){
        vector<int> answer = results.back();
        vector<int> newAnswer;
        results.pop_back();
        for(vector<int> result:results){
            newAnswer.clear();
            int carry = 0;
            for(int i=0;i<answer.size()||i<result.size();i++){
                int digit1 = i<result.size()?result[i]:0;
                int digit2 = i<answer.size()?answer[i]:0;
                int sum = digit1+digit2+carry;
                carry = sum/10;
                newAnswer.push_back(sum%10);
            }
            if(carry){
                newAnswer.push_back(carry);
            }
            answer = newAnswer;
        }
        string finalAnswer;
        for(int digit:answer){
            finalAnswer.push_back(digit+'0');
        }
        reverse(finalAnswer.begin(),finalAnswer.end());
        return finalAnswer;
    }
    vector<int> multiply(int numpointer,string& num1,char& num2){
        vector<int> result(numpointer,0);
        int carry = 0;
        for(char num:num1){
            int mul = (num2-'0')*(num-'0') + carry;
            carry = mul/10;
            mul = mul%10;
            result.push_back(mul);
        }
        if(carry){
            result.push_back(carry);
        }
        // for(int it:result){
        //     cout<<it;
        // }cout<<endl;
        return result;
    }
    string multiplyStrings(string str1, string str2) {
        bool neg1 = false;
        bool neg2 = false;
        for(char s:str1){
            if(s=='-'){
                neg1 = true;
            }
        }
        for(char s:str2){
            if(s=='-'){
                neg2 = true;
            }
        }
        string s1 ="",s2 = "";
        bool f = false;
        if(neg1){
            for(char num:str1){
                if(num!='0'){
                   f = true;
                }
               if(f && num!='-'){
                   s1.push_back(num);
               }
            }
        }else{
            s1 = str1;
        }
        f = false;
        if(neg2){
            for(char num:str2){
                if(num!='0'){
                   f = true;
                }
               if(f && num!='-'){
                   s2.push_back(num);
               }
            }
        }else{
            s2 = str2;
        }
       reverse(s1.begin(),s1.end());
       reverse(s2.begin(),s2.end());
       vector<vector<int>> results;
       for(int i=0;i<s2.size();i++){
           results.push_back(multiply(i,s1,s2[i]));
       }
       string ans = sumResults(results);
       string res = "";
       bool flag = false;
       for(char num:ans){
           if(num!='0'){
               flag = true;
           }
           if(flag){
               res.push_back(num);
           }
       }
       if((neg1==true && neg2==false)||(neg1==false && neg2==true)) res = "-"+res;
       return res;
    }

};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends