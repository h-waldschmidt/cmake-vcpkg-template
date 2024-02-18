#include "sublib_component.h"

#include <fmt/core.h>

namespace name::sublibrary {
void SubLibComponent::print(int a) { fmt::println("Some value: {}", a); }

int SubLibComponent::add(int a, int b) {
    print(a + b);
    return a + b;
}
}  // namespace name::sublibrary