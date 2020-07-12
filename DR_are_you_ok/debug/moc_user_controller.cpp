/****************************************************************************
** Meta object code from reading C++ file 'user_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../user_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserController_t {
    QByteArrayData data[15];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserController_t qt_meta_stringdata_UserController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "UserController"
QT_MOC_LITERAL(1, 15, 5), // "newId"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "registIsSuccess"
QT_MOC_LITERAL(4, 38, 9), // "isIdExist"
QT_MOC_LITERAL(5, 48, 8), // "checkRet"
QT_MOC_LITERAL(6, 57, 12), // "setIsLogined"
QT_MOC_LITERAL(7, 70, 9), // "isLogined"
QT_MOC_LITERAL(8, 80, 8), // "getNewId"
QT_MOC_LITERAL(9, 89, 6), // "regist"
QT_MOC_LITERAL(10, 96, 2), // "id"
QT_MOC_LITERAL(11, 99, 4), // "name"
QT_MOC_LITERAL(12, 104, 3), // "pwd"
QT_MOC_LITERAL(13, 108, 7), // "checkId"
QT_MOC_LITERAL(14, 116, 10) // "loginCheck"

    },
    "UserController\0newId\0\0registIsSuccess\0"
    "isIdExist\0checkRet\0setIsLogined\0"
    "isLogined\0getNewId\0regist\0id\0name\0pwd\0"
    "checkId\0loginCheck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   71,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    3,   75,    2, 0x0a /* Public */,
      13,    1,   82,    2, 0x0a /* Public */,
      14,    2,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   12,

       0        // eod
};

void UserController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->registIsSuccess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->isIdExist((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->checkRet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setIsLogined((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->getNewId(); break;
        case 6: _t->regist((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->checkId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->loginCheck((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserController::newId)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserController::registIsSuccess)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UserController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserController::isIdExist)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UserController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserController::checkRet)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_UserController.data,
    qt_meta_data_UserController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void UserController::newId(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserController::registIsSuccess(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserController::isIdExist(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UserController::checkRet(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
