#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Gets the user interface element, connects the signal to the slot
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button()
{
    // Usernames
    QString name[] = {"abc", "def", "ghi"};
    QString code[] = {"abc12", "def34", "ghi56"};

    QString uName = ui->lineEdit->text();
    QString uCode = ui->lineEdit_2->text();

    bool found = false;

    for (int i{}; i < name->length(); i++) {
        if (uName == name[i] && uCode == code[i]) {
            QMessageBox::information(this, "Welcome Message", "User: " + name[i] + "\n"
                                                                                   " Welcome to Login Management System");
            found = true;
            break;
        }
    }
    if (!found) {
        QMessageBox::information(this, "Error Box", "invalid username or password");
    }
}

