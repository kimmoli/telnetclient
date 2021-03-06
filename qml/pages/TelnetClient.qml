/*
    telnetclient, Telnet Client
*/

import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
    id: page

    BusyIndicator
    {
        anchors.centerIn: parent
        running: telnet.connecting
        visible: telnet.connecting
    }

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

            TextField
            {
                id: hostAddress
                placeholderText: "host:port"
                text: "192.168.10.43"
                inputMethodHints: Qt.ImhPreferLowercase
                width: parent.width - 100
                //validator: RegExpValidator { regExp: /^\S+([:]\d+){1}|^[^:]+$/ }
                anchors.horizontalCenter: parent.horizontalCenter
                EnterKey.onClicked: telnet.telnetSend(sendData.text)
            }

            Button
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: telnet.connected ? "disconnect" : "connect"
                onClicked:
                {
                    if (telnet.connected)
                        telnet.disconnectTelnet()
                    else
                        telnet.connectToTelnet(hostAddress.text)
                }
            }

            TextField
            {
                id: sendData
                placeholderText: "Enter something here"
                inputMethodHints: Qt.ImhPreferLowercase
                width: parent.width - 100
                //validator: RegExpValidator { regExp: /[0-9a-fA-F]{1,2}/ }
                anchors.horizontalCenter: parent.horizontalCenter
                EnterKey.onClicked: telnet.telnetSend(sendData.text)
            }

            Label
            {
                id: readData
                width: parent.width - 100
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.Wrap
                text: telnet.data
            }


        }
    }

}


