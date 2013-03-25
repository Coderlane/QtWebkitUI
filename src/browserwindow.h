#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include "server.h"


namespace Ui {
class BrowserWindow;
}

class BrowserWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit BrowserWindow(QWidget *parent = 0);
    ~BrowserWindow();
    
private:
    Ui::BrowserWindow *ui;

public slots:
    void Status(QString status);
    void UpdateURL(QUrl url);


};

#endif // BROWSERWINDOW_H
