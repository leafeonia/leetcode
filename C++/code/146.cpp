class LRUCache {
public:
    struct Node{
        int key, value;
        Node* prev;
        Node* next;
        Node(): key(0), value(0), prev(nullptr), next(nullptr) {}
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        moveToHead(mp[key]);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if (!mp.count(key)) {
            Node* node = new Node(key, value);
            addToHead(node);
            mp[key] = node;
            size++;
            if (size > cap) {
                Node* todelete = deleteTail();
                mp.erase(todelete->key);
                delete todelete;
                size--;
            }
        } else {
            mp[key]->value = value;
            moveToHead(mp[key]);
        }
        
    }
    
    void addToHead(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->next = next;
        next->prev = node;
        node->prev = head;
    }
    
    Node* deleteTail() {
        Node* todelete = tail->prev;
        todelete->prev->next = tail;
        tail->prev = todelete->prev;
        return todelete;
    }
    
    void moveToHead(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        addToHead(node);
    }
    
    
    Node* head;
    Node* tail;
    int size;
    unordered_map<int, Node*> mp;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */