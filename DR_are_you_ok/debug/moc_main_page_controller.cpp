/****************************************************************************
** Meta object code from reading C++ file 'main_page_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../main_page_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_page_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainPageController_t {
    QByteArrayData data[20];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainPageController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainPageController_t qt_meta_stringdata_MainPageController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MainPageController"
QT_MOC_LITERAL(1, 19, 15), // "findCurrentDate"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "sendImg"
QT_MOC_LITERAL(4, 44, 7), // "getTime"
QT_MOC_LITERAL(5, 52, 13), // "saveVideoToDB"
QT_MOC_LITERAL(6, 66, 9), // "videoName"
QT_MOC_LITERAL(7, 76, 4), // "date"
QT_MOC_LITERAL(8, 81, 9), // "saveVideo"
QT_MOC_LITERAL(9, 91, 7), // "saveImg"
QT_MOC_LITERAL(10, 99, 5), // "count"
QT_MOC_LITERAL(11, 105, 11), // "saveImgToDB"
QT_MOC_LITERAL(12, 117, 7), // "imgName"
QT_MOC_LITERAL(13, 125, 3), // "img"
QT_MOC_LITERAL(14, 129, 13), // "startFdThread"
QT_MOC_LITERAL(15, 143, 6), // "getImg"
QT_MOC_LITERAL(16, 150, 7), // "exitSys"
QT_MOC_LITERAL(17, 158, 12), // "stopFdThread"
QT_MOC_LITERAL(18, 171, 9), // "noSendImg"
QT_MOC_LITERAL(19, 181, 7) // "restart"

    },
    "MainPageController\0findCurrentDate\0\0"
    "sendImg\0getTime\0saveVideoToDB\0videoName\0"
    "date\0saveVideo\0saveImg\0count\0saveImgToDB\0"
    "imgName\0img\0startFdThread\0getImg\0"
    "exitSys\0stopFdThread\0noSendImg\0restart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainPageController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   80,    2, 0x0a /* Public */,
       5,    5,   81,    2, 0x0a /* Public */,
      11,    3,   92,    2, 0x0a /* Public */,
       9,    1,   99,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    1,  103,    2, 0x0a /* Public */,
      16,    0,  106,    2, 0x0a /* Public */,
      17,    0,  107,    2, 0x0a /* Public */,
      18,    0,  108,    2, 0x0a /* Public */,
      19,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QImage,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,    7,    9,
    QMetaType::Void, QMetaType::QImage,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainPageController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainPageController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->findCurrentDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->getTime(); break;
        case 3: _t->saveVideoToDB((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 4: _t->saveImgToDB((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->saveImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 6: _t->startFdThread(); break;
        case 7: _t->getImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 8: _t->exitSys(); break;
        case 9: _t->stopFdThread(); break;
        case 10: _t->noSendImg(); break;
        case 11: _t->restart(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainPageController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainPageController::findCurrentDate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainPageController::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainPageController::sendImg)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainPageController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MainPageController.data,
    qt_meta_data_MainPageController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainPageController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainPageController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainPageController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainPageController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void MainPageController::findCurrentDate(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainPageController::sendImg(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
