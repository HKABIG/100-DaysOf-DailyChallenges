//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool help(int i,int j,int len,vector<vector<char>>& b, string w){
        if(len==w.size()) return true;
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size()){
            return false;
        }
        if(b[i][j]!=w[len]){
            return false;
        }
        b[i][j] = '*';
        return help(i+1,j,len+1,b,w) || help(i,j+1,len+1,b,w) || help(i-1,j,len+1,b,w) || help(i,j-1,len+1,b,w);
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && help(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends