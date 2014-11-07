#ifndef ML_AST_H
#define ML_AST_H

#include <vector>
#include <string>

namespace mylang {

using ASTNodeType = char *;

char node_root[] = "root";

class ASTNodeList;
class ASTNodeText;

class ASTNode {
public:
    virtual ASTNodeType getType() {}

    inline ASTNodeList *castAsList() {
        dynamic_cast<ASTNodeList *>(this);
    }

    inline ASTNodeText *castAsText() {
        dynamic_cast<ASTNodeText *>(this);
    }
};

class ASTNodeList: public ASTNode {
private:
    std::vector<ASTNode *> children;

public:
    inline std::vector<ASTNode *> &getChildren() {
        return children;
    }
};

class ASTNodeText: public ASTNode {
private:
    std::string text;

public:
    inline std::string &getText() {
        return text;
    }
};

template <class T>
class ASTNodeData: public ASTNodeText {
private:
    T value;

public:
    inline T &getValue() {
        return value;
    }
};

template <ASTNodeType NT, class T>
class ASTNodeTyped: public T {
public:
    virtual ASTNodeType getType() {
        return NT;
    }
};

template <ASTNodeType NT>
using ASTNodeListTyped = ASTNodeTyped<NT, ASTNodeList>;

template <ASTNodeType NT>
using ASTNodeTextTyped = ASTNodeTyped<NT, ASTNodeText>;

template <ASTNodeType NT>
using ASTNodeDataTyped = ASTNodeTyped<NT, ASTNodeData>;

}

#endif
