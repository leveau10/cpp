#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:

    linked_list() {
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }

    ~linked_list() {
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }

    unsigned int size() {
        return size_;
    }

    // unsigned int capacitty() {}

    // double percent_occupied() {}

    bool insert_at(unsigned int index, int value) {
        if(index > this->size_){
            return false;
        }
        
        int_node *current = this->head;
        for (unsigned int i = 0; i < index; i++){            
            current = current->next;
        }
        if (current == this->head){
            push_front(value);
        }else if( this->size_ == index){
            push_back(value);
        }else{
            int_node* new_node = new int_node;
            new_node->value = value;    
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
            this->size_++;
        }
        return true;
        
    }

    bool remove_at(unsigned int index) {
        if (index >= this->size_)
            return false; // Não removeu
        int_node* to_remove = this->head;
        for (unsigned int i = 0; i < index; ++i)
            to_remove = to_remove->next;
        if (to_remove->prev != nullptr)
            to_remove->prev->next = to_remove->next;
        if (to_remove->next != nullptr)
            to_remove->next->prev = to_remove->prev;
        delete to_remove;
        this->size_--;
        return true; // Removeu
    }

    int get_at(unsigned int index) { //TESTADO OK
        if (this->size_ == 0 || index >= size_)
        {
            return -1;
        }
        
        int_node *current = this->head;
        for (unsigned int i = 0; i < index; i++)
        {
            current = current->next;
            
        }
        return current->value;
    }

    void clear() { // TESTADO OK
        size_ = 0;
    }

    void push_back(int value) { // TESTADO OK
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;
        if(this->head == nullptr){
            this->head = new_node;
        }else{
            this->tail->next = new_node;
        }
        this->tail = new_node;
        this->size_++;
    }

    void push_front(int value) { //TESTADO OK
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
        this->size_++;
    }

    bool pop_back() { //TESTADO OK
        if(this->tail == 0){
            return false;
        }
        if(this->tail == this->head){
            delete this->tail;
            this->tail = 0;
            this->head = 0;
        }else{
            int_node *to_remove = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = 0;
            delete to_remove;
        }
        this->size_--;
        return true;
    }

    bool pop_front() {      //TESTADO OK
        if(this->head == 0){
            return false;
        }
        int_node *to_remove = this->head;
        if (this->tail==this->head){
            this->tail = 0;
            this->head = 0;
            return true;
        }
        this->head = this->head->next;
        this->head->prev = 0;
        delete to_remove;
        this->size_--;
        return true;
    }

    int front() { //TESTADO OK
        if (this->head != 0)
            return this->head->value;
        else
            return -1;
    }

    int back() { //TESTADO OK
        if (this->tail != 0)
            return this->tail->value;
        else
            return -1;
    }

    bool remove(int value) {
        int_node *current = this->head;
        int size = this->size_;
        for (int i = 0; i < size; i++){
            if (current->value == value){
                if (i==0){
                    this->head = this->head->next;
                    this->head->prev = 0;
                }else if(i == size-1){
                    this->tail = this->tail->prev;
                    this->tail->next = 0;
                }else{
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                }
                this->size_--;
                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int find(int value) { // TESTADO OK;
        int_node *current = this->head;
        int size = this->size_;
        for (int i = 0; i < size; i++)
        {
            if(current->value == value){
                return i;
            }
            current = current->next;
        }
    
        return -1;
    }

    int count(int value) { //TESTADO OK
        int count = 0;
        int size = this->size_;
        int_node *current = this->head;
        for (int i = 0; i < size; i++)
        {
            if (current->value == value)
            {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    int sum() { // TESTADO OK
        int sum = 0;
        int_node *current = this->head;
        int size = this->size_;
        for (int i = 0; i < size; i++)
        {
            sum+= current->value;
            current = current->next;
        }
        return sum;
    }
};


#endif // __LINKED_LIST_IFRN__