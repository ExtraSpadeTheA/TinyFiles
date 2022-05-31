#ifndef FILEINFO_H
#define FILEINFO_H

#include <QString>
#include <QTableWidget>

class FileInfo {
 public:
  // Create a FileInfo object by 4 QString* which contains
  // the content that you wish insert into the table.
  FileInfo(const QString* name, const QString* size, const QString* type,
           const QString* update_time);

  // Add a row for the table. The table's header should be this format:
  // |Name|Size|Type|Date Modified|
  void AddRow(QTableWidget* table);

 private:
  const QString* name_;
  const QString* size_;
  const QString* type_;
  const QString* update_time_;
};

#endif  // FILEINFO_H
