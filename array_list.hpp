#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__


class array_list {
private:
    int* data;
    unsigned int size_, capacity_, tam_;
    void increase_capacity() {
        this->tam_ += this->tam_;
        this->capacity_= this->tam_;
        int* new_array = new int[this->capacity_];
        for (unsigned int i = 0; i < this->size_; i++){
            new_array[i] = data[i];
        }
        int* old_array = data;
        delete [] old_array;
        data = new_array;
    } 
public:
    array_list() {
        this->tam_ = 100;
        data = new int[this->tam_];
        this->size_ = 0;
        this->capacity_ = tam_;
    }
    ~array_list() {
        delete[] data;
    }
    unsigned int size() {
        return this->size_;
    }
    unsigned int capacity() {
        return this->capacity_;
    }
    double percent_occupied() {
        double size = this->size_;
        return size/this->capacity_;
    }
    bool insert_at(unsigned int index, int value) {
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
    bool remove_at(unsigned int index) {
        if (index >= this->size_)
            return false; // Não removeu
        for (unsigned int i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) {
        if (index >= this->size_){
            return false;
        }
        
        // TODO: Check if index is valid
        return this->data[index];
    }
    void clear() {
        this->size_ = 0;
    }
    void push_back(int value) {
        if (this->size_ == this->capacity_)
            increase_capacity();
        this->data[size_++] = value;
    }
    void push_front(int value) {
        if(this->size_ == this->capacity_)
            increase_capacity();
        for (unsigned i = this->size_; i > 0; i--){
            data[i] = data[i-1];
        }
        data[0] = value;
        this->size_++;
    }
    bool pop_back() {
        if(this->size_>0){
            this->size_--;
            return true;
        }
        return false;
        
    }
    bool pop_front() {
        if (this->size_ > 0){
            for (unsigned int i = 0; i < this->size_; i++){
                data[i] = data[i+1];
            }

            this->size_--;
            return true;
            
        }
        return false;
        
    }
    int front(){
        return data[0];
    }
    int back(){
        return data[this->size_-1];
    }
    bool remove(int value) {
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
    int find(int value) {
        for (unsigned int i = 0; i < this->size_; i++){
            if (data[i] == value) {
                return i;
            }
            
        }
        return -1;
    }
    int count(int value) {
        int count = 0;
        for (unsigned int i = 0; i < this->size_; i++){
            if(data[i] == value){
                count++;
            }
        }
        
        return count;
    }
    int sum() {
        int sum = 0;
        for (unsigned int i = 0; i < this->size_; i++){
            sum+= data[i];
        }
        return sum;
    }
};

#endif // __ARRAY_LIST_IFRN__