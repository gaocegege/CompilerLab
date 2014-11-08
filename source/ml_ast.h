#ifndef ML_AST_H
#define ML_AST_H

#include <vector>
#include <string>

namespace mylang {

class Rule;

using NodeType = const Rule *;

class Node {
public:
    virtual NodeType getType() const = 0;

    template <class T>
    inline const T *cast() const {
        dynamic_cast<T *>(this);
    }
};

class NodeList: public Node {
private:
    std::vector<Node *> children;

public:
    inline NodeList(): children() {}

    inline void putChild(Node *value) {
        children.push_back(value);
    }

    inline const std::vector<Node *> &getChildren() const {
        return children;
    }
};

class NodeText: public Node {
private:
    std::string text;

public:
    inline NodeText(std::string value): text() {}

    inline const std::string &getText() const {
        return text;
    }

    template <class T>
    inline const T &getValue() const = delete;
};

template <NodeType NT, class T>
class NodeTyped: public T {
public:
    virtual NodeType getType() const {
        return NT;
    }
};

template <NodeType NT>
using NodeListTyped = NodeTyped<NT, NodeList>;

template <NodeType NT>
using NodeTextTyped = NodeTyped<NT, NodeText>;

}

#endif
