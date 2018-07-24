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
    Truck.h \
    Car.h

SOURCES += \
	main.cpp \
	AnimatedObject.cpp \
	Game.cpp \
	Player.cpp \
	Score.cpp \
        Vehicle.cpp \
    Truck.cpp \
    Car.cpp

RESOURCES += Resources.qrc

mac {
	Resources.files = Resources
	Resources.path = Contents/MacOS
	QMAKE_BUNDLE_DATA += Resources
}


