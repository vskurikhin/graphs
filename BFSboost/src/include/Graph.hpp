// Main.hpp
/* $Date$
 * $Id$
 * $Version: 0.1$
 * $Revision: 1$
 */

#pragma once
#ifndef __GRAPH__
#define __GRAPH__

#include <cstdlib>
#include <istream>
#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>

namespace {
using namespace boost;

typedef adjacency_list<vecS, vecS, directedS> graph_t;

class Graph : public graph_t  {
public:

    typedef graph_traits<graph_t>::edge_descriptor    edge_type;
    typedef graph_traits<graph_t>::vertex_descriptor  vertex_type;
    typedef graph_traits<graph_t>::vertex_iterator    vertex_iterator;
    typedef graph_traits<graph_t>::adjacency_iterator adjacency_iterator;

    Graph(size_t number)
     : graph_t(number), number_(number) { }

    virtual ~Graph() { }

    std::istream & read(std::istream & is, size_t count) {
        graph_t::vertex_iterator v;
        for(size_t i = 0; i < count; i++) {
            size_t number1, number2;
            is >> number1 >> number2;
            add_edge(number1, number2, *this);
            add_edge(number2, number1, *this);
        }

        return is;
    }

    class OutBFSVisitor : public default_bfs_visitor {
        std::ostream & os_;
    public:
        OutBFSVisitor(std::ostream & os) : os_(os) { /* None */ }

        void tree_edge(edge_type e, const Graph & g) const {
            os_ << "      tree     " << e << std::endl;
        }

        void non_tree_edge(edge_type e, const Graph & g) const {
            os_ << "non tree ";
        }

        void gray_target(edge_type e, const Graph & g) const {
            os_ << "gray  " << e << std::endl;
        }

        void black_target(edge_type e, const Graph & g) const {
            os_ << "black " << e << std::endl;
        }
    };

private:
    /* data */
    size_t number_;
};
};

#endif // __GRAPH__

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
