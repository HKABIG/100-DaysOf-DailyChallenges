//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int dx[] = {0,0,-1,1,-1,1,-1,1};
        int dy[] = {-1,1,0,0,-1,1,1,-1};
        int ans = 0;
        int c=0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            c=0;
            for(int i=0;i<8;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(matrix[nx][ny]==0){
                        c++;
                    }
                }
            }
            if(c%2==0 and c!=0) ans++;
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends