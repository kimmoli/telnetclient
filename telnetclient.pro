#
# Project telnetclient, Telnet Client
#

TARGET = telnetclient

CONFIG += sailfishapp

DEFINES += "APPVERSION=\\\"$${SPECVERSION}\\\""

message($${DEFINES})

SOURCES += src/telnetclient.cpp \
	src/telnet.cpp \
    src/qttelnet.cpp
	
HEADERS += src/telnet.h \
    src/qttelnet.h

OTHER_FILES += qml/telnetclient.qml \
    qml/cover/CoverPage.qml \
    qml/pages/TelnetClient.qml \
    qml/pages/AboutPage.qml \
    rpm/telnetclient.spec \
	telnetclient.png \
    telnetclient.desktop

