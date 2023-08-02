//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        queue<vector<int>> q;
        vector<vector<bool>> vis(N,vector<bool>(M,false));
        q.push({0,0,0});
        vis[0][0] = true;
        while(!q.empty()){
            vector<int> a = q.front();
            q.pop();
            if(a[0]==X && a[1]==Y){
                return a[2];
            }
            for(int i=0;i<4;i++){
                int nx = dx[i] + a[0];
                int ny = dy[i] + a[1];
                if(nx>=0 && nx<N && ny>=0 && ny<M && !vis[nx][ny] && A[nx][ny]==1){
                    vis[nx][ny] = true;
                    q.push({nx,ny,a[2]+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends