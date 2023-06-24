	class Solution {
	public:
		vector<unordered_map<int,int>> dp;
		int f(int i,vector<int>& v, int d){
			if(i==v.size()){
				if(d==0){
					return 0;
				}
			  return INT_MIN;
			}

			if(dp[i].find(d)!=dp[i].end())return dp[i][d];

			int x = f(i+1,v,d);
			int y = v[i] + f(i+1,v,d+v[i]);
			int z = f(i+1,v,d-v[i]);

			return dp[i][d] = max({x,y,z});
		}
		int tallestBillboard(vector<int>& rods) {
			dp.assign(21,{});
			return f(0,rods,0);

		}
	};

//     class Solution {
//     int solve(int[] rods,int st1,int st2,int ind,int[][] dp){
//         if(dp[st1][st2]!=-1) return dp[st1][st2];
//         if(ind==rods.length){
//             return st1==st2 ? st1:0;
//         }
//         return dp[st1][st2] = Math.max(solve(rods,st1,st2,ind+1,dp),Math.max(solve(rods,st1+rods[ind],st2,ind+1,dp),solve(rods,st1,st2+rods[ind],ind+1,dp)));
//     }
//     int solveMem(int[] rods,int i,int st1,int st2,int sum,int[][] dp){
//         if(st1>sum || st2>sum) return -1;
//         if(i>=rods.length) return st1==st2?st1:-1;
//         if(dp[i][Math.abs(st1-st2)]!=-2) return dp[i][Math.abs(st1-st2)];
//         return dp[i][Math.abs(st1-st2)] = Math.max(-1,Math.max(solveMem(rods,i+1,st1,st2,sum,dp),Math.max(solveMem(rods,i+1,st1+rods[i],st2,sum,dp),solveMem(rods,i+1,st1,st2+rods[i],sum,dp))));
//     }
//     public int tallestBillboard(int[] rods) {
//         int n = rods.length;
//         int sum = 0;
//         for(int i:rods){
//             sum += i;
//         }
//         int [][] dp = new int[n+1][sum+1];
//         for(int i=0;i<=n;i++){
//             Arrays.fill(dp[i],-2);
//         }
//         // return solve(rods,0,0,0,sum,dp);
//         return solveMem(rods,0,0,0,sum,dp);
//     }
// }