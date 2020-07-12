/****************************************************************************
** Meta object code from reading C++ file 'play_page_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../play_page_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'play_page_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayPageController_t {
    QByteArrayData data[23];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayPageController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayPageController_t qt_meta_stringdata_PlayPageController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "PlayPageController"
QT_MOC_LITERAL(1, 19, 15), // "findCurrentDate"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "sendImg"
QT_MOC_LITERAL(4, 44, 8), // "finished"
QT_MOC_LITERAL(5, 53, 6), // "replay"
QT_MOC_LITERAL(6, 60, 9), // "videoSize"
QT_MOC_LITERAL(7, 70, 9), // "videoInit"
QT_MOC_LITERAL(8, 80, 13), // "startFdThread"
QT_MOC_LITERAL(9, 94, 10), // "setSources"
QT_MOC_LITERAL(10, 105, 7), // "sources"
QT_MOC_LITERAL(11, 113, 5), // "pause"
QT_MOC_LITERAL(12, 119, 6), // "getImg"
QT_MOC_LITERAL(13, 126, 3), // "img"
QT_MOC_LITERAL(14, 130, 7), // "restart"
QT_MOC_LITERAL(15, 138, 11), // "changeSpeed"
QT_MOC_LITERAL(16, 150, 4), // "mult"
QT_MOC_LITERAL(17, 155, 12), // "playFinished"
QT_MOC_LITERAL(18, 168, 7), // "saveImg"
QT_MOC_LITERAL(19, 176, 12), // "findPrevious"
QT_MOC_LITERAL(20, 189, 4), // "name"
QT_MOC_LITERAL(21, 194, 8), // "findLast"
QT_MOC_LITERAL(22, 203, 9) // "transcode"

    },
    "PlayPageController\0findCurrentDate\0\0"
    "sendImg\0finished\0replay\0videoSize\0"
    "videoInit\0startFdThread\0setSources\0"
    "sources\0pause\0getImg\0img\0restart\0"
    "changeSpeed\0mult\0playFinished\0saveImg\0"
    "findPrevious\0name\0findLast\0transcode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayPageController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       3,    1,  102,    2, 0x06 /* Public */,
       4,    0,  105,    2, 0x06 /* Public */,
       5,    0,  106,    2, 0x06 /* Public */,
       6,    1,  107,    2, 0x06 /* Public */,
       7,    1,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  113,    2, 0x0a /* Public */,
       9,    1,  114,    2, 0x0a /* Public */,
      11,    0,  117,    2, 0x0a /* Public */,
      12,    1,  118,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,
      15,    1,  122,    2, 0x0a /* Public */,
      17,    0,  125,    2, 0x0a /* Public */,
      18,    1,  126,    2, 0x0a /* Public */,
      19,    1,  129,    2, 0x0a /* Public */,
      21,    1,  132,    2, 0x0a /* Public */,
      22,    0,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,   13,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,

       0        // eod
};

void PlayPageController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayPageController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->findCurrentDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        case 3: _t->replay(); break;
        case 4: _t->videoSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->videoInit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->startFdThread(); break;
        case 7: _t->setSources((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->pause(); break;
        case 9: _t->getImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 10: _t->restart(); break;
        case 11: _t->changeSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->playFinished(); break;
        case 13: _t->saveImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 14: _t->findPrevious((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->findLast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->transcode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayPageController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayPageController::findCurrentDate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayPageController::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayPageController::sendImg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayPageController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayPageController::finished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlayPageController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayPageController::replay)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PlayPageController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayPageController::videoSize)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PlayPageController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayPageController::videoInit)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlayPageController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_PlayPageController.data,
    qt_meta_data_PlayPageController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlayPageController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayPageController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayPageController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlayPageController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void PlayPageController::findCurrentDate(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayPageController::sendImg(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayPageController::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PlayPageController::replay()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PlayPageController::videoSize(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlayPageController::videoInit(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
