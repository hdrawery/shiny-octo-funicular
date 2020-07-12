/****************************************************************************
** Meta object code from reading C++ file 'menu_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menu_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuController_t {
    QByteArrayData data[21];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuController_t qt_meta_stringdata_MenuController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MenuController"
QT_MOC_LITERAL(1, 15, 13), // "videoOverview"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "sendVideoSum"
QT_MOC_LITERAL(4, 43, 11), // "imgOverview"
QT_MOC_LITERAL(5, 55, 10), // "sendImgSum"
QT_MOC_LITERAL(6, 66, 12), // "getVideoInfo"
QT_MOC_LITERAL(7, 79, 13), // "previousVideo"
QT_MOC_LITERAL(8, 93, 9), // "nextVideo"
QT_MOC_LITERAL(9, 103, 16), // "getVideoMaxCount"
QT_MOC_LITERAL(10, 120, 12), // "setVideoDate"
QT_MOC_LITERAL(11, 133, 4), // "date"
QT_MOC_LITERAL(12, 138, 18), // "getVideoSearchInfo"
QT_MOC_LITERAL(13, 157, 10), // "clearVideo"
QT_MOC_LITERAL(14, 168, 8), // "clearImg"
QT_MOC_LITERAL(15, 177, 10), // "getImgInfo"
QT_MOC_LITERAL(16, 188, 11), // "previousImg"
QT_MOC_LITERAL(17, 200, 7), // "nextImg"
QT_MOC_LITERAL(18, 208, 14), // "getImgMaxCount"
QT_MOC_LITERAL(19, 223, 10), // "setImgDate"
QT_MOC_LITERAL(20, 234, 16) // "getImgSearchInfo"

    },
    "MenuController\0videoOverview\0\0"
    "sendVideoSum\0imgOverview\0sendImgSum\0"
    "getVideoInfo\0previousVideo\0nextVideo\0"
    "getVideoMaxCount\0setVideoDate\0date\0"
    "getVideoSearchInfo\0clearVideo\0clearImg\0"
    "getImgInfo\0previousImg\0nextImg\0"
    "getImgMaxCount\0setImgDate\0getImgSearchInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  104,    2, 0x06 /* Public */,
       3,    1,  109,    2, 0x06 /* Public */,
       4,    2,  112,    2, 0x06 /* Public */,
       5,    1,  117,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  120,    2, 0x0a /* Public */,
       7,    0,  121,    2, 0x0a /* Public */,
       8,    0,  122,    2, 0x0a /* Public */,
       9,    0,  123,    2, 0x0a /* Public */,
      10,    1,  124,    2, 0x0a /* Public */,
      12,    0,  127,    2, 0x0a /* Public */,
      13,    0,  128,    2, 0x0a /* Public */,
      14,    0,  129,    2, 0x0a /* Public */,
      15,    0,  130,    2, 0x0a /* Public */,
      16,    0,  131,    2, 0x0a /* Public */,
      17,    0,  132,    2, 0x0a /* Public */,
      18,    0,  133,    2, 0x0a /* Public */,
      19,    1,  134,    2, 0x0a /* Public */,
      20,    0,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void MenuController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->videoOverview((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->sendVideoSum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->imgOverview((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 3: _t->sendImgSum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->getVideoInfo(); break;
        case 5: _t->previousVideo(); break;
        case 6: _t->nextVideo(); break;
        case 7: _t->getVideoMaxCount(); break;
        case 8: _t->setVideoDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->getVideoSearchInfo(); break;
        case 10: _t->clearVideo(); break;
        case 11: _t->clearImg(); break;
        case 12: _t->getImgInfo(); break;
        case 13: _t->previousImg(); break;
        case 14: _t->nextImg(); break;
        case 15: _t->getImgMaxCount(); break;
        case 16: _t->setImgDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->getImgSearchInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MenuController::*)(QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuController::videoOverview)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MenuController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuController::sendVideoSum)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MenuController::*)(QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuController::imgOverview)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MenuController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuController::sendImgSum)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MenuController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MenuController.data,
    qt_meta_data_MenuController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MenuController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MenuController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MenuController::videoOverview(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MenuController::sendVideoSum(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MenuController::imgOverview(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MenuController::sendImgSum(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
