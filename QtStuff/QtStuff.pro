QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bedrockwall.cpp \
    bullet.cpp \
    button.cpp \
    coin.cpp \
    door.cpp \
    enemy.cpp \
    enemybullet.cpp \
    game.cpp \
    health.cpp \
    log_in.cpp \
    main.cpp \
    map.cpp \
    player.cpp \
    puddle.cpp \
    score.cpp \
    wall.cpp

HEADERS += \
    bedrockwall.h \
    bullet.h \
    button.h \
    coin.h \
    door.h \
    enemy.h \
    enemybullet.h \
    game.h \
    health.h \
    log_in.h \
    map.h \
    player.h \
    puddle.h \
    score.h \
    wall.h

FORMS += \
    log_in.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myRes.qrc

DISTFILES += \
    myQML.qml
