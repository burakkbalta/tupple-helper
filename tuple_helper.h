#ifndef TUPLE_HELPER_H
#define TUPLE_HELPER_H

#include <ostream>
#include <tuple>

namespace bb {
namespace tuple_helper{

template<typename TupleT, std::size_t... Is>
std::ostream& printTupleImpl(std::ostream& os, const TupleT& tp, std::index_sequence<Is...>) {
    auto printElem = [&os](const auto& x, size_t id) {
        if(id > 0 ) {
            os << ", "; 
        }
        os << id << ": " << x;
    };
    os << "(";
    (printElem(std::get<Is>(tp), Is),...);
    os << ")";
    return os;
} 

template<typename TupleT, std::size_t TupSize = std::tuple_size<std::decay_t<TupleT>>::value>
std::ostream& operator <<(std::ostream& os, const TupleT& tp) {
    return printTupleImpl(os, tp, std::make_index_sequence<TupSize>{});
}

template<typename TupleT, typename T, std::size_t... Is>
bool isExistHelper(const TupleT& tp, T&& elementToBeSearched, std::index_sequence<Is...>) {
    auto isExist = [&elementToBeSearched](const auto& x) {
        if constexpr(std::is_same_v<std::decay_t<decltype(elementToBeSearched)>, std::decay_t<decltype(x)>>) {
            return x == elementToBeSearched;
        } else {
            return false;
        }
    };

    return (isExist(std::get<Is>(tp)) || ...);
}

template<typename TupleT, typename T, std::size_t TupSize = std::tuple_size<std::decay_t<TupleT>>::value>
decltype(auto) isExistInTuple(const TupleT& tp, T&& elementToBeSearched) {
    return isExistHelper(tp, elementToBeSearched, std::make_index_sequence<TupSize>{});
} 

}
}

#endif // TUPLE_HELPER_H