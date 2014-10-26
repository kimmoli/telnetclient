/*
Copyright (c) 2014 kimmoli kimmo.lindholm@gmail.com @likimmo

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "telnet.h"
#include "qttelnet.h"
#include <QDebug>

Telnet::Telnet(QObject *parent) :
    QObject(parent)
{
    emit versionChanged();

    qDebug() << "here we go";

    t = new QtTelnet();

    t->connect(t, SIGNAL(connected()), this, SLOT(telnetConnected()));
    t->connect(t, SIGNAL(connectionError(QAbstractSocket::SocketError)), this, SLOT(telnetError(QAbstractSocket::SocketError)));



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
    qDebug() << "Connecting to" << host;
    t->connectToHost(host);
}


void Telnet::telnetConnected()
{
    qDebug() << "telnet connected";
    t->close();
}

void Telnet::telnetError(QAbstractSocket::SocketError err)
{
    qDebug() << "error" << err;
}
