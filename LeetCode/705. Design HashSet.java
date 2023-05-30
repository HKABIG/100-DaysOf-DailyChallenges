class MyHashSet {
    int [] mp ;
    public MyHashSet() {
        mp = new int[1000001];
    }
    
    public void add(int key) {
        mp[key] = 1;
    }
    
    public void remove(int key) {
        mp[key] = 0;
    }
    
    public boolean contains(int key) {
        if(mp[key] == 1) return true;
        return false;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */