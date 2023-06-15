
class Solution {
    public void dfs(TreeNode root,int level,List<Integer> sumOfNodes){
        if(root==null) return ;
        if(sumOfNodes.size()==level) sumOfNodes.add(root.val);
        else{
            sumOfNodes.set(level,sumOfNodes.get(level)+root.val);
        }
        dfs(root.left,level+1,sumOfNodes);
        dfs(root.right,level+1,sumOfNodes);
    }
    public int maxLevelSum(TreeNode root) {
        List<Integer> sumOfNodes = new ArrayList<>();
        dfs(root,0,sumOfNodes);
        int maxSum = Integer.MIN_VALUE;
        int ans = 0;
        for(int i=0;i<sumOfNodes.size();i++){
            int currSum = sumOfNodes.get(i);
            if(currSum>maxSum){
                maxSum = currSum;
                ans = i+1;
            }
        }
        return ans;
    }
}