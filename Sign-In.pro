QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    admin.cpp \
    admin_profile.cpp \
    del.cpp \
    edit.cpp \
    giveback.cpp \
    main.cpp \
    mem_info.cpp \
    member.cpp \
    profile.cpp \
    rent.cpp \
    search.cpp \
    signin.cpp \
    signup.cpp \
    status.cpp \
    wellcome.cpp

HEADERS += \
    add.h \
    admin.h \
    admin_profile.h \
    del.h \
    edit.h \
    giveback.h \
    mem_info.h \
    member.h \
    profile.h \
    rent.h \
    search.h \
    signin.h \
    signup.h \
    status.h \
    wellcome.h

FORMS += \
    add.ui \
    admin.ui \
    admin_profile.ui \
    del.ui \
    edit.ui \
    giveback.ui \
    mem_info.ui \
    member.ui \
    profile.ui \
    rent.ui \
    search.ui \
    signin.ui \
    signup.ui \
    status.ui \
    wellcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

DISTFILES += \
    C:/Users/DELTAcomputer/Desktop/icons/add/add1.png \
    C:/Users/DELTAcomputer/Desktop/icons/add/add2.png \
    C:/Users/DELTAcomputer/Desktop/icons/add/add3.jpg \
    C:/Users/DELTAcomputer/Desktop/icons/edit/book (6).png \
    C:/Users/DELTAcomputer/Desktop/icons/main/add.PNG \
    C:/Users/DELTAcomputer/Desktop/icons/main/all.png \
    C:/Users/DELTAcomputer/Desktop/icons/main/edit.PNG \
    C:/Users/DELTAcomputer/Desktop/icons/main/remove.PNG \
    C:/Users/DELTAcomputer/Desktop/icons/main/search.png \
    C:/Users/DELTAcomputer/Desktop/icons/remove/50665230-remove-book-icon.jpg
