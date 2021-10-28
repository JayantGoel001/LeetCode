class Node{
  public:
    int val;
    Node *next;
    Node *down;
    
    Node(int data){
        this->val = data;
        this->next = nullptr;
        this->down = nullptr;
    }
};
class Skiplist {
public:
    Node *head;
    int mLevel;
    int randomLevel(){
        int ret = 1;
        while(rand() & 1){
            ++ret;
        }
        return ret;
    }
    
    Skiplist() {
        head = nullptr;
        mLevel = 0;
    }
    
    bool search(int target) {
        Node *node = head;
        
        while(node){
            while(node->next && node->next->val <= target){
                node = node->next;
            }
            if(node->val == target){
                break;
            }
            node = node->down;
        }
        return node && node->val == target;
    }
    
    void add(int num) {
        int level = randomLevel();
        
        if(level > mLevel){
            Node *temp = head;
            head = new Node(INT_MIN);
            head->down = temp;
            mLevel++;
        }
        Node *temp = head;
        Node *up = nullptr;
        
        while(temp){
            while(temp->next && temp->next->val < num){
                temp = temp->next;
            }
            if(level >= mLevel){
                Node *temp2 = temp->next;
                temp->next = new Node(num);
                temp->next->next = temp2;
                
                if(up){
                    up->down = temp->next;
                }
                up = temp->next;
            }
            temp = temp->down;
            ++level;
        }
    }
    
    bool erase(int num) {
        bool ret = false;
        Node *node = head;
        Node *delt = nullptr;
        
        while(node){
            if(!delt){
                while(node->next && node->next->val < num){
                    node = node->next;
                }
                if(node->next && node->next->val == num){
                    delt = node->next;
                    ret = true;
                }
            }
            if(delt){
                while(node->next != delt){
                    node = node->next;
                }
                Node *temp = node->next;
                delt = node->next->down;
                
                node->next = node->next->next;
                delete temp;
            }
            node = node->down;
        }
        return ret;
    }
};
