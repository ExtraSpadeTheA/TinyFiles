//fileview_widget.cpp

#include "fileview_widget.h"
#include<QTextCodec>

FileViewWidget::FileViewWidget(QWidget *parent/*=0*/) :QWidget(parent)
{
    FileViewWidget::setAcceptDrops(true);
    this->setFixedSize(1270,810);
    this->setStyleSheet("background-image:url(:/pic/gplay.png);background-color:black");
    this->setWindowTitle("Tiny Files");
    this->setWindowIcon(QIcon(":/pic/tittle.png"));
    //—–实例化对象
    fileLineEdit = new QLineEdit("H:/",this);
    fileListWidget = new QListWidget(this);
    fileextWidget = new QListWidget(this);
    filesizeWidget = new QListWidget(this);
    filemodifiedWiget = new QListWidget(this);
    fileurl = new QLineEdit("UpLoad",this);
    submit = new QPushButton("upload",this);
    del = new QPushButton("Delete",this);
    download = new QPushButton("Download",this);
    home = new QLabel(this);
    home->setPixmap(QPixmap(":/pic/home.png"));
    home->setStyleSheet("background-color:black");
    home->setGeometry(280,50,49,50);
    home->setStyleSheet("background-color:#cccccc;border:0px groove ;border-radius:10px;padding:2px 4px");
    QPixmap pixmap;
    pixmap = QPixmap(":/pic/up.png");
    up = new QPushButton(this);
    up->setGeometry(230,50,50,50);
    pixmap = pixmap.scaled(up->width(),up->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    up->setIconSize(QSize(up->width(),up->height()));
    up->setIcon(pixmap);
    up->setFlat(true);
    up->setStyleSheet("background-color:black");


    //—布局
    fileListWidget->setGeometry(280,110,242,680);
    fileListWidget->setStyleSheet("background-color:#cccccc;border:0px groove ;border-radius:10px;padding:2px 4px");
    fileListWidget->setFont(QFont("Microsoft YaHei",7,QFont::Bold));
    filesizeWidget->setGeometry(522,110,242,680);
    filesizeWidget->setStyleSheet("background-color:#cccccc;border:0px groove ;border-radius:10px;padding:2px 4px");
    filesizeWidget->setFont(QFont("Microsoft YaHei",7,QFont::Bold));
    fileextWidget->setGeometry(764,110,242,680);
    fileextWidget->setStyleSheet("background-color:#cccccc;border:0px groove ;border-radius:10px;padding:2px 4px");
    fileextWidget->setFont(QFont("Microsoft YaHei",7,QFont::Bold));
    filemodifiedWiget->setGeometry(1006,110,242,680);
    filemodifiedWiget->setStyleSheet("background-color:#cccccc;border:0px groove ;border-radius:10px;padding:2px 4px");
    filemodifiedWiget->setFont(QFont("Microsoft YaHei",7,QFont::Medium));
    fileLineEdit->setGeometry(280,50,700,50);
    fileLineEdit->setReadOnly(true);
    fileLineEdit->setPlaceholderText("H:/");
    fileLineEdit->setStyleSheet("background-color:#cccccc;border:0px groove ;border-radius:10px;padding:2px 4px");
    fileLineEdit->setFont(QFont("Microsoft YaHei",10,QFont::Bold));
    fileurl->setGeometry(20,110,250,570);
    fileurl->setFont(QFont("Microsoft YaHei",10));
    fileurl->setStyleSheet("background-color:#cccccc;border:2px groove ;border-radius:10px;padding:2px 4px");
    submit->setGeometry(20,690,125,100);
    submit->setFont(QFont("Microsoft YaHei",9));
    submit->setStyleSheet("background-color:#cccccc;border:2px groove ;border-radius:10px;padding:2px 4px");
    download->setGeometry(145,690,125,100);
    download->setFont(QFont("Microsoft YaHei",9));
    download->setStyleSheet("background-color:#cccccc;border:2px groove ;border-radius:10px;padding:2px 4px");
    del->setGeometry(1000,50,250,50);
    del->setFont(QFont("Microsoft YaHei",10));
    del->setStyleSheet("background-color:#cccccc;border:2px groove ;border-radius:10px;padding:2px 4px");
    connect(fileLineEdit, SIGNAL(returnPressed()),
                this, SLOT(slotDirShow(QDir)));
    connect(fileListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)),
                this, SLOT(slotDirShow(QListWidgetItem*)));
    connect(submit, SIGNAL(clicked()),
                this, SLOT(refresh()));
    connect(del, SIGNAL(clicked()),
                this, SLOT(delfor()));
   // connect(download, SIGNAL(clicked()),
     //           this, SLOT(loadin()));
    connect(fileListWidget, SIGNAL(itemClicked(QListWidgetItem *)),
                this, SLOT(change()));
    connect(up, SIGNAL(clicked()),
                this, SLOT(back()));


    QString rootStr = "H:/";
    QDir rootDir(rootStr);
    QStringList stringlist;
    stringlist << "*";
    list = rootDir.entryInfoList(stringlist);
    showFileInfoList(list);

    //—显示布局

    //—-设置窗口属性
    setWindowTitle("File View");
}
QString delurl="";
//QString DownLoadPath="";
//–显示当前目录下的所有文件
void FileViewWidget::slotShow(QDir dir)
{
     QStringList stringList;
     stringList << "*";
     QFileInfoList InfoList = dir.entryInfoList(stringList,QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);

     showFileInfoList(InfoList);
}

//—用双击浏览器中显示的目录进入下一级，或者返回上一级目录。
void FileViewWidget::showFileInfoList(QFileInfoList list)
{
    //–清空列表控件
    fileListWidget->clear();
    fileextWidget->clear();
    filemodifiedWiget->clear();
    filesizeWidget->clear();
    //—-取出所有项，按照目录，文件方式添加到控件内
    for (unsigned int i = 0; i < list.count(); i++)
    {
        QFileInfo tmpFileInfo = list.at(i);
        if (tmpFileInfo.isDir())
        {

            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem*tmpListWidgetItem = new QListWidgetItem(fileName);
            fileListWidget->addItem(tmpListWidgetItem);
        }
        else
        {

            QString fileName = tmpFileInfo.fileName();

            qint64 size = tmpFileInfo.size();
            QString filesize;
            if(size>0&&size<1024){
             filesize = QString::number(size,10)+"B";
            }else if (size>1024&&size<1048576) {
             size=size/1024;
             filesize = QString::number(size,10)+"KB";
            }else if (size>1048576&&size<1073741824){
             size=size/1048576;
             filesize = QString::number(size,10)+"MB";
            }

            QString filesuffix = tmpFileInfo.suffix();
            QDateTime modify = tmpFileInfo.lastModified();
            QString filemodify = modify.toString("yyyy-MM-dd hh:mm:ss");
            QListWidgetItem*tmpname = new QListWidgetItem(fileName);
            QListWidgetItem*tmpsize = new QListWidgetItem(filesize);
            QListWidgetItem*tmpsuffix = new QListWidgetItem(filesuffix);
            QListWidgetItem*tmpmodify = new QListWidgetItem(filemodify);
            fileListWidget->addItem(tmpname);
            fileextWidget->addItem(tmpsuffix);
            filemodifiedWiget->addItem(tmpmodify);
            filesizeWidget->addItem(tmpsize);
        }
    }
}

//—-根据用户的选择显示下一级目录下的文件，
void FileViewWidget::slotDirShow(QListWidgetItem *Item)
{
    //—-保存下一级目录名
    QString string = Item->text();
    QDir dir;
    //—-设置路径为当前目录路径
    dir.setPath(fileLineEdit->text());
    //—–重新设置路径
    dir.cd(string);
    //—-更新当前显示路径， 这里获取的是绝对路径
    fileLineEdit->setText(dir.absolutePath());
    //—显示当前文件目录下的所有文件
    slotShow(dir);
}

//拖拽添加文件
void FileViewWidget::dragEnterEvent(QDragEnterEvent *event)
{

if(event->mimeData()->hasUrls())
{
    event->acceptProposedAction();
}else{
    event->ignore();
}
}

//放下事件
void FileViewWidget::dropEvent(QDropEvent *event){
    const  QMimeData *m = event->mimeData();
    if(event->mimeData()->hasUrls())
    {
    QList<QUrl> urlList = m->urls();
    QString fileName = urlList.at(0).toLocalFile();
    if(!fileName.isEmpty()){
        QByteArray qByteArrary = fileName.toUtf8();
        char* filePath = qByteArrary.data();
        if(fileurl->underMouse()){
         fileurl->setText(filePath);
            }

    }
    }
}

void FileViewWidget::dragMoveEvent(QDragMoveEvent *event)
{

}

//提交事件
void FileViewWidget::refresh(){
  /*  QString cpath = "H:/";++++++++++++-
    a.copy(cpath+"test3.txt");*/

    QDir dir;
       dir.setPath(fileLineEdit->text());
        if(!dir.path().isEmpty()){
       QString Real = fileurl->text();
       QString Fake = dir.path();
       QFileInfo Vax(Real);
       QFile currentFile(Real);
       currentFile.copy(Fake+"/"+Vax.fileName());
       fileurl->setText("");
       qint64 dl = Vax.size()/838860;
       if(dl>1){
       QTest::qSleep(dl*1000);
       }
        slotShow(dir);
        }
}

//刪除事件

void FileViewWidget::delfor(){
    QDir dir;
    dir.setPath(fileLineEdit->text());
    QFile delfile(delurl);
    delfile.remove();
    slotShow(dir);
}

void FileViewWidget::change(){
    QString a=fileLineEdit->text();
    QString b=fileListWidget->currentItem()->text();
    delurl=a+"/"+b;

}
//回退事件
void FileViewWidget::back(){
    QDir dir;
    dir.setPath(fileLineEdit->text());
    dir.cdUp();
    fileLineEdit->setText(dir.absolutePath());
    slotShow(dir);
}

//下載事件
/*void FileViewWidget::loadin(){
    QDir dir;
    dir.setPath(fileLineEdit->text());
    QFile loadfile(delurl);
    loadfile.copy(DownLoadPath);
}*/
