TEMPLATE = subdirs

# Указываем директорию сборки
CONFIG += shadow_build
SHADOW_BUILD_DIR = $$PWD/build

SUBDIRS += \
    Tests \
    client \
    server \
    common \
    sha512Test \
    sha512test

client.depends = common
server.depends = common

OTHER_FILES += \
    README.md \
    docker/Dockerfile \
    docker/docker-compose.yml

# Doxygen documentation
doxygen.commands = doxygen Doxyfile
doxygen.depends =
doxygen.target = docs

QMAKE_EXTRA_TARGETS += doxygen 