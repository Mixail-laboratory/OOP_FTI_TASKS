#include <iostream>
#include "sort.h"
#include "vector"
#include <functional>

int main()
{
    std::vector<int> c = {9};
    
    sortFunction::sort(c.begin(), c.end(), std::less<int>{});

}

