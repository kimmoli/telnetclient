/*
    telnetclient, Telnet Client
*/

import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
    id: page

    SilicaFlickable
    {
        anchors.fill: parent

        PullDownMenu
        {
            MenuItem
            {
                text: "About..."
                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"),
                                          { "version": telnet.version,
                                              "year": "2014",
                                              "name": "Telnet Client",
                                              "imagelocation": "/usr/share/icons/hicolor/86x86/apps/telnetclient.png"} )
            }
        }

        contentHeight: column.height

        Column
        {
            id: column

            width: page.width
            spacing: Theme.paddingLarge
            PageHeader
            {
                title: "Telnetclient"
            }
            Label
            {
                x: Theme.paddingLarge
                text: "Hello you"
                color: Theme.primaryColor
                font.pixelSize: Theme.fontSizeExtraLarge
            }
            Button
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "connect"
                onClicked: telnet.connectToTelnet("192.168.10.43")
            }
        }
    }

}


