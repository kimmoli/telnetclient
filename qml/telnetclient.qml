/*
    telnetclient, Telnet Client
*/

import QtQuick 2.0
import Sailfish.Silica 1.0
import telnetclient.Telnet 1.0

ApplicationWindow
{
    id: telnetclient

    property string coverActionLeftIcon: "image://theme/icon-cover-pause"
    property string coverActionRightIcon: "image://theme/icon-cover-play"

    initialPage: Qt.resolvedUrl("pages/TelnetClient.qml")
    cover: Qt.resolvedUrl("cover/CoverPage.qml")

    function coverActionLeft()
    {
        console.log("Left cover action")
    }

    function coverActionRight()
    {
        console.log("Right cover action")
    }

    Telnet
    {
        id: telnet
    }
}


