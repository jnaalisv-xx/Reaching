SOURCES += Main.cpp
SOURCES += BackgroundWidget.cpp

HEADERS += BackgroundWidget.hpp

CONFIG -= qt

TARGET = Reaching

macx {
  LIBS += -framework Nimble 
  LIBS += -framework Radiant -framework Luminous -framework Screenplay
  LIBS += -framework MultiTouch -framework MultiWidgets
  LIBS += -lSDL -lSDLmain

  LIBS += -framework Cocoa
}

linux-* {
  LIBS += -lMultiWidgets
}

win* {
  # You may need to edit CORNERSTONE_ROOT to match your installation.

  CORNERSTONE_ROOT="C:\CornerStone"

  INCLUDEPATH += $$CORNERSTONE_ROOT\include 
  
  LIBS += -L$$CORNERSTONE_ROOT\lib
  LIBS += -lMultiWidgets -lFluffy -lValuable -lRadiant -lNimble -lSDLmain -lSDL

  CONFIG += console
}
