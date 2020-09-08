#ifndef DEBUG_HPP
#define DEBUG_HPP


#define DEBUG

#ifdef DEBUG
    #define $D( code ) code
#else
    #define $D( code ) if(0){ code }
#endif


#include <iostream>
#include <vector>


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& arr) {
    for (const auto& item : arr) {
        out << item << " ";
    }
    return out;
}


#endif //DEBUG_HPP
