#include "sublib_component.h"

#include <gtest/gtest.h>

namespace name::sublibrary {
TEST(SubLibComponentTest, Add) {
    SubLibComponent sublib;
    int out = sublib.add(2, 3);
    EXPECT_EQ(out, 5);
}
}  // namespace name::sublibrary