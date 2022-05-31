#include "newwindow.h"
#include "ui_newwindow.h"
#include "fileinfo.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDateTime>

NewWindow::NewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);
    connect(ui->actionUpload_Files,&QAction::triggered,this,&NewWindow::OpenFile);
}
void NewWindow::OpenFile(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.exec();
    QFileInfo info(dialog.selectedFiles()[0]);
    QString name=info.fileName();
    QString size=QString::number(info.size());
    QString type=info.suffix();
    QString date=info.lastModified().toString();
    FileInfo tableinfo(&name,&size,&type,&date);
    tableinfo.AddRow(ui->files);

}

NewWindow::~NewWindow()
{
    delete ui;
}
