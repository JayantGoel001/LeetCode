class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class MyLinkedList {
public:
    Node *head;
    int size;
    
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index <= size){
            Node *temp = head;
            
            while(temp && index-- > 0){
                temp = temp->next;
            }
            return temp ? temp->data : -1;
        }else{
            return -1;
        }
    }
    void addAtHead(int val) {
        if(head){
            Node *next = head;
            head = new Node(val);
            next->prev = head;
            head->next = next;
        }else{
            head = new Node(val);
        }
        size++;
    }
    
    void addAtTail(int val) {
        if(head){
            Node *tail = head;
            while(tail->next){
                tail = tail->next;
            }
            
            Node *node = new Node(val);
            node->prev = tail;
            tail->next = node;
        }else{
            head = new Node(val);
        }
        size++;
    }
    void display(){
        Node *temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    void addAtIndex(int index, int val) {
        if(index < size){
            Node *temp = head;
            while(temp && index-- > 0){
                temp = temp->next;
            }
            Node *prev = temp->prev;
            if(prev){
                Node *next = temp;

                Node *node = new Node(val);
                next->prev = node;
                node->prev = prev;
                node->next = next;

                prev->next = node;
            }else{
                addAtHead(val);
            }
            size++;
        }else if(index == size){
            addAtTail(val);
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < size){
            Node *temp = head;
            while(temp && index-- > 0){
                temp = temp->next;
            }
            
            Node *prev = temp->prev;
            Node *next = temp->next;
            if(prev){
                prev->next = next;
                if(next){
                    next->prev = prev;
                }
            }else{
                head = head->next;
                if(head){
                    head->prev = nullptr;
                }
            }
            size--;
        }
    }
};