#ifndef ML_AST_H
#define ML_AST_H

#include <vector>
#include <string>

namespace mylang {

// forward declaration

class Rule;

template <class TX = void>
class NodeList;

template <class TX = void>
class NodeText;

// forward declaration finished

using NodeType = const Rule *;

class Node {
public:
    inline Node() {}

    virtual ~Node() {}

    virtual NodeType getType() const = 0;

    virtual const std::string getFullText() const = 0;

    inline const NodeList<> *castList() const;

    inline const NodeText<> *castText() const;
};

template <class TX> // actually not a template
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

    inline void putChild(const Node *value) {
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

template <class TX> // actually not a template
class NodeText: public Node {
private:
    std::string text;

public:
    inline NodeText(const std::string &value): Node(), text(value) {}

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

inline const NodeList<> *Node::castList() const {
    return dynamic_cast<const NodeList<> *>(this);
}

inline const NodeText<> *Node::castText() const {
    return dynamic_cast<const NodeText<> *>(this);
}

template <class NT, class T>
class NodeTyped: public T {
public:
    virtual NodeType getType() const {
        return NT::instance;
    }
};

template <class NT>
using NodeListTyped = NodeTyped<NT, NodeList<>>;

template <class NT>
using NodeTextTyped = NodeTyped<NT, NodeText<>>;

}

#endif
