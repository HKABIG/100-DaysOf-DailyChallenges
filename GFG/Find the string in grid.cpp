//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

    int dx[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int dy[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
class Solution {
public:
    bool searchWord(int row,int col,vector<vector<char>>grid, string word){
        if(grid[row][col]!=word[0]) return false;
        int len = word.length();
        for(int i=0;i<8;i++){
            int x = dx[i]+row,y = dy[i]+col,k;
            for(k=1;k<len;k++){
                if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) 
                    break;
                if(grid[x][y]!=word[k])
                    break;
                x += dx[i];y += dy[i];
            }
            if(k==len){
                //cout<<"SUCCESS"<<endl;
                return true;   
            }
        }
        //cout<<"FAIL"<<endl;
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>> ans;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(searchWord(i,j,grid,word)){
	                ans.push_back({i,j});
	            }
	        }
	    }
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends