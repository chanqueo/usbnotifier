TARGET = usbnotifier.exe

QT = /cygdrive/c/Qt/5.2.1

export PATH:=$(PATH):$(QT)/mingw48_32/bin

INCS = -I$(QT)/mingw48_32/include \
       -I$(QT)/mingw48_32/include/QtWidgets \
       -I$(QT)/mingw48_32/include/QtGui \
       -I$(QT)/mingw48_32/include/QtCore \
       -I$(QT)/mingw48_32/mkspecs/win32-g++

LIBS = -lglu32 -lopengl32 -lgdi32 -luser32 -lmingw32 -lqtmaind \
       -L$(QT)/mingw48_32/lib -lQt5Widgetsd -lQt5Guid -lQt5Cored

DEFS = -DUNICODE -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB \
       -DQT_NEEDS_QMAIN

CC = mingw32-gcc
CXX = mingw32-g++
LD = mingw32-g++
RM = rm -f
FIND = find
DEP = mingw32-gcc -MM

CFLAGS = -pipe -fno-keep-inline-dllexport -g -Wall -Wextra
CXXFLAGS = -pipe -fno-keep-inline-dllexport -g -frtti -Wall -Wextra \
           -fexceptions -mthreads
LDFLAGS = -Wl,-subsystem,windows -mthreads

HDRS = $(sort $(shell $(FIND) . -name "*.h" | sed s_^./__))
SRCS = $(sort $(shell $(FIND) . -name "*.c" -o -name "*.cpp"  | sed s_^./__))
OBJS = $(filter-out $(NO_OBJS), $(basename $(SRCS)))
OBJS := $(addsuffix .o, $(OBJS))

ifneq ($(V), 1)

ORIG_CC := $(CC)
CC = @echo CC $<; $(ORIG_CC)
ORIG_CXX := $(CXX)
CXX = @echo CXX $<; $(ORIG_CXX)
ORIG_LD := $(LD)
LD = @echo LD $@; $(ORIG_LD)
ORIG_DEP := $(DEP)
DEP = @echo DEP $@; $(ORIG_DEP)

endif

first: $(TARGET)

run: $(TARGET)
	@./$(TARGET)

%.o: %.c Makefile
	$(CC) -c $(CFLAGS) $(DEFS) $(INCS) $< -o $@

%.o: %.cpp Makefile
	$(CXX) -c $(CXXFLAGS) $(DEFS) $(INCS) $< -o $@

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

clean:
	$(RM) $(OBJS)

allclean:
	$(RM) $(TARGET) .depend

.depend: $(HDRS) $(SRCS)
	$(DEP) $(CFLAGS) $(DEFS) $(INCS) $^ > $@

ifeq ($(findstring clean, $(MAKECMDGOALS)),)
-include .depend
endif

.PHONY: first run clean allclean
