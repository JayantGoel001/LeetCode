class Node {
    public:
    int key;
    int data;
    Node *next;
    Node *prev;

    Node(int key, int data) {
        this->key = key;
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class LRUCache {
    Node *head;
    Node *tail;
    unordered_map<int, Node*> mp;
    int capacity;

    void addNode(Node *node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void deleteNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        this->head->next = tail;
        this->tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node *node = mp[key];
        
        deleteNode(node);
        addNode(node);

        return node->data;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            deleteNode(mp[key]);
        }

        Node *node = new Node(key, value);
        mp[key] = node;
        
        if (mp.size() > this->capacity) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */