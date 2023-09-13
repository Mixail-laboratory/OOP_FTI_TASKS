#pragma once
#include <algorithm>
#include <type_traits>
#include <iterator>


/// Ну, все solution собрал, давай сначала по ошибкам.
/// Ну во-первых Падает на Compare(first, curretFirst). А знаешь почему? Потому что Compare это тип, а надо позвать от самого параметра...
/// Во вторых там где enable_if надо еще имя типу дать, что-то вроде typename T = std::enable_if<std::is_arithmetic_v<RandomAccessIterator>>::type>
/// И все, оно компилится. А теперь разбор полетов:
/// 1. Убирай swap, он медленный, когда начнется move-семантика ты еще успеешь наиграться с его правильной реализацей.
/// 2. Какая-то херабора с алгоритмом... Падает в рантайме, где-то с памятью ошибка, попробуй подебажить и понять в чем ошибка.
/// 3. Хочу дефолтный компаратор, std::less например.
/// 4. SFINAE у тебя наверное тестовый, потому что хочется проверку на то, что итератор является Random Access, а у тебя проверка на то, что он поддерживает арифметику 0_o


namespace sortFunction
{
	template <class RandomAccessIterator, typename Compare,typename T = std::enable_if<std::is_same<typename std::iterator_traits<RandomAccessIterator>::iterator_category, std::random_access_iterator_tag>::value>>
    void sort(RandomAccessIterator first, RandomAccessIterator last, const Compare& comp) {
        if (first != last) {
            RandomAccessIterator left = first;
            RandomAccessIterator right = last;
            RandomAccessIterator pivot = left++;

            while (left != right) {
                if (comp(*left, *pivot)) {
                    ++left;
                }
                else {
                    while ((left != --right) && comp(*pivot, *right));
                    std::iter_swap(left, right);
                }
            }
            --left;
            std::iter_swap(first, left);
            sortFunction::sort(first, left, comp);
            sortFunction::sort(right, last, comp);
        }
    }
}


