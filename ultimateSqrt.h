#pragma once
#include <cmath>
#include <type_traits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stdexcept>


template <typename T>
class sqrtTraits;

template<typename T>
class sqrtTraits<std::vector<T>> {
public:
    using sqrtType = std::vector<T>;
    static constexpr int vec = true;
};
template<typename T>
class sqrtTraits<std::list<T>> {
public:
    using sqrtType = std::list<T>;
    static constexpr int vec = true;
};
template<typename T>
class sqrtTraits<std::forward_list<T>> {
public:
    using sqrtType = std::forward_list<T>;
    static constexpr int vec = true;
};

template<typename T>
class sqrtTraits<std::set<T>> {
public:
    using sqrtType = std::set<T>;
    static constexpr int set = true;
};
template<typename T>
class sqrtTraits<std::unordered_set<T>> {
public:
    using sqrtType = std::unordered_set<T> ;
    static constexpr int set = true;
};

template <typename K, typename V>
class sqrtTraits<std::map<K, V>>{
public:
    using sqrtType = std::map<K, V>;
    static constexpr int map = true;
};

template <typename K, typename V>
class sqrtTraits<std::unordered_map<K, V>>{
public:
    using sqrtType = std::unordered_map<K, V>;
    static constexpr int map = true;
};

//template for number
template <typename T>
typename std::enable_if_t<std::is_arithmetic<T>::value, T> sqrT(const T & x){
    if (x < 0) {
        throw std::invalid_argument("neg number");
    }
    else
        return static_cast<T>(sqrt(x));
}
//template for map/unordered_map
template <typename T>
typename std::enable_if_t<sqrtTraits<T>::map, T> sqrT(const T & inp){
    using sqrtType = typename sqrtTraits<T>::sqrtType;
    sqrtType out;
    for(auto const & el: inp)
        out.insert(std::make_pair(el.first,sqrT(el.second)));
    return out;
}

//template for vector/list
template <typename T>
typename std::enable_if_t<sqrtTraits<T>::vec, T> sqrT(const T & inp){
    using sqrtType = typename sqrtTraits<T>::sqrtType;
    sqrtType out;
    for(auto const & el: inp){
        out.push_back(sqrT(el));
    }
    return out;
}

//template for set/unordered_set
template <typename T>
typename std::enable_if_t<sqrtTraits<T>::set, T> sqrT(const T & inp){
    using sqrtType = typename sqrtTraits<T>::sqrtType;
    sqrtType out;
    for(auto const & el: inp)
        out.insert(sqrT(el));
    return out;
}

//template for forward_list
template <typename T>
std::forward_list<T> sqrT(const std::forward_list<T> & inp){
    std::forward_list<T> out;
    auto befBeg = out.before_begin();
    for(auto const & el: inp) {
        out.insert_after(befBeg, sqrT(el));
    }
    out.reverse();
    return out;
}
