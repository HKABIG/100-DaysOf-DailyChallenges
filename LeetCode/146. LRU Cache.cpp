class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;
            node(int _key,int _val){
                key = _key;
                val = _val;
            }
    };
    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);
    int k;
    unordered_map<int,node*> map;
    LRUCache(int capacity) {
        k = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    int get(int key) {
        if(map.find(key)!=map.end()){
            node* resnode = map[key];
            int res = resnode->val;
            map.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            map[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            node* resnode = map[key];
            map.erase(key);
            deleteNode(resnode);
        }
        if(map.size()==k){
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */