FORMS +=

HEADERS += \
    qnotifierapplication.h \
    qnotifierviewer.h \
    qnotifierlistener.h

SOURCES += \
    main.cpp \
    qnotifierapplication.cpp \
    qnotifierviewer.cpp \
    qnotifierlistener.cpp

QT += \
    widgets

RESOURCES += \
    usbnotifier.qrc

win32: LIBS += -LC:\Qt\Qt5.6.0\5.6\mingw49_32\lib -lQt5Core -lQt5Gui -lQt5Widgets
