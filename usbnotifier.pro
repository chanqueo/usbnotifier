FORMS +=

HEADERS += \
    qnotifierapplication.h \
    qnotifierviewer.h \
    qnotifierlistener.h \
    qnotifiersettings.h

SOURCES += \
    main.cpp \
    qnotifierapplication.cpp \
    qnotifierviewer.cpp \
    qnotifierlistener.cpp \
    qnotifiersettings.cpp

QT += \
    widgets

RESOURCES += \
    usbnotifier.qrc

win32: LIBS += -LC:\Qt\Qt5.6.0\5.6\mingw49_32\lib -lQt5Core -lQt5Gui -lQt5Widgets
