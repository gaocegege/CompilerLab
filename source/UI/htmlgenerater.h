#ifndef HTMLGENERATER_H
#define HTMLGENERATER_H
#include <string>

class HtmlGenerater
{
public:
    HtmlGenerater();
    // flag == 1: myStr is a json, else myStr is a filename
    static void generateSyntax(std::string myStr, bool flag);
    static void generateLex(std::string myStr, bool flag);

private:
    static std::string getStringFromFile(std::string str);
//    static std::string compressJson(std::string str);
};

#endif // HTMLGENERATER_H
