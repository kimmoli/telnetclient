/*
Copyright (c) 2014 kimmoli kimmo.lindholm@gmail.com @likimmo

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "telnet.h"
#include "qttelnet.h"
#include <QDebug>
#include <QStringList>

Telnet::Telnet(QObject *parent) :
    QObject(parent)
{
    emit versionChanged();

    qDebug() << "here we go";
    m_data = "N/A";
    m_connected = false;
    m_connecting = false;

    emit dataChanged();
    emit connectedChanged();

    t = new QtTelnet();

    t->connect(t, SIGNAL(connected()), this, SLOT(telnetConnected()));
    t->connect(t, SIGNAL(connectionError(QAbstractSocket::SocketError)), this, SLOT(telnetError(QAbstractSocket::SocketError)));
    t->connect(t, SIGNAL(message(const QString&)), this, SLOT(telnetReceive(const QString&)));

}

Telnet::~Telnet()
{
}

QString Telnet::readVersion()
{
    return APPVERSION;
}

void Telnet::connectToTelnet(QString host)
{
    qint16 port = 23;

    QStringList hostPort = host.split(":");
    if (hostPort.count() == 2)
        port = hostPort.at(1).toInt();

    qDebug() << "Connecting to" << host << port;
    t->connectToHost(hostPort.at(0), port);
    m_connecting = true;
    emit connectingChanged();
}


void Telnet::telnetConnected()
{
    qDebug() << "telnet connected";

    m_connected = true;
    emit connectedChanged();
    m_connecting = false;
    emit connectingChanged();
}

void Telnet::disconnectTelnet()
{
    qDebug() << "disconnect";

    t->close();
    m_connected = false;
    emit connectedChanged();
}

void Telnet::telnetError(QAbstractSocket::SocketError err)
{
    qDebug() << "error:" << err;
    m_connecting = false;
    emit connectingChanged();
}

void Telnet::telnetReceive(const QString &data)
{
    qDebug() << "receive:" << data;

    m_data = data;
    emit dataChanged();
}

void Telnet::telnetSend(QString data)
{
    qDebug() << "send:" << data;
    t->sendData(data.append("\r\n"));
}
