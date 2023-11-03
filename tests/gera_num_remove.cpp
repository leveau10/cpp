#include <iostream>
#include <random>

int main(int argc, char** argv) {
    if (argc !=2 ){
        std::cout << "Error: Need to inform 'n'\n";
        exit(1);
    }
    int n = std::stoi(argv[1]);
    std::string zero;
    std::random_device rd;
    std::mt19937 mt(rd());

    std::cout << n << "\n";
    std::uniform_int_distribution<> dist1(1, n*2);
    for (int i=0 ; i<n ; ++i)
        std::cout << dist1(mt) << "\n";

    std::cout << n << "\n";
    std::uniform_int_distribution<> dist2(0, n-1);
    for (int i=0 ; i<n ; ++i)
        std::cout << dist2(mt) << "\n";
    return 0;
}