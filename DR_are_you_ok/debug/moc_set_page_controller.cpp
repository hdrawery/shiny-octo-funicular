/****************************************************************************
** Meta object code from reading C++ file 'set_page_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../set_page_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_page_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetPageController_t {
    QByteArrayData data[13];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetPageController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetPageController_t qt_meta_stringdata_SetPageController = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SetPageController"
QT_MOC_LITERAL(1, 18, 11), // "checkCamRet"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "findCamName"
QT_MOC_LITERAL(4, 43, 11), // "findCamInfo"
QT_MOC_LITERAL(5, 55, 12), // "checkCamInfo"
QT_MOC_LITERAL(6, 68, 10), // "getCamName"
QT_MOC_LITERAL(7, 79, 6), // "setCam"
QT_MOC_LITERAL(8, 86, 5), // "video"
QT_MOC_LITERAL(9, 92, 3), // "img"
QT_MOC_LITERAL(10, 96, 3), // "itv"
QT_MOC_LITERAL(11, 100, 4), // "name"
QT_MOC_LITERAL(12, 105, 10) // "getCamInfo"

    },
    "SetPageController\0checkCamRet\0\0"
    "findCamName\0findCamInfo\0checkCamInfo\0"
    "getCamName\0setCam\0video\0img\0itv\0name\0"
    "getCamInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetPageController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    3,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    4,   64,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,
    QMetaType::Void,

       0        // eod
};

void SetPageController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SetPageController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkCamRet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->findCamName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->findCamInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->checkCamInfo(); break;
        case 4: _t->getCamName(); break;
        case 5: _t->setCam((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 6: _t->getCamInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SetPageController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPageController::checkCamRet)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SetPageController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPageController::findCamName)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SetPageController::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPageController::findCamInfo)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SetPageController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SetPageController.data,
    qt_meta_data_SetPageController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SetPageController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetPageController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetPageController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SetPageController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SetPageController::checkCamRet(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SetPageController::findCamName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SetPageController::findCamInfo(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
