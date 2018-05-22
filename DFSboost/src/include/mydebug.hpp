#ifndef MYDEBUG_HPP
#define MYDEBUG_HPP

#include <string>
#include <iostream>

const char * em = "";
const char * & empty = em;
const char * sp = " ";
const char * & space = sp;
const char * cl = ":";
const char * & colon = cl;
const char * sc = ";";
const char * & semicolon = sc;
const std::string brackets[] = {"[", ",", "]"};
const std::string parens[] = {"(", ",", ")"};
const std::string (& parentheses)[3] = parens;
const std::string braces[] = {"{", ",", "}"};

#if defined(__WIN32__) || defined(__NT__) || defined(_WIN32)
# if !defined(WIN32)
#  define WIN32
# endif
#endif

#ifdef WIN32
# if defined(_MSC_VER)
#  ifndef __func__
#   define __func__ __FUNCTION__
#  endif
# endif
#endif

#if defined(__GNUC__) \
    && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || (__GNUC__ >= 5)) \
    || (defined(__cplusplus) && defined(__GXX_EXPERIMENTAL_CXX0X__))
# define HACK_GCC_ITS_CPP0X 1
#endif

#if defined(_AIX) && (defined(__IBMCPP__) && __IBMCPP__ >= 900)
# define HACK_VACPP_ITS_CPP 1
#endif

#if __cplusplus >= 201103L || defined(__clang__) \
    || (defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 180040629)
template <typename T>
std::ostream& printm_r(std::ostream& stm, const T &t) {
    return stm << t;
}

template <typename T, typename... Args>
std::ostream& printm_r(std::ostream& stm, const T &t, const Args&... r) {
    stm << t;
    return printm_r(stm, r...);
}

template <typename... Args>
std::ostream& printm(std::ostream& stm, const Args&... r) {
    printm_r(stm, r...);
    return stm;
}
# define PRINTM
#else
# if __cplusplus >= 201103L || defined(HACK_VACPP_ITS_CPP) \
     || defined(HACK_GCC_ITS_CPP0X)
#  define EVAL0(...) __VA_ARGS__
#  define EVAL1(...) EVAL0 (EVAL0 (EVAL0 (__VA_ARGS__)))
#  define EVAL2(...) EVAL1 (EVAL1 (EVAL1 (__VA_ARGS__)))
#  define EVAL3(...) EVAL2 (EVAL2 (EVAL2 (__VA_ARGS__)))
#  define EVAL4(...) EVAL3 (EVAL3 (EVAL3 (__VA_ARGS__)))
#  define EVAL(...)  EVAL4 (EVAL4 (EVAL4 (__VA_ARGS__)))

#  define MAP_END(...)
#  define MAP_OUT

#  define MAP_GET_END() 0, MAP_END
#  define MAP_NEXT0(test, next, ...) next MAP_OUT
#  define MAP_NEXT1(test, next) MAP_NEXT0 (test, next, 0)
#  define MAP_NEXT(test, next)  MAP_NEXT1 (MAP_GET_END test, next)

#  define MAP0(f, x, peek, ...) f(x) MAP_NEXT (peek, MAP1) (f, peek, __VA_ARGS__)
#  define MAP1(f, x, peek, ...) f(x) MAP_NEXT (peek, MAP0) (f, peek, __VA_ARGS__)
#  define MAP(f, ...) EVAL (MAP1 (f, __VA_ARGS__, (), 0))

#  define STMAPOUT(x) << (x)
#  define printm(stm, ...) stm MAP(STMAPOUT, __VA_ARGS__)
#  define PRINTM
# endif
#endif

#if defined(PRINTM)
# define printe(...) printm(std::cerr, __VA_ARGS__)
# define printd(...) printe(__FILE__, ":", __func__, ":", __LINE__, "| "); \
                     printe(__VA_ARGS__)
# define INDEBUG(...) if (debug) { __VA_ARGS__; }
# define INDEBUG1(...) if (debug > 1) { __VA_ARGS__; }
# define INDEBUG2(...) if (debug > 2) { __VA_ARGS__; }
# define INDEBUG3(...) if (debug > 3) { __VA_ARGS__; }
inline void* cp2vp(const char* c) { return (void*)c; }
#endif

#endif // MYDEBUG_HPP
/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
