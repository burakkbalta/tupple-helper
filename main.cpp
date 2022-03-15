#include <iostream>
#include <ostream>
#include <tuple>
#include "tuple_helper.h"

int main()
{
    std::cout << "Hello World C++17 gcc" << std::endl;

    std::tuple tup {15, 20.6, "tuple_print"};
    using namespace bb::tuple_helper;
    std::cout << tup << "\n";

    auto val = isExistInTuple(tup, 15);
    std::cout << std::boolalpha << val << "\n";
    
    val = isExistInTuple(tup, 20.6);
    std::cout << std::boolalpha << val << "\n";

    val = isExistInTuple(tup, "tuple_print");
    std::cout << std::boolalpha << val << "\n";

    return 0;
}