// main.cpp
/* $Date$
 * $Id$
 * $Version: 0.1$
 * $Revision: 1$
 */

#include <Main.hpp>

/* let's go */
int main(int argc, char * argv[]) {
    std::ios_base::sync_with_stdio(0);
    return (new Main(argc, argv))->run(std::cin);
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
