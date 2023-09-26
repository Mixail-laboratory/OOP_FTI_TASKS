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



template <typename T>
class sqrtTraits;

// Для начала сделай все bool поля public. Ты же их вытаскиваешь потом в std::enable_if.
template<typename T>
class sqrtTraits<std::vector<T>> {
public:
    typedef std::vector<T> sqrtType;
private:
    const static bool vec = true;
};
template<typename T>
class sqrtTraits<std::list<T>> {
public:
    typedef std::list<T> sqrtType;
private:
    const static bool vec = true;
};
template<typename T>
class sqrtTraits<std::forward_list<T>> {
public:
    typedef std::forward_list<T> sqrtType;
private:
    const static bool vec = true;
    
};

template<typename T>
class sqrtTraits<std::set<T>> {
public:
    typedef std::set<T> sqrtType;
private:
    const static bool set = true;
};
template<typename T>
class sqrtTraits<std::unordered_set<T>> {
public:
    typedef std::unordered_set<T> sqrtType;
private:
    const static bool set = true;
};

template <typename K, typename V>
class sqrtTraits<std::map<K, V>>{
public:
    typedef std::map<K, V> sqrtType;
private:
    const static bool map = true;
};

template <typename K, typename V>
class sqrtTraits<std::unordered_map<K, V>>{
public:
    typedef std::unordered_map<K, V> sqrtType;
private:
    const static bool map = true;
};

// А теперь идем к месту, где не компиллируется. Вот в случае успеха инстанцирования, SFINAE функция возвращает тип T.
// А ты возвращаешь "not a number", то есть const char[13]. Вот он и падает на этапе компиляции.
// Лучше выброси исключение, например std::invalid_argument("neg number").
// И зачем нужен  if (!std::is_arithmetic<T>::value) return "not a number"? Уже ж проверка была в ebable_if...

template <typename T>
typename std::enable_if_t<std::is_arithmetic<T>::value, T> sqrT(const T & x){
    if (!std::is_arithmetic<T>::value) return "not a number";
    if (x < 0) return "neg number";
    else return sqrt(x);
}
//template for map/unordered_map
template <typename T>
typename std::enable_if_t<sqrtTraits<T>::map, T> sqrT(const T & inp){
    typedef typename sqrtTraits<T>::sqrtType sqrtType;
    sqrtType out;
    for(auto el: inp)
        out.insert(std::make_pair(el.first,sqrT(el.second)));
    return out;
}

//Вот здесь transform не скомпилируется по особым причинам.
//Лучше просто циклом push_back делай да и всё.
//template for vector/list/forward_list

template <typename T>
typename std::enable_if_t<sqrtTraits<T>::vec, T> sqrT(const T & inp){
    typedef typename sqrtTraits<T>::sqrtType sqrtType;
    sqrtType out;
    std::transform(inp.begin(), inp.end(), out.begin(), [](T element){return sqrT(element);} );
    return out;
}

//template for set/unordered_set
template <typename T>
typename std::enable_if_t<sqrtTraits<T>::set, T> sqrT(const T & inp){
    typedef typename sqrtTraits<T>::sqrtType sqrtType;
    sqrtType out;
    for(auto el: inp)
        out.insert(sqrT(el));
    return out;
}
