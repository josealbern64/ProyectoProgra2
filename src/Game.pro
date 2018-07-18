QT += core gui widgets svg multimedia

TARGET = MultiFrogger
TEMPLATE = app
CONFIG += c++11

HEADERS += \
	AnimatedObject.h \
	Game.h \
	Player.h \
	Score.h \
        Vehicle.h \
        Log.h \
        GameTimer.h

SOURCES += \
	main.cpp \
	AnimatedObject.cpp \
	Game.cpp \
	Player.cpp \
	Score.cpp \
        Vehicle.cpp \
        Log.cpp \
        GameTimer.cpp

RESOURCES += Resources.qrc

mac {
	Resources.files = Resources
	Resources.path = Contents/MacOS
	QMAKE_BUNDLE_DATA += Resources
}


