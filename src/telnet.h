/*
    telnetclient, Telnet Client
*/

#ifndef TELNET_H
#define TELNET_H
#include <QObject>
#include "qttelnet.h"

class Telnet : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString version READ readVersion NOTIFY versionChanged())

public:
    explicit Telnet(QObject *parent = 0);
    ~Telnet();

    QString readVersion();

    Q_INVOKABLE void connectToTelnet(QString host);

signals:
    void versionChanged();

public slots:
    void telnetConnected();
    void telnetError(QAbstractSocket::SocketError);

private:

    QtTelnet* t;
};


#endif // TELNET_H

