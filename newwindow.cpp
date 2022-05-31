#include "newwindow.h"
#include "ui_newwindow.h"

NewWindow::NewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);
    auto cur = ui->files->rowCount();
    ui->files->setRowCount(cur + 1);
}

NewWindow::~NewWindow()
{
    delete ui;
}
