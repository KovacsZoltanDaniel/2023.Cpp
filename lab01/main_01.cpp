#include <iostream>
#include "functions.h"
int main() {
    for (int i = 0; i < 127; ++i) {
    std::cout << countBits(i) << std::endl;
    }
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            std::cout<<i<<" ---> " << n << std:: endl;
        }else{
            std:: cout<<"Impossible operation!" << std:: endl;
        }
    }
    double array[] = {1, 2, 3, 4, 5};
    std::cout << "mean: " << mean(array, 5) << std::endl;
    return 0;
}

