#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_list {
private:
    int* data;
    unsigned int size_, capacity_, increase_;

    void increase_capacity() {  // Método que aumenta a capacidade reservada dinamicamente;   //  O(N)
        if(this->increase_ == 8){
            this->capacity_= this->capacity_*2;
        }else{
            this->capacity_+= this->increase_;
        }
        int* new_array = new int[this->capacity_];
        for (unsigned int i = 0; i < this->size_; i++){
                new_array[i] = data[i];
            }
        int* old_array = data;
        delete [] old_array;
        data = new_array;
        
    } 
public:
    array_list() { // Construtor // O(1)
        data = new int[100];
        this->size_ = 0;
        this->capacity_ = 100;
        this->increase_ = 100;
    }
    array_list(unsigned int cpcty){  // Construtor // O(1)
        data = new int[cpcty];
        this->size_ = 0;
        this->capacity_ = cpcty;
        this->increase_ = cpcty;
    }
    ~array_list() {  // Destrutor   // O(1)
        delete[] data;
    }
    unsigned int size() { // Método que retorna o tamanho atual da lista // O(1)
        return this->size_;
    }
    unsigned int capacity() {   // Método que retorna o espaço reservada dinamicamente; // O(1)
        return this->capacity_;
    }
    double percent_occupied() {  // Método que retorna a porcentagem ocupada do espaço reservado dinamicamente; // O(1)
        double size = this->size_;
        return size/this->capacity_;
    }
    bool insert_at(unsigned int index, int value) { // Método que insere um novo valor na posição desejada e atualiza o atributo tamanho;  // O(N)
        if (this->size_ == this->capacity_)
            increase_capacity();
        for (unsigned int i = 0; i < this->size_+1; i++){
            if (i == index){
                for (unsigned int j  = this->size_+1; j > i; j--)
                {

                    data[j] = data[j-1];
                }
                data[i] = value;
                this->size_++;
                return true;
            }
        }
        return false;
    }
    bool remove_at(unsigned int index) { // Método que remove o valor armazenado no index informado e atualiza o atributo tamanho;  //  O(N)
        if (index >= this->size_)
            return false; // Não removeu
        for (unsigned int i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { //   Método que retorna o valor armazenado no index fornecido;  //  O(1)
        if (index >= this->size_){
            return false;
        }
        return this->data[index];
    }
    void clear() {  // Método que zera o atributo tamanho da lista;   // O(1)
        this->size_ = 0;
    }
    void push_back(int value) { // Método que insere um novo valor no FIM da lista e atualiza o atributo tamanho;  // O(1)
        if (this->size_ == this->capacity_)
            increase_capacity();
        this->data[size_++] = value;
    }
    void push_front(int value) { // Método que insere um novo valor no INÍCIO da lista e atualiza o atributo tamanho;  // O(N)
        if(this->size_ == this->capacity_)
            increase_capacity();
        for (unsigned i = this->size_; i > 0; i--){
            data[i] = data[i-1];
        }
        data[0] = value;
        this->size_++;
    }
    bool pop_back() { // Método que remove o último valor da lista e atualiza o atributo tamanho;  // O(1)
        if(this->size_>0){
            this->size_--;
            return true;
        }
        return false;
    }
    bool pop_front() { // Método que remove o primeiro valor da lista e atualiza o atributo tamanho;  // O(N)
        if (this->size_ > 0){
            for (unsigned int i = 0; i < this->size_; i++){
                data[i] = data[i+1];
            }
            this->size_--;
            return true;
        }
        return false;
    }
    int front(){ // Método que retorna o valor armazenado na primeira posição da lista;  // O(1)
        return data[0];
    } 
    int back(){ // Método que retorna o valor armazenado na última posição da lista;  // O(1)
        return data[this->size_-1];
    }
    bool remove(int value) { // Método que checa se o valor fornecido está presente na lista. Se estiver ele será removido;  // O(N)
        if (this->size_ == 0){
            return false;
        }
        for (unsigned int i = 0; i < this->size_; i++){
            if (data[i] == value){
                for (unsigned int j = i; j < this->size_; j++){
                    data[j] = data[j+1];
                }
                this->size_--;
                return true;
            }
        }
        return false;
    }
    int find(int value) { // Método que checa se um valor está presente e retorna o seu índice;  // O(N)
        for (unsigned int i = 0; i < this->size_; i++){
            if (data[i] == value) {
                return i;
            }
            
        }
        return -1;
    }
    int count(int value) { // Método que conta a quantidade de vezes que um valor se repete na lista ;  // O(N)
        int count = 0;
        for (unsigned int i = 0; i < this->size_; i++){
            if(data[i] == value){
                count++;
            }
        }
        
        return count;
    }
    int sum() { // Método que soma todos os valores armazenados na lista ;  // O(N)
        int sum = 0;
        for (unsigned int i = 0; i < this->size_; i++){
            sum+= data[i];
        }
        return sum;
    }
};
#endif // __ARRAY_LIST_IFRN__