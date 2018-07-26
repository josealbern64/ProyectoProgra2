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
    Car.h \
    Motorbike.h \
    Help.h \
    Menu.h \
    ConnectDialog.h

SOURCES += \
	main.cpp \
	AnimatedObject.cpp \
	Game.cpp \
	Player.cpp \
	Score.cpp \
        Vehicle.cpp \
    Truck.cpp \
    Car.cpp \
    Motorbike.cpp \
    Help.cpp \
    Menu.cpp \
    ConnectDialog.cpp

RESOURCES += Resources.qrc

mac {
	Resources.files = Resources
	Resources.path = Contents/MacOS
	QMAKE_BUNDLE_DATA += Resources
}

FORMS += \
    Help.ui \
    Menu.ui \
    ConnectDialog.ui


