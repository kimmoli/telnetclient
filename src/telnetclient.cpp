/*
    telnetclient, Telnet Client
*/


#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QtQml>
#include <QScopedPointer>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QCoreApplication>
#include "telnet.h"


int main(int argc, char *argv[])
{
    qmlRegisterType<Telnet>("telnetclient.Telnet", 1, 0, "Telnet");

    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());
    view->setSource(SailfishApp::pathTo("qml/telnetclient.qml"));
    view->show();

    return app->exec();
}

