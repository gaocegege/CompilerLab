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
    HtmlGenerater::generateHtml("/test.json", false);

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
