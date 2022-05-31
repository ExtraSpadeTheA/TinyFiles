#include "newwindow.h"

#include "fileinfo.h"
#include "ui_newwindow.h"
#include "fileinfo.h"
#include <QFileDialog>

<<<<<<< HEAD
NewWindow::NewWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::NewWindow) {
  ui->setupUi(this);
=======
NewWindow::NewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);
    FileInfo info(new QString("name"),new  QString("123kb"),new  QString("txt"),new  QString("2022-6-1"));
    info.AddRow(ui->files);
    connect(ui->actionUpload_Files,&QAction::triggered,this,&NewWindow::OpenFile);
}
void NewWindow::OpenFile(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.exec();

>>>>>>> f9d7951e319577885fc01d9b0ac91aca28073799
}

NewWindow::~NewWindow() { delete ui; }
