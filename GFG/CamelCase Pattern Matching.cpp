//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    vector<int> al;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

void insert(string word,TrieNode* root){
     TrieNode temp = NULL;
     for(int i=0;i<word.length();i++){
         temp = root;
         for(int j=0;j<word[i].length();j++){
             char ch = word[i][j];
             if(ch>='A' && ch<='Z'){
                 if(temp->children[ch-'A']==NULL){
                     temp->children[ch-'A'] = new TrieNode();
                 }
                 temp = temp->children[ch-'A'];
             }
         }
         temp->al.push_back(word[i]);
     }
}

int find(string s,TrieNode* root){
    for(int i=0;i<s.length();i++){
        if(root->children[s[i]-'A']==NULL){
            return 0;
            root = root->children[s[i]-'A'];
        }
    }
    printAllword(root);
    return 1;
}

void printAllword(TrieNode* root){
    for(string str:root->al) ans.add(str);
    for(int i=0;i<26;i++){
        TrieNode* child = root->children[i];
        if(child!=NULL) printAllword(child);
    }
}

class Solution {
   public:
    vector<String> ans;
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        TrieNode* root = new TrieNode();
        insert(Dictionary,root);
        find(Pattern,root);
        sort(ans.begin(),ans.end());
        if(ans.length()==0) ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends