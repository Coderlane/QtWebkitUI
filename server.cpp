#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    mainSocket = NULL;
}

void Server::Connect()
{
    if(mainSocket != NULL)
    {
        Disconnect();
        free(mainSocket);
        mainSocket = NULL;
    }
    mainSocket = new QTcpSocket(this);
    connect(mainSocket, SIGNAL(connected ()), this, SLOT(ConnectedToHost()));
    connect(mainSocket, SIGNAL(disconnected ()), this, SLOT(DisconnectedFromHost()));
    connect(mainSocket, SIGNAL(error( QAbstractSocket::SocketError )), this, SLOT(SocketError( QAbstractSocket::SocketError )));
    connect(mainSocket, SIGNAL(stateChanged ( QAbstractSocket::SocketState )), this, SLOT(SocketStateChanged ( QAbstractSocket::SocketState )));
    mainSocket->connectToHost (HostIP, HostTCPPort, QIODevice::ReadWrite);
}

void Server::Disconnect()
{

}

void Server::DisconnectFromHost()
{

}

void Server::ConnectToHost()
{


}

void Server::ConnectedToHost()
{
    emit Connected();
}

void Server::DisconnectedFromHost()
{
    emit Disconnected();
}


/* Server::SocketError
 * Handle all possible errors that could occur
 * See: http://qt-project.org/doc/qt-4.8/qabstractsocket.html#SocketError-enum
 */
void Server::SocketError(QAbstractSocket::SocketError socketError )
{
    switch (socketError)
    {
        case QAbstractSocket::ConnectionRefusedError:
            emit Status("The connection was refused by the peer (or timed out)");
            break;
        case QAbstractSocket::RemoteHostClosedError:
            emit Status("The remote host closed the connection. Note that the client socket (i.e., this socket) will be closed after the remote close notification has been sent.");
            break;
        case QAbstractSocket::HostNotFoundError:
            emit Status("The host address was not found.");
            break;
        case QAbstractSocket::SocketAccessError:
            emit Status("The socket operation failed because the application lacked the required privileges.");
            break;
        case QAbstractSocket::SocketResourceError:
            emit Status("The local system ran out of resources (e.g., too many sockets).");
            break;
        case QAbstractSocket::SocketTimeoutError:
            emit Status("The socket operation timed out.");
            break;
        case QAbstractSocket::NetworkError:
            emit Status("An error occurred with the network (e.g., the network cable was accidentally plugged out).");
            break;
        case QAbstractSocket::AddressInUseError:
            emit Status("The address specified to QUdpSocket::bind() is already in use and was set to be exclusive.");
            break;
        case QAbstractSocket::SocketAddressNotAvailableError:
            emit Status("The address specified to QUdpSocket::bind() does not belong to the host.");
            break;
        case QAbstractSocket::UnsupportedSocketOperationError:
            emit Status("The requested socket operation is not supported by the local operating system (e.g., lack of IPv6 support).");
            break;
        case QAbstractSocket::ProxyAuthenticationRequiredError:
            emit Status("The socket is using a proxy, and the proxy requires authentication.");
            break;
        case QAbstractSocket::UnfinishedSocketOperationError:
            emit Status("Used by QAbstractSocketEngine only, The last operation attempted has not finished yet (still in progress in the background)");
            break;
        case QAbstractSocket::ProxyConnectionRefusedError:
            emit Status("Could not contact the proxy server because the connection to that server was denied ");
            break;
        case QAbstractSocket::ProxyConnectionClosedError:
            emit Status("The connection to the proxy server was closed unexpectedly (before the connection to the final peer was established)");
            break;
        case QAbstractSocket::ProxyConnectionTimeoutError:
            emit Status("The connection to the proxy server timed out or the proxy server stopped responding in the authentication phase.");
            break;
        case QAbstractSocket::ProxyNotFoundError:
            emit Status("The proxy address set with setProxy() (or the application proxy) was not found.");
            break;
        case QAbstractSocket::ProxyProtocolError:
            emit Status("The connection negotiation with the proxy server because the response from the proxy server could not be understood. ");
            break;
        case QAbstractSocket::UnknownSocketError:
            emit Status("An unidentified error occurred.");
            break;
        default:
            emit Status("An unidentified error occurred.");
            break;

    }
}
/* Server::SocketStateChanged
 * Handle all possible socket state changes
 * See: http://qt-project.org/doc/qt-4.8/qabstractsocket.html#SocketState-enum
 */
void Server::SocketStateChanged ( QAbstractSocket::SocketState socketState )
{
    switch (socketState)
    {
        case QAbstractSocket::UnconnectedState:
            emit Status("The socket is not connected.");
            break;
        case QAbstractSocket::HostLookupState:
            emit Status("The socket is performing a host name lookup.");
            break;
        case QAbstractSocket::ConnectingState:
            emit Status("The socket has started establishing a connection.");
            break;
        case QAbstractSocket::ConnectedState:
            emit Status("A connection is established.");
            break;
        case QAbstractSocket::BoundState:
            emit Status("The socket is bound to an address and port (for servers).");
            break;
        case QAbstractSocket::ClosingState:
            emit Status("The socket is about to close (data may still be waiting to be written).");
            break;
        case QAbstractSocket::ListeningState:
            emit Status("For internal use only.");
            break;
        default:
            emit Status("Unidentified socket state.");
            break;
    }
}
