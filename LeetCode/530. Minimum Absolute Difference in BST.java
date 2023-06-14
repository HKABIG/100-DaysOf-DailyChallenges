
class Solution {
    ArrayList<Integer> tree = new ArrayList<>();
    void inorder(TreeNode root){
        if(root==null) return ;
        inorder(root.left);
        tree.add(root.val);
        inorder(root.right);
    }
    public int getMinimumDifference(TreeNode root) {
        inorder(root);
        int mx = Integer.MAX_VALUE;
        for(int i=1;i<tree.size();i++){
            mx = Math.min(mx,tree.get(i)-tree.get(i-1));
        }
        return mx;
    }
}