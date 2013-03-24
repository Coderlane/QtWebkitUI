#include "browserwindow.h"
#include "ui_browserwindow.h"

BrowserWindow::BrowserWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::BrowserWindow)
{
    ui->setupUi(this);
    UpdateURL(QUrl("http://" + HostIP +":" + QString(HostWSPort)));
}

BrowserWindow::~BrowserWindow()
{
    delete ui;
}

void BrowserWindow::Status(QString status)
{
    ui->statusLabel->setText(status);
}

void BrowserWindow::UpdateURL(QUrl url)
{
    ui->webView->setUrl(url);
}
