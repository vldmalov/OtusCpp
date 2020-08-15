#include "header.h"

auto headerFunc(int a, int b) {
    return a + b;
}

void usageTest() {
    auto result = headerFunc(42, 43);
    (void)result;
}