#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>


static QString HostIP = "127.0.0.1";
static int HostTCPPort = 10236;
static int HostWSPort = 8080;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

    void Connect();
    void Disconnect();

private:
    QTcpSocket *mainSocket;


signals:
    void Connected();
    void Disconnected();
    void Status(QString status);
    void ChangeURL(QString url);

public slots:
    void ConnectToHost();
    void DisconnectFromHost();

private slots:
    void ConnectedToHost();
    void DisconnectedFromHost();
    void SocketError(QAbstractSocket::SocketError socketError );
    void SocketStateChanged ( QAbstractSocket::SocketState socketState );

};

#endif // SERVER_H
