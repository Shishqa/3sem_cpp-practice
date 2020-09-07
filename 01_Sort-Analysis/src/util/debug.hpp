#ifndef DEBUG_HPP
#define DEBUG_HPP

#define DEBUG

#ifdef DEBUG
    #define $D( code ) code
#else
    #define $D( code ) if(0){ code }
#endif

#endif //DEBUG_HPP
