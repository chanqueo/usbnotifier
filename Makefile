TARGET = usbnotifier.exe

CC = i686-pc-mingw32-gcc
CXX = i686-pc-mingw32-g++
LINKER = i686-pc-mingw32-g++

QT = /cygdrive/c/Qt/5.2.1

DEFINES = -DUNICODE -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB \
          -DQT_NEEDS_QMAIN
CFLAGS = -pipe -fno-keep-inline-dllexport -g -Wall -Wextra $(DEFINES)
CXXFLAGS = -pipe -fno-keep-inline-dllexport -g -frtti -Wall -Wextra \
           -fexceptions -mthreads $(DEFINES)
INCPATH = -I. \
          -I$(QT)/mingw48_32/include \
          -I$(QT)/mingw48_32/include/QtWidgets \
          -I$(QT)/mingw48_32/include/QtGui \
          -I$(QT)/mingw48_32/include/QtCore \
          -I$(QT)/mingw48_32/mkspecs/win32-g++

LFLAGS = -Wl,-subsystem,windows -mthreads
LIBS = -lglu32 -lopengl32 -lgdi32 -luser32 -lmingw32 -lqtmaind \
       -L$(QT)/mingw48_32/lib -lQt5Widgetsd -lQt5Guid -lQt5Cored

SOURCES = main.cpp
OBJECTS = main.o

first: all
	@echo $(INCPATH)
all: Makefile $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

$(TARGET): $(OBJECTS)
	$(LINKER) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)
