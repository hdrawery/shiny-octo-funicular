QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT       += multimedia
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animation_item.cpp \
    animation_view.cpp \
    bar.cpp \
    cache.cpp \
    dbutil.cpp \
    fdecode.cpp \
    fencode.cpp \
    img.cpp \
    img_dao.cpp \
    img_label.cpp \
    img_menu_page.cpp \
    img_page.cpp \
    img_page_controller.cpp \
    img_table.cpp \
    line_edit.cpp \
    login_page.cpp \
    main.cpp \
    main_page.cpp \
    main_page_controller.cpp \
    menu_controller.cpp \
    play_page.cpp \
    play_page_controller.cpp \
    playback_menu_page.cpp \
    register_page.cpp \
    set_page.cpp \
    set_page_controller.cpp \
    setting_dao.cpp \
    transcode_page.cpp \
    transcode_page_controller.cpp \
    user.cpp \
    user_controller.cpp \
    user_dao.cpp \
    video.cpp \
    video_bar.cpp \
    video_dao.cpp \
    video_label.cpp \
    video_list_widget.cpp \
    widget_manager.cpp

HEADERS += \
    animation_item.h \
    animation_view.h \
    bar.h \
    cache.h \
    dbutil.h \
    fdecode.h \
    fencode.h \
    img.h \
    img_dao.h \
    img_label.h \
    img_menu_page.h \
    img_page.h \
    img_page_controller.h \
    img_table.h \
    line_edit.h \
    login_page.h \
    main_page.h \
    main_page_controller.h \
    menu_controller.h \
    play_page.h \
    play_page_controller.h \
    playback_menu_page.h \
    register_page.h \
    set_page.h \
    set_page_controller.h \
    setting_dao.h \
    sqlite3.h \
    transcode_page.h \
    transcode_page_controller.h \
    user.h \
    user_controller.h \
    user_dao.h \
    video.h \
    video_bar.h \
    video_dao.h \
    video_label.h \
    video_list_widget.h \
    widget_manager.h

FORMS +=

INCLUDEPATH += $$PWD/ffmpeg/include

LIBS +=$$PWD/ffmpeg/lib/avdevice.lib \
       $$PWD/ffmpeg/lib/avcodec.lib \
       $$PWD/ffmpeg/lib/avfilter.lib \
       $$PWD/ffmpeg/lib/avutil.lib \
       $$PWD/ffmpeg/lib/swscale.lib \
       $$PWD/ffmpeg/lib/avformat.lib \
       $$PWD/ffmpeg/lib/swresample.lib \
       $$PWD/ffmpeg/sqlite3.lib
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc \
    qss.qrc

DESTDIR=bin
