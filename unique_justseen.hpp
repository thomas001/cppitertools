#ifndef UNIQUE_JUSTSEEN_HPP
#define UNIQUE_JUSTSEEN_HPP

#include "filter.hpp"
#include <type_traits>
#include <functional>

namespace iter 
{
    //this should be self evident but unique_justseen places the requirement 
    //on the elements in the container have the != operator overloaded
    template <typename Container>
    auto unique_justseen(Container && container) 
    -> decltype(filter(std::function<bool(decltype(container.front))>(),container))
    {
        using elem_t = decltype(container.front());
        auto last = container.begin();
        std::function<bool(elem_t)> func = [&last,container](elem_t e) 
                {
                    if (last == container.begin())return true;
                    else return *(++last) != e;
                };
        return filter(func, container);
    }
}

#endif //UNIQUE_JUSTSEEN_HPP
    
