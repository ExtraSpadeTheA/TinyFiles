#include "fileinfo.h"

enum { NAME = 0, SIZE = 1, TYPE = 2, UPDATE_TIME = 3 };

FileInfo::FileInfo(const QString* name, const QString* size,
                   const QString* type, const QString* update_time)
    : name_(name), size_(size), type_(type), update_time_(update_time) {}

void FileInfo::AddRow(QTableWidget* table) {
  auto row_count = table->rowCount();
  table->setRowCount(row_count + 1);
  auto name = new QTableWidgetItem(*name_);
  auto size = new QTableWidgetItem(*size_);
  auto type = new QTableWidgetItem(*type_);
  auto update_time = new QTableWidgetItem(*update_time_);

  table->setItem(row_count, NAME, name);
  table->setItem(row_count, SIZE, size);
  table->setItem(row_count, TYPE, type);
  table->setItem(row_count, UPDATE_TIME, update_time);
}
