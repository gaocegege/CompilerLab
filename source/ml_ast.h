#ifndef ML_AST_H
#define ML_AST_H

#include <vector>
#include <string>

namespace mylang {

// forward declaration

class Rule;

template <class TX>
class NodeList;

template <class TX>
class NodeText;

// forward declaration finished

using NodeType = const Rule *;

class Node {
public:
    inline Node() {}

    virtual ~Node() {}

    virtual NodeType getType() const = 0;

    virtual const std::string getFullText() const = 0;

    template <class TX = void> // decide type later
    inline const NodeList<TX> *castList() const {
        dynamic_cast<NodeList<TX> *>(this);
    }

    template <class TX = void> // decide type later
    inline const NodeText<TX> *castText() const {
        dynamic_cast<NodeText<TX> *>(this);
    }
};

template <class TX = void> // actually not a template
class NodeList: public Node {
private:
    std::vector<Node *> children;

public:
    inline NodeList(): Node(), children() {}

    virtual ~NodeList() {
        for (Node *child: children) {
            delete child;
        }
    }

    inline void putChild(Node *value) {
        children.push_back(value);
    }

    virtual const std::string getFullText() const {
        std::string result = "";

        for (Node *child: children) {
            result += child->getFullText();
        }

        return result;
    }

    inline const std::vector<Node *> &getChildren() const {
        return children;
    }
};

template <class TX = void> // actually not a template
class NodeText: public Node {
private:
    std::string text;

public:
    inline NodeText(std::string value): Node(), text() {}

    virtual ~NodeText() {}

    virtual const std::string getFullText() const {
        return text;
    }

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
using NodeListTyped = NodeTyped<NT, NodeList<>>;

template <NodeType NT>
using NodeTextTyped = NodeTyped<NT, NodeText<>>;

}

#endif
