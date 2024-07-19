#include <climits>
#include <iostream>

int main() {
    std::cout << "Minimum value for signed char: " << SCHAR_MIN << std::endl;
    std::cout << "Maximum value for signed char: " << SCHAR_MAX << std::endl;
    std::cout << "Minimum value for unsigned char: " << 0 << std::endl;
    std::cout << "Maximum value for unsigned char: " << UCHAR_MAX << std::endl;
    std::cout << "Minimum value for int: " << INT_MIN << std::endl;
    std::cout << "Maximum value for int: " << INT_MAX << std::endl;

    return 0;
}
