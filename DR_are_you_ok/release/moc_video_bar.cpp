/****************************************************************************
** Meta object code from reading C++ file 'video_bar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../video_bar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_bar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoBar_t {
    QByteArrayData data[18];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoBar_t qt_meta_stringdata_VideoBar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "VideoBar"
QT_MOC_LITERAL(1, 9, 5), // "pause"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "restart"
QT_MOC_LITERAL(4, 24, 5), // "speed"
QT_MOC_LITERAL(5, 30, 5), // "value"
QT_MOC_LITERAL(6, 36, 12), // "findPrevious"
QT_MOC_LITERAL(7, 49, 8), // "findLast"
QT_MOC_LITERAL(8, 58, 12), // "stopAndStart"
QT_MOC_LITERAL(9, 71, 11), // "speedChange"
QT_MOC_LITERAL(10, 83, 15), // "setSpeedRestore"
QT_MOC_LITERAL(11, 99, 10), // "initSlider"
QT_MOC_LITERAL(12, 110, 3), // "len"
QT_MOC_LITERAL(13, 114, 12), // "valueChanged"
QT_MOC_LITERAL(14, 127, 13), // "previousVideo"
QT_MOC_LITERAL(15, 141, 9), // "lastVideo"
QT_MOC_LITERAL(16, 151, 8), // "initInfo"
QT_MOC_LITERAL(17, 160, 4) // "name"

    },
    "VideoBar\0pause\0\0restart\0speed\0value\0"
    "findPrevious\0findLast\0stopAndStart\0"
    "speedChange\0setSpeedRestore\0initSlider\0"
    "len\0valueChanged\0previousVideo\0lastVideo\0"
    "initInfo\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    1,   86,    2, 0x06 /* Public */,
       5,    1,   89,    2, 0x06 /* Public */,
       6,    1,   92,    2, 0x06 /* Public */,
       7,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   98,    2, 0x0a /* Public */,
       9,    0,   99,    2, 0x0a /* Public */,
      10,    0,  100,    2, 0x0a /* Public */,
      11,    1,  101,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    0,  105,    2, 0x0a /* Public */,
      15,    0,  106,    2, 0x0a /* Public */,
      16,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void VideoBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pause(); break;
        case 1: _t->restart(); break;
        case 2: _t->speed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->findPrevious((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->findLast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->stopAndStart(); break;
        case 7: _t->speedChange(); break;
        case 8: _t->setSpeedRestore(); break;
        case 9: _t->initSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->valueChanged(); break;
        case 11: _t->previousVideo(); break;
        case 12: _t->lastVideo(); break;
        case 13: _t->initInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoBar::pause)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoBar::restart)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoBar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoBar::speed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoBar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoBar::value)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VideoBar::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoBar::findPrevious)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VideoBar::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoBar::findLast)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VideoBar::staticMetaObject = { {
    &QMenuBar::staticMetaObject,
    qt_meta_stringdata_VideoBar.data,
    qt_meta_data_VideoBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoBar.stringdata0))
        return static_cast<void*>(this);
    return QMenuBar::qt_metacast(_clname);
}

int VideoBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void VideoBar::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoBar::restart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VideoBar::speed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VideoBar::value(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void VideoBar::findPrevious(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void VideoBar::findLast(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
