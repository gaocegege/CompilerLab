#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "htmlgenerater.h"
#include "../mylang.hpp"
#include <iostream>
#include <QtWidgets/QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTextEdit>
#include <QDialog>
#include <QWindow>
#include <iostream>
#include <sstream>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// lex
void MainWindow::on_pushButton_clicked()
{
    std::cout << "lex\n" ;
//    str="1+2";
    std::stringstream ss;
    mylang::PassReprJSON<> rf4(ss);
    mylang::Input sbegin = str.cbegin();
    auto x = mylang::Parser<>::parse(sbegin, str.cend());
    x->runPass(&rf4);
//    std::cout << "cece" << ss.str() << std::endl;
    HtmlGenerater::generateLex(ss.str(), true);
    std::string lexHtml = "/lex.html";
    std::string fileurl = "file://";
    lexHtml = fileurl + PROJECT_PATH + lexHtml;
    QDesktopServices::openUrl(QUrl(QString(lexHtml.c_str())));
}

// syntax
void MainWindow::on_pushButton_2_clicked()
{
    std::cout << "syntax\n" ;
//    str = "program test()\ntype testArray is array of 20 integer;\nis\nvar buf is testArray;\nbegin\nbuf[0] := 100;\nend";
    std::stringstream ss;
    mylang::PassReprJSON<> rf4(ss);
    mylang::Input sbegin = str.cbegin();
    auto x = mylang::Parser<>::parse(sbegin, str.cend());
    x->runPass(&rf4);
//    std::cout << "cece" << ss.str() << std::endl;
    HtmlGenerater::generateSyntax(ss.str(), true);
    std::string syntaxHtml = "/syntax.html";
    std::string fileurl = "file://";
    syntaxHtml = fileurl + PROJECT_PATH + syntaxHtml;
    std::cout << syntaxHtml << std::endl;
    QDesktopServices::openUrl(QUrl(syntaxHtml.c_str()));

}

// read statements from file
void MainWindow::on_pushButton_5_clicked()
{
    QFileDialog *fd = new QFileDialog(this,"Choose a file to read:");
        if(fd->exec() == QFileDialog::Accepted) // ok
        {
            QString fileStr = fd->selectedFiles()[0];
            QFile myFile(fileStr);
            if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                std::cout << "Open failed." << std::endl;
                return;
            }

            QTextStream txtInput(&myFile);
            QString lineStr;
            str.clear();
            while(!txtInput.atEnd())
            {
                lineStr = txtInput.readLine();
                str += lineStr.toStdString();
                // critic
                str += "\n";
            }
            std::cout << str << std::endl;
        }
    delete fd;
}

// read statements from text
void MainWindow::on_pushButton_6_clicked()
{

}
