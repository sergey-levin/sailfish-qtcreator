TARGET = QmlProfilerExtension
TEMPLATE = lib

PROVIDER = Digia
include(../../qtcreatorplugin.pri)

DEFINES += QMLPROFILEREXTENSION_LIBRARY
CONFIG(licensechecker): DEFINES += LICENSECHECKER

# QmlProfilerExtension files

SOURCES += qmlprofilerextensionplugin.cpp \
        scenegraphtimelinemodel.cpp \
        pixmapcachemodel.cpp \
        memoryusagemodel.cpp \
        inputeventsmodel.cpp \
        debugmessagesmodel.cpp

HEADERS += qmlprofilerextensionplugin.h \
        qmlprofilerextension_global.h \
        qmlprofilerextensionconstants.h \
        scenegraphtimelinemodel.h \
        pixmapcachemodel.h \
        memoryusagemodel.h \
        inputeventsmodel.h \
        debugmessagesmodel.h

OTHER_FILES += \
    QmlProfilerExtension.json.in
