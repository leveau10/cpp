
#include "array_list.hpp"
#include <iostream>

int main()
{
    array_list lista1(1000);
    for (int i = 0; i < 2049; i++)
    {
        lista1.push_back(i);
    }
    int size = lista1.size();
    std::cout << "Size: " << size << std::endl;
    std::cout << "Soma: " << lista1.sum() << std::endl;
    std::cout << "Count: " << lista1.count(2) << std::endl;
    std::cout << "Find: " << lista1.find(1) << std::endl;
    std::cout << "Capacidade: " << lista1.capacity() << std::endl;
    std::cout << "Porcentagem Usada: " << lista1.percent_occupied() << std::endl;
    std::cout << "Valor: " << lista1.get_at(2) << std::endl;
    std::cout << "lista1 = { ";
    for (int i=0 ; i< size; i++){
        // std::cout << lista1.front() << " ";
        lista1.pop_front();
    }
    std::cout << "}" << std::endl;
    return 0;
}