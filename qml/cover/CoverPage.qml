/*
    telnetclient, Telnet Client
*/

import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground
{
    CoverPlaceholder
    {
        text: "Telnetclient"
        icon.source: "/usr/share/icons/hicolor/86x86/apps/telnetclient.png"
    }

    CoverActionList
    {
        CoverAction
        {
            iconSource: coverActionLeftIcon
            onTriggered: coverActionLeft()
        }

        CoverAction
        {
            iconSource: coverActionRightIcon
            onTriggered: coverActionRight()
        }
    }
}


