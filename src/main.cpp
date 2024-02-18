#include <fmt/core.h>

#include "sublibrary/sublib_component.h"

int main() {
    fmt::print("Hello, world!\n");
    name::sublibrary::SubLibComponent sublib;
    int out = sublib.add(2, 3);
    return 0;
}