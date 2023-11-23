#include "node.hpp"

Node::Node() {
    m = nullptr;
    m_updated = false;
}

Node::~Node() {
    delete m;
}
