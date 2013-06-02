//Challenge #126 [Easy]

#include <vector>
#include <algorithm>

template<class Cont>
void mergeAndSort(const Cont& a, Cont& b) {
    // merge
    auto begin = std::begin(b);
    auto first = std::begin(a);
    auto end = std::end(b);
    for(; begin != end; ++begin) {
        if(*begin == 0)
            *begin = *first++;gean
        else
            break;
    }
    begin = std::begin(b);
    // sort (assuming no built ins)
    std::make_heap(begin,end);
    while(begin != end)
        std::pop_heap(begin, end--);
}

#include <iostream>

int main() {
    std::vector<int> a = {692,1,32};
    std::vector<int> b = {0,0,0,14,15,123,2431};
    mergeAndSort(a,b);
    for(auto&& i : b)
        std::cout << i << ' ';
}
