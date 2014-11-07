#ifndef ML_AST_H
#define ML_AST_H

#include <vector>
#include <string>

namespace mylang {

using NodeType = char *;

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
    inline std::vector<Node *> &getChildren() {
        return children;
    }
};

class NodeText: public Node {
private:
    std::string text;

public:
    inline std::string &getText() {
        return text;
    }
};

template <class T>
class NodeData: public NodeText {
private:
    T value;

public:
    inline T &getValue() {
        return value;
    }
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

template <NodeType NT, class T>
using NodeDataTyped = NodeTyped<NT, NodeData<T> >;

}

#endif
