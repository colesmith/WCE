#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

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

void MainWindow::on_action_open_file_triggered()
{
    // QFileDialog * fileDlg = new QFileDialog(this,Qt::Popup);
    QString path = QFileDialog::getOpenFileName(this,
            tr("Open Text"), "C:/", tr("Image Files (*.txt *.md *.html)"));
    QFile * file = new QFile(path);
    if (! file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Open Error", "文件打开错误");
        return ;
    }

    QTextStream * textFileStream = new QTextStream(file);
    // QMessageBox::information(this, "Content", textFileStream->readAll());
    ui->plain_content->setPlainText(textFileStream->readAll());

    file->close();
}
