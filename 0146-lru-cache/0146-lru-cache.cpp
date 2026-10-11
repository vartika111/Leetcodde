class LRUCache {
    private:
    struct Node 
    {   int key;
        int value;
        Node* prev;
        Node* next;

        //Default Constructor
        Node()
        {
            key=0;
            value=0;
            prev=nullptr;
            next=nullptr;
        }

        //parameterized constructor(when kay an dvalue is passed)
        Node(int k , int v)
        {
            key=k;
            value=v;
            prev=nullptr;
            next=nullptr;

        }

       

    };

    // LRUcache(key)
    // {
    //     this.key=key;
    //     this.value=value;
    //     this.prev=NULL;
    //     this.next=NULL;

    // }
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>cache;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        cache.clear();
        head=new Node();
        tail= new Node();
        head->next=tail;
        tail->prev=head;

        
    }
     void deleteNode(Node*node)
        {
              Node* prevNode= node->prev;
              Node* afterNode= node->next;

              prevNode->next=afterNode;
              afterNode->prev=prevNode;
        }


        
        void insertAtFront(Node*node)
        {
           
            //dummy head and tail
            Node* curAfterHead= head->next;
            head->next=node;
            node->next=curAfterHead;
            node->prev= head;
            curAfterHead->prev=node;
            

        }


    int get(int key) {
        if(cache.find(key)==cache.end())
        {
            //key not present
            return -1;
        }
        Node* node= cache[key];
        //delete the node
        deleteNode(node);
        insertAtFront(node);

        return node->value;
        
    }
    
    void put(int key, int value) {

        if(cache.find(key)!=cache.end())
        {
            //key presennt 
            //delete and add to front in linked list 
            Node* foundNode=cache[key];
            foundNode->value=value;
            deleteNode(foundNode);
            insertAtFront(foundNode);

        }
        else
        {
            if(cache.size()==capacity)
            {
                Node* node= tail->prev;
                deleteNode(node);
                cache.erase(node->key);
                delete node;
            }
            Node* node= new Node(key,value);
            cache[key]=node;
            insertAtFront(node);

        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */