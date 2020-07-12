/****************************************************************************
** Meta object code from reading C++ file 'bar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Bar_t {
    QByteArrayData data[14];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bar_t qt_meta_stringdata_Bar = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Bar"
QT_MOC_LITERAL(1, 4, 13), // "pageToSetting"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "wantToExit"
QT_MOC_LITERAL(4, 30, 6), // "askPic"
QT_MOC_LITERAL(5, 37, 18), // "pageToPlaybackMenu"
QT_MOC_LITERAL(6, 56, 13), // "pageToImgMenu"
QT_MOC_LITERAL(7, 70, 15), // "pageToTranscode"
QT_MOC_LITERAL(8, 86, 7), // "exitSys"
QT_MOC_LITERAL(9, 94, 9), // "toSetting"
QT_MOC_LITERAL(10, 104, 8), // "takePics"
QT_MOC_LITERAL(11, 113, 8), // "playBack"
QT_MOC_LITERAL(12, 122, 11), // "imgOverview"
QT_MOC_LITERAL(13, 134, 9) // "transcode"

    },
    "Bar\0pageToSetting\0\0wantToExit\0askPic\0"
    "pageToPlaybackMenu\0pageToImgMenu\0"
    "pageToTranscode\0exitSys\0toSetting\0"
    "takePics\0playBack\0imgOverview\0transcode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,
       4,    0,   78,    2, 0x06 /* Public */,
       5,    1,   79,    2, 0x06 /* Public */,
       6,    1,   82,    2, 0x06 /* Public */,
       7,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   88,    2, 0x0a /* Public */,
       9,    0,   89,    2, 0x0a /* Public */,
      10,    0,   90,    2, 0x0a /* Public */,
      11,    0,   91,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Bar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Bar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pageToSetting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->wantToExit(); break;
        case 2: _t->askPic(); break;
        case 3: _t->pageToPlaybackMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->pageToImgMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->pageToTranscode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->exitSys(); break;
        case 7: _t->toSetting(); break;
        case 8: _t->takePics(); break;
        case 9: _t->playBack(); break;
        case 10: _t->imgOverview(); break;
        case 11: _t->transcode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Bar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bar::pageToSetting)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Bar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bar::wantToExit)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Bar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bar::askPic)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Bar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bar::pageToPlaybackMenu)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Bar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bar::pageToImgMenu)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Bar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bar::pageToTranscode)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Bar::staticMetaObject = { {
    &QMenuBar::staticMetaObject,
    qt_meta_stringdata_Bar.data,
    qt_meta_data_Bar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Bar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Bar.stringdata0))
        return static_cast<void*>(this);
    return QMenuBar::qt_metacast(_clname);
}

int Bar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Bar::pageToSetting(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Bar::wantToExit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Bar::askPic()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Bar::pageToPlaybackMenu(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Bar::pageToImgMenu(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Bar::pageToTranscode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
