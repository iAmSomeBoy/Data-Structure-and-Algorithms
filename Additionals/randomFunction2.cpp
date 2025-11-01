#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    
    // Random number between 0 and 9
    int zeroToNine = rand() % 10;
    std::cout << "0-9: " << zeroToNine << std::endl;
    
    // Random number between 1 and 10
    int oneToTen = (rand() % 10) + 1;
    std::cout << "1-10: " << oneToTen << std::endl;
    
    // Random number between 5 and 15
    int fiveToFifteen = (rand() % 11) + 5;  // 11 numbers from 5 to 15
    std::cout << "5-15: " << fiveToFifteen << std::endl;
    
    // Random number between -10 and 10
    int negToPos = (rand() % 21) - 10;  // 21 numbers from -10 to 10
    std::cout << "-10 to 10: " << negToPos << std::endl;
    
    return 0;
}