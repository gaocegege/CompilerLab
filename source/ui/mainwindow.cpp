#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "htmlgenerater.h"
#include <iostream>
#include <QtWidgets/QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTextEdit>
#include <QDialog>
#include <QWindow>
#include "../mylang_util.hpp"
#include <iostream>
#include <sstream>

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
}

// syntax
void MainWindow::on_pushButton_2_clicked()
{
    std::cout << "syntax\n" ;
    str = "program test()\ntype testArray is array of 20 integer;\nis\nvar buf is testArray;\nbegin\nbuf[0] := 100;\nend";
    std::stringstream ss;
    mylang::PassReprJSON<> rf4(ss);
    mylang::Input sbegin = str.cbegin();
    auto x = mylang::Parser<>::parse(sbegin, str.cend());
    x->runPass(&rf4);
    std::cout << "cece" << ss.str() << std::endl;
    HtmlGenerater::generateHtml(ss.str(), true);

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
            }
            std::cout << str << std::endl;
        }
    delete fd;
}

// read statements from text
void MainWindow::on_pushButton_6_clicked()
{

}
