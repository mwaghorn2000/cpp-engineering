#include <cassert>
#include <iostream>
#include <q8_8.h>

void q8_8_tests();
void test_framework(float E, float R);

int main() {
    std::cout << "Hello C++ development environment!" << std::endl;
    std::cout << "Running Tests!..." << std::endl;
    q8_8_tests();
    return 0;
}

void q8_8_tests() {
    q8_8 test = q8_8(0x8180);
    float result = test.toFloat();
    float expected = -1.5f;
    test_framework(expected, result);

    test = q8_8(0x4061);
    result = test.toFloat();
    expected = 64.3789;
    test_framework(expected, result);
}

void test_framework(const float E, const float R) {
    std::cout << "R: " << R << " E: " << E;
    if (R != E) {
        assert(false);
    }
    std::cout << " ....   Passed" << std::endl;
}