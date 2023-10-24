#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    unsigned int n;
    std::cin >> n;
    linked_list l1;
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }
    auto beg = std::chrono::high_resolution_clock::now();
    int m = l1.size();
    unsigned int removed = 0, not_removed = 0;
    for (int i = 0; i < m; ++i) {
        if (l1.pop_front())
            removed++;
        else
            not_removed++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[DEBUG] Tried to pop " << m << " element(s)\n";
    std::cerr << "[DEBUG] pop " << removed << " element(s)\n";
    std::cerr << "[DEBUG] not popped " << not_removed << " element(s)\n";
    if (not (l1.size() == n - removed) or (not_removed + removed != m)) {
        std::cerr << "[ERROR] check remove_at method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << removed << " pops : "
        << elapsed.count() << std::endl;
    return 0;
}