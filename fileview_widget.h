#ifndef FILEVIEWWIDGET_H
#define FILEVIEWWIDGET_H

#include <QWidget>
#include <QDir>
#include <QListWidgetItem>
#include <QFileInfoList>
#include <QListWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QIcon>
#include <QStringList>
#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QUrl>
#include <QMimeData>
#include <QList>
#include <QFile>
#include <QDebug>
#include <QPushButton>
#include <QTest>
#include <QLabel>
#include <QPixmap>
#include <QSize>
class FileViewWidget : public QWidget
{
    Q_OBJECT
public:
    FileViewWidget(QWidget *parent=0);

    //—用双击浏览器中显示的目录进入下一级，或者返回上一级目录。
    void showFileInfoList(QFileInfoList list);
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
    public slots:
        //–显示当前目录下的所有文件
        void slotShow(QDir dir);

        //—-根据选择显示下一级目录下的文件，
        void slotDirShow(QListWidgetItem *Item);
        void refresh();
        void delfor();
        void change();
        void back();
       // void loadin();
private:
    QLineEdit *fileLineEdit;
    QListWidget *fileListWidget;
    QListWidget *fileextWidget;
    QListWidget *filesizeWidget;
    QListWidget *filemodifiedWiget;
    QFileInfoList list;
    QLineEdit *fileurl;
    QPushButton *submit;
    QPushButton *del;
    QPushButton *download;
    QLabel *tool;
    QLabel *lft;
    QLabel *rt;
    QPushButton *up;
    QLabel *home;
    QLabel *reset;
    QLineEdit *add;
    QLineEdit *search;
    QListWidget *meau;
    QPushButton *newfolder;


    bool copyFiles(QString sourceFile,QString destFile);
    bool copyDir(QString sourceDir,QString destDir);

};

#endif  //FILEVIEWWIDGET_H
