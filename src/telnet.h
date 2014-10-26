/*
    telnetclient, Telnet Client
*/

#ifndef TELNET_H
#define TELNET_H
#include <QObject>

class Telnet : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString version READ readVersion NOTIFY versionChanged())

public:
    explicit Telnet(QObject *parent = 0);
    ~Telnet();

    QString readVersion();

signals:
    void versionChanged();

    //private:

};


#endif // TELNET_H

