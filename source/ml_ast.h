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

    ASTNodeList *castAsList() {
        dynamic_cast<ASTNodeList *>(this);
    }

    ASTNodeText *castAsText() {
        dynamic_cast<ASTNodeText *>(this);
    }
};

class ASTNodeList: public ASTNode {
private:
    std::vector<ASTNode *> children;

public:
    std::vector<ASTNode *> &getChildren() {
        return children;
    }
};

class ASTNodeText: public ASTNode {
private:
    std::string text;

public:
    std::string &getText() {
        return text;
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

// TODO: generalize ASTNode???Typed with value

template <>
class ASTNodeTextTyped<node_int>: public ASTNodeText {
private:
    int value;

public:
    virtual ASTNodeType getType() {
        return node_int;
    }

    int getValue() {
        return value;
    }
};

}
