#include <iostream>
#include <ostream>
#include <tuple>
#include "tuple_helper.h"

int main()
{
    std::tuple tup {19, 20.7, "tuple_print"};
    using namespace bb::tuple_helper;
    std::cout << tup << "\n";

    auto val = isExistInTuple(tup, 19);
    std::cout << std::boolalpha << val << "\n";
    
    val = isExistInTuple(tup, 20.7);
    std::cout << val << "\n";

    val = isExistInTuple(tup, "tuple_print");
    std::cout << val << "\n";

    val = isExistInTuple(tup, 25.8);
    std::cout << val << "\n";

    return 0;
}