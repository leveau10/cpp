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
    linked_list() {  // Método construtor que inicializa os ponteiros zerados; // O(1)
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    ~linked_list() { // Método destrutor que deleta todos os ponteiros usados para nós;  // O(N)
        int_node* current = this->head; 
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() {  // Método que retorna o tamanho atual da lista;  // O(1)
        return size_;
    }

    // unsigned int capacitty() {} 
                                        // Nenhum desses dois métodos são possíveis de implementar em listas ligadas!!!
    // double percent_occupied() {}

    bool insert_at(unsigned int index, int value) { // Método que insere um novo nó na posição desejada e atualiza o atributo tamanho;  // O(N)
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
    bool remove_at(unsigned int index) { // Método que remove o nó presente no index informado e atualiza o atributo tamanho;  //  O(N)
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
    int get_at(unsigned int index) { //   Método que retorna o valor armazenado no nó que está no index fornecido;  //  O(N)
        if (this->size_ == 0 || index >= size_){
            return -1;
        }
        int_node *current = this->head;
        for (unsigned int i = 0; i < index; i++){
            current = current->next; 
        }
        return current->value;
    }
    void clear() { // Método que zera o atributo tamanho da lista;   // O(1)
        size_ = 0;
    }
    void push_back(int value) { // Método que insere um novo nó no FIM da lista e atualiza o atributo tamanho;  // O(1)
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
    void push_front(int value) { // Método que insere um novo nó no INÍCIO da lista e atualiza o atributo tamanho;  // O(1)
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
    bool pop_back() { // Método que remove um novo nó no FIM da lista e atualiza o atributo tamanho;  // O(1)
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
    bool pop_front() {  // Método que remove o nó no INÍCIO da lista e atualiza o atributo tamanho;  // O(1)
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
    int front() { // Método que retorna o valor armazenado no nó do INÍCIO da lista;  // O(1)
        if (this->head != 0)
            return this->head->value;
        else
            return -1;
    }
    int back() { // Método que retorna o valor armazenado no nó do FIM da lista;  // O(1)
        if (this->tail != 0)
            return this->tail->value;
        else
            return -1;
    }
    bool remove(int value) {    // Método que remove checa se o valor fornecido está presente na lista. Se estiver ele será removido;  // O(N)
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
    int find(int value) { // Método que checa se um valor está presente e retorna o seu índice;  // O(N)
        int_node *current = this->head;
        int size = this->size_;
        for (int i = 0; i < size; i++){
            if(current->value == value){
                return i;
            }
            current = current->next;
        }
        return -1;
    }
    int count(int value) { // Método que conta a quantidade de vezes que um valor se repete na lista ;  // O(N)
        int count = 0;
        int size = this->size_;
        int_node *current = this->head;
        for (int i = 0; i < size; i++){
            if (current->value == value){
                count++;
            }
            current = current->next;
        }
        return count;
    }
    int sum() { // Método que soma os valores em todos os nós da lista ;  // O(N)
        int sum = 0;
        int_node *current = this->head;
        int size = this->size_;
        for (int i = 0; i < size; i++){
            sum+= current->value;
            current = current->next;
        }
        return sum;
    }
};
#endif // __LINKED_LIST_IFRN__