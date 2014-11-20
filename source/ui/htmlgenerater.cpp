#include "htmlgenerater.h"
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDir>

HtmlGenerater::HtmlGenerater()
{
}

std::string HtmlGenerater::getStringFromFile(std::string str)
{
    std::cout << "Get:\t" << str << std::endl;
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
    std::cout << result << std::endl;

    return result;
}

void HtmlGenerater::generateHtml(std::string myStr, bool flag)
{
    std::string result = "";
    std::string start = "/before.txt";
    std::string end = "/after.txt";

    std::string index = "/index.html";
    index = PROJECT_PATH + index;
    std::string beforeStr = getStringFromFile(PROJECT_PATH + start);
    std::string afterStr = getStringFromFile(PROJECT_PATH + end);
//    std::cout << PROJECT_PATH + start << std::endl;
    if (flag == true)
        result = beforeStr + myStr + afterStr;
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
