#include <iostream>
#include <ostream>
#include <tuple>
#include "tuple_helper.h"

int main()
{
    std::tuple tup {16, 20.7, "tuple_print"};
    using namespace bb::tuple_helper;
    std::cout << tup << "\n";

    auto val = isExistInTuple(tup, 16);
    std::cout << std::boolalpha << val << "\n";
    
    val = isExistInTuple(tup, 20.7);
    std::cout << std::boolalpha << val << "\n";

    val = isExistInTuple(tup, "tuple_print");
    std::cout << std::boolalpha << val << "\n";

    return 0;
}