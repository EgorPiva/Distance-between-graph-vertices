QT += core
QT += gui
# Модуль core5compat недоступен в Docker-образе Ubuntu 20.04 с Qt 5.12
# QT += core5compat

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

SOURCES += \
    crypto/sha512.cpp \
    crypto/tripledes.cpp \
    math/chordmethod.cpp \
    steganography/steganography.cpp \
    network/protocol.cpp

HEADERS += \
    crypto/sha512.h \
    crypto/tripledes.h \
    math/chordmethod.h \
    steganography/steganography.h \
    network/protocol.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target 