#include "htmlgenerater.h"
#include <QFile>
#include <iostream>
#include <sstream>
#include <QTextStream>
#include <QDir>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/date_time.hpp>

using namespace boost::property_tree;

HtmlGenerater::HtmlGenerater()
{
}

std::string HtmlGenerater::getStringFromFile(std::string str)
{
//    std::cout << "Get:\t" << str << std::endl;
    std::string result;
    QString buf(str.c_str());
    QFile myFile(buf);
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Open failed." << std::endl;
        return "Open failed.";
    }

    QTextStream txtInput(&myFile);
    QString lineStr;
    str.clear();
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        result += lineStr.toStdString();
        result += "\n";
    }
//    std::cout << result << std::endl;

    return result;
}

// compress the json stream to get a lex
//std::string HtmlGenerater::compressJson(std::string str)
//{
//    ptree pt;
//    str = "{\n\"rulename\": \"root\",\n\"ruleindex\": \"0\",\n\"children\": [{\n\"rulename\": \"main structure\",\n\"ruleindex\": \"0\",\n\"children\": [{\n\"rulename\": \"program\",\n\"ruleindex\": \"0\",\n\"children\": [{\n\"rulename\": \"error\",\n\"error\": \"Bad keyword\",\n\"children\": [{\n\"rulename\": \"keyword\",\n\"ruleindex\": \"0\",\n\"children\": [{\n\"rulename\": \"id\",\n\"error\": \"Regex not matched\"\n}]\n}]\n}]\n}]\n}]\n}";
//    std::stringstream stream(str);
//    std::cout << str << std::endl;
//    // bug: <unspecified file>(19): expected object name
//    try{
//        read_json<ptree>(stream, pt);
//      }
//      catch(ptree_error & e) {
//        std::cout << e.what() << std::endl;
//      }

//    for (ptree::iterator it = pt.begin(); it != pt.end(); it++)
//    {
//        ptree pbuf = it->second;
//        if (pbuf.get_child("children").size() == 0)
//        {
//            std::cout << pbuf.get<std::string>("rulename") << std::endl;
//        }
//    }
//    return str;
//}

void HtmlGenerater::generateSyntax(std::string myStr, bool flag)
{
    std::string result = "";
    std::string start = "/before.html";
    std::string end = "/after.html";

    std::string index = "/syntax.html";
    index = PROJECT_PATH + index;
    std::string beforeStr = getStringFromFile(PROJECT_PATH + start);
    std::string afterStr = getStringFromFile(PROJECT_PATH + end);
//    std::cout << PROJECT_PATH + start << std::endl;
    //true is from program,else from file
    if (flag == true)
    {
        std::cout << myStr << std::endl;
        result = beforeStr + myStr + afterStr;
    }
    else
    {
        result = beforeStr + getStringFromFile(PROJECT_PATH + myStr) + afterStr;
    }

//    std::cout << "cece:  " << result << std::endl;

    QFile myFile(QString(index.c_str()));
    if(!myFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cout << "Open failed." << std::endl;
        return;
    }

    QTextStream txtOutput(&myFile);
    txtOutput << QString(result.c_str());
}

void HtmlGenerater::generateLex(std::string myStr, bool flag)
{
    std::string result = "";
    std::string start = "/before.html";
    std::string end = "/afterlex.html";

    std::string index = "/lex.html";
    index = PROJECT_PATH + index;
    std::string beforeStr = getStringFromFile(PROJECT_PATH + start);
    std::string afterStr = getStringFromFile(PROJECT_PATH + end);
//    std::cout << PROJECT_PATH + start << std::endl;
    //true is from program,else from file
    if (flag == true)
    {
//        myStr = compressJson(myStr);
        std::cout << "From the text: " << myStr << std::endl;
        result = beforeStr + myStr + afterStr;
    }
    else
    {
        result = beforeStr + getStringFromFile(PROJECT_PATH + myStr) + afterStr;
    }

//    std::cout << "cece:  " << result << std::endl;

    QFile myFile(QString(index.c_str()));
    if(!myFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cout << "Open failed." << std::endl;
        return;
    }

    QTextStream txtOutput(&myFile);
    txtOutput << QString(result.c_str());
}
