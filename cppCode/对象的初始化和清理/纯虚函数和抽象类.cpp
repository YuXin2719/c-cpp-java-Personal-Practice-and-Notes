#include <iostream>

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 5 && j == 5) {
                std::cout << "1";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}