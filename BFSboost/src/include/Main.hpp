// Main.hpp
/* $Date$
 * $Id$
 * $Version: 0.1$
 * $Revision: 1$
 */

#pragma once
#ifndef __MAIN__
#define __MAIN__

#include <cassert>
#include <cstring>
#include <cstdint>
#include <cstdlib>

#include <string>
#include <iostream>
#include <algorithm>

#include <boost/graph/breadth_first_search.hpp>

#include <Graph.hpp>

namespace {
using namespace boost;

class Main {
public:
    Main(int argc, char ** argv)
     : argc_(argc),  argv_(argv) { /* None */ }

    virtual ~Main() { }

    std::ostream & print_vertexes(std::ostream & os, const Graph & g) {
        Graph::vertex_iterator begin, end;
        boost::tie(begin, end) = vertices(static_cast<graph_t>(g));

        return print(os, begin, end);
    }

    std::ostream & print_edges(std::ostream & os, const Graph & g) {
        Graph::edge_iterator begin, end;
        boost::tie(begin, end) = edges(static_cast<graph_t>(g));

        return print(os, begin, end);
    }

    int run(std::istream & is) {
        int number, count;
        is >> number;
        Graph g(number);

        is >> count;
        g.read(is, count);
        print_vertexes(std::cout, g);
        print_edges(std::cout, g);

        std::cout << "breadth_first_search" << std::endl;
        Graph::OutBFSVisitor cout_bfs_visitor(std::cout);
        breadth_first_search(g, 0, visitor(cout_bfs_visitor));

        return EXIT_SUCCESS; 
    }

private:
    template <class Iterator>
    std::ostream & print(std::ostream & os, Iterator begin, Iterator end) {
        Iterator next;

        if (begin != end) {
            next = begin;
            os << *next;
            next++;
        }
        for (; next != end; next++) {
            os << " " << *next;
        }
        os << std::endl;

        return os;
    }

    /* data */
    int argc_;
    char ** argv_;
};
};
#endif // __MAIN__

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
