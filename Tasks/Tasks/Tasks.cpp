#include <iostream>
#include "sort.h"
#include "vector"
#include <functional>

int main()
{
    std::vector<int> c = {9,8,7,7,7};
    
    sortFunction::sort(c.begin(), c.end(), std::less<int>{});
    std::copy(c.begin(), c.end(), std::ostream_iterator<int>(std::cout, " "));

}

