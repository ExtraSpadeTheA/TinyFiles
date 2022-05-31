#include "login.h"

#include <QDebug>
#include <QIcon>
#include <QRegExp>
#include <QString>

#include "newwindow.h"
#include "ui_login.h"


Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login) {
  ui->setupUi(this);
  setWindowIcon(QIcon(":/icons/res/draw-cuboid.svg"));
  setWindowTitle("Little Files");
  setFixedSize(720, 580);
  connect(ui->connect_button, &QPushButton::clicked, this, &Login::Loding);
}

Login::~Login() { delete ui; }

void Login::Loding() {
  auto username = ui->username->text();
  auto password = ui->password->text();

  ui->server_addr->setStyleSheet("background-color:none");
  ui->server_port->setStyleSheet("background-color:none");
  ui->username->setStyleSheet("background-color:none");
  ui->password->setStyleSheet("background-color:none");

  auto addr = ui->server_addr->text();
  auto port = ui->server_port->text();

  // Regular expression pattern for an IPv4 address or an english domain.
  QRegExp server_rx(R"((([0-9]{1,3}\.){3}[1-9]{1,3})|(([a-z]|[A-Z])+(\w|\.|-)*))");

  // Validate server_addr and server_port, then try to connect it.
  if (!server_rx.exactMatch(addr)) {
    ui->server_addr->setStyleSheet("background-color:#800");
    ui->status->setText("Server address invalid.");
    return;
  } else if (ui->server_port->text() == "" || port.toInt() < 0 ||
             port.toInt() > 65535) {
    ui->server_port->setStyleSheet("background-color:#800");
    ui->status->setText("Server port invalid.");
    return;
  } else {
    ui->status->setText("Connecting to : " + addr + ":" + port);
  }

  if (ui->username->text() != "song" || ui->password->text() != "123456") {
     ui->username->setStyleSheet("background-color:#800");
     ui->password->setStyleSheet("background-color:#800");
     ui->status->setText("Username or Password error.");
     return;
  }

  auto main = new NewWindow(nullptr);
  main->show();
  close();
}
