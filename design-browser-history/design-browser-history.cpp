class Node{
  public:
    string data;
    Node *next;
    Node *prev;
    
    Node(string s){
        this->data = s;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class BrowserHistory {
public:
    Node *dll = nullptr;
    Node *cur = nullptr;
    BrowserHistory(string homepage) {
        dll = new Node(homepage);
        cur = dll;
    }
    
    void visit(string url) {
        Node *node = new Node(url);
        cur->next = node;
        node->prev = cur;
        cur = node;
    }
    
    string back(int step) {
        while(step && cur->prev){
            cur = cur->prev;
            step--;
        }
        return cur->data;
    }
    
    string forward(int step) {
        while(step && cur->next){
            cur = cur->next;
            step--;
        }
        return cur->data;
    }
};
