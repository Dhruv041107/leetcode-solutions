class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key, int _val) {
            key = _key;
            val = _val;
            prev = nullptr;
            next = nullptr;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        head->next = newnode;
        newnode->prev = head;
        temp->prev = newnode;
    }

    void deletenode(node* current) {
        node* currprev = current->prev;
        node* currnext = current->next;
        currprev->next = currnext;
        currnext->prev = currprev;
    }

    int get(int key_) {
        if (mp.find(key_) != mp.end()) {
            node* resnode = mp[key_];
            int res = resnode->val;
            mp.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value_) {
        if (mp.find(key_) != mp.end()) {
            node* currnode = mp[key_];
            mp.erase(key_);
            deletenode(currnode);
        }

        if (mp.size() == cap) {
            node* todelete = tail->prev;
            mp.erase(todelete->key);
            deletenode(todelete);
        }

        addnode(new node(key_, value_));
        mp[key_] = head->next;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */