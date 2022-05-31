#include "newwindow.h"

#include "fileinfo.h"
#include "ui_newwindow.h"

NewWindow::NewWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::NewWindow) {
  ui->setupUi(this);
}

NewWindow::~NewWindow() { delete ui; }
