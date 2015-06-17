
#include <sstream>
#include <iostream>
#include <gmp.h>

int main() {
    long long int x, max;
    std::stringstream ss1, ss2;
    ss1 << std::hex << "ffffffffffffffff";
    ss1 >> max;
    ss2 << std::hex << "-6000000000001f2d";
    ss2 >> x;
    // output it as a signed type
    max += 1;
    std::cout << static_cast<long long int>(max) << std::endl;
    std::cout << static_cast<long long int>(x) << std::endl;
}