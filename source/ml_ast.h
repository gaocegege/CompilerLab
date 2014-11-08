#ifndef ML_AST_H
#define ML_AST_H

#include <vector>
#include <string>

namespace mylang {

class Rule;

using NodeType = Rule *;

class Node {
public:
    virtual NodeType getType() = 0;

    template <class T>
    inline T *cast() {
        dynamic_cast<T *>(this);
    }
};

class NodeList: public Node {
private:
    std::vector<Node *> children;

public:
    inline NodeList(): children() {}

    inline void putChildren(Node *value) {
        children.push_back(value);
    }

    inline std::vector<Node *> &getChildren() {
        return children;
    }
};

class NodeText: public Node {
private:
    std::string text;

public:
    inline NodeText(std::string value): text() {}

    inline std::string &getText() {
        return text;
    }

    template <class T>
    inline T &getValue() = delete;
};

template <NodeType NT, class T>
class NodeTyped: public T {
public:
    virtual NodeType getType() {
        return NT;
    }
};

template <NodeType NT>
using NodeListTyped = NodeTyped<NT, NodeList>;

template <NodeType NT>
using NodeTextTyped = NodeTyped<NT, NodeText>;

}

#endif
