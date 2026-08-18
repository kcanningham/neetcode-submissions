class Node {
    public :
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
};

class LRUCache {
private :
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insertAtHead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insertAtHead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insertAtHead(node);
            return;
        }
        else {
            if(cache.size() < cap) {
                Node* node = new Node(key, value);
                insertAtHead(node);
                cache[key] = node;
            } 
            else {
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                // delete(lru);
                Node* newNode = new Node(key, value);
                insertAtHead(newNode);
                cache[key] = newNode;
            }
        }
    }
};
