/****************************************************************************
** Meta object code from reading C++ file 'transcode_page_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../transcode_page_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transcode_page_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TranscodePageController_t {
    QByteArrayData data[17];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TranscodePageController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TranscodePageController_t qt_meta_stringdata_TranscodePageController = {
    {
QT_MOC_LITERAL(0, 0, 23), // "TranscodePageController"
QT_MOC_LITERAL(1, 24, 13), // "videoOverview"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 9), // "videoSize"
QT_MOC_LITERAL(4, 49, 9), // "sendCount"
QT_MOC_LITERAL(5, 59, 13), // "previousVideo"
QT_MOC_LITERAL(6, 73, 9), // "nextVideo"
QT_MOC_LITERAL(7, 83, 12), // "getVideoInfo"
QT_MOC_LITERAL(8, 96, 18), // "getVideoSearchInfo"
QT_MOC_LITERAL(9, 115, 12), // "setVideoDate"
QT_MOC_LITERAL(10, 128, 15), // "transcodeThread"
QT_MOC_LITERAL(11, 144, 4), // "name"
QT_MOC_LITERAL(12, 149, 8), // "savePath"
QT_MOC_LITERAL(13, 158, 6), // "format"
QT_MOC_LITERAL(14, 165, 11), // "setProgress"
QT_MOC_LITERAL(15, 177, 5), // "index"
QT_MOC_LITERAL(16, 183, 10) // "clearVideo"

    },
    "TranscodePageController\0videoOverview\0"
    "\0videoSize\0sendCount\0previousVideo\0"
    "nextVideo\0getVideoInfo\0getVideoSearchInfo\0"
    "setVideoDate\0transcodeThread\0name\0"
    "savePath\0format\0setProgress\0index\0"
    "clearVideo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TranscodePageController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       3,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   80,    2, 0x0a /* Public */,
       6,    0,   81,    2, 0x0a /* Public */,
       7,    0,   82,    2, 0x0a /* Public */,
       8,    0,   83,    2, 0x0a /* Public */,
       9,    1,   84,    2, 0x0a /* Public */,
      10,    3,   87,    2, 0x0a /* Public */,
      14,    1,   94,    2, 0x0a /* Public */,
      16,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

void TranscodePageController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TranscodePageController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->videoOverview((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->videoSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->previousVideo(); break;
        case 4: _t->nextVideo(); break;
        case 5: _t->getVideoInfo(); break;
        case 6: _t->getVideoSearchInfo(); break;
        case 7: _t->setVideoDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->transcodeThread((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 9: _t->setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->clearVideo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TranscodePageController::*)(QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TranscodePageController::videoOverview)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TranscodePageController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TranscodePageController::videoSize)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TranscodePageController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TranscodePageController::sendCount)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TranscodePageController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TranscodePageController.data,
    qt_meta_data_TranscodePageController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TranscodePageController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TranscodePageController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TranscodePageController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TranscodePageController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TranscodePageController::videoOverview(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TranscodePageController::videoSize(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TranscodePageController::sendCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
