#define ll long long int
class Solution {
public:
    int N,Goal,K;
    int mod = 1e9+7;
    ll dp[101][101];
    ll solve(int usedSong,int currL){
        if(currL==Goal)
            return usedSong==N;
        if(dp[usedSong][currL]!=-1) return dp[usedSong][currL];
        ll usedSongPlay = (solve(usedSong,currL+1)*max(0,usedSong-K))%mod;
        ll newSongPlay = (solve(usedSong+1,currL+1)*(N-usedSong))%mod;
        ll total = (usedSongPlay + newSongPlay)%mod;

        return dp[usedSong][currL] = total%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        this->N = n;
        this->Goal = goal;
        this->K = k;
        memset(dp,-1,sizeof(dp));
        return (int) solve(0,0);
    }
};