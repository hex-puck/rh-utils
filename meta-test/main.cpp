#include <cstdio>
#include "type_at_test.h"
#include "type_sequence_test.h"

int main(int /*argc*/, char */*argv*/[])
{
    std::printf("meta-test is a compilable test\n");

    using namespace meta_test;
    type_at_test();
    type_sequence_test();
}
