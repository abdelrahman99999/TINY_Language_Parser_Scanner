QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GUI_tabs/inputfile.cpp \
    GUI_tabs/scanner_tab.cpp \
    Scanner/scanner.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    GUI_tabs/inputfile.h \
    GUI_tabs/scanner_tab.h \
    Scanner/scanner.h \
    mainwindow.h

FORMS += \
    GUI_tabs/inputfile.ui \
    GUI_tabs/scanner_tab.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    Resoures.qrc
RC_ICONS = Compiler.ico
