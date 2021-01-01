#include <cstdio>
#include "type_sequence_test.h"

int main(int /*argc*/, char */*argv*/[])
{
    std::printf("meta-test is a compilable test\n");

    using namespace meta_test;
    type_sequence_test();
}
