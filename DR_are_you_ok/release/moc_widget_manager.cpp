/****************************************************************************
** Meta object code from reading C++ file 'widget_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetManager_t {
    QByteArrayData data[16];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetManager_t qt_meta_stringdata_WidgetManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WidgetManager"
QT_MOC_LITERAL(1, 14, 13), // "isNeedInitCam"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "changePage"
QT_MOC_LITERAL(4, 40, 11), // "startCamera"
QT_MOC_LITERAL(5, 52, 13), // "restartCamera"
QT_MOC_LITERAL(6, 66, 9), // "initTable"
QT_MOC_LITERAL(7, 76, 12), // "initImgTable"
QT_MOC_LITERAL(8, 89, 14), // "initListWidget"
QT_MOC_LITERAL(9, 104, 9), // "findNewId"
QT_MOC_LITERAL(10, 114, 5), // "index"
QT_MOC_LITERAL(11, 120, 12), // "setFirstPage"
QT_MOC_LITERAL(12, 133, 6), // "isNull"
QT_MOC_LITERAL(13, 140, 7), // "ImgShow"
QT_MOC_LITERAL(14, 148, 4), // "name"
QT_MOC_LITERAL(15, 153, 9) // "VideoPlay"

    },
    "WidgetManager\0isNeedInitCam\0\0changePage\0"
    "startCamera\0restartCamera\0initTable\0"
    "initImgTable\0initListWidget\0findNewId\0"
    "index\0setFirstPage\0isNull\0ImgShow\0"
    "name\0VideoPlay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,
       8,    0,   80,    2, 0x06 /* Public */,
       9,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   82,    2, 0x0a /* Public */,
      11,    1,   85,    2, 0x0a /* Public */,
      13,    2,   88,    2, 0x0a /* Public */,
      15,    2,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,   14,

       0        // eod
};

void WidgetManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isNeedInitCam(); break;
        case 1: _t->changePage(); break;
        case 2: _t->startCamera(); break;
        case 3: _t->restartCamera(); break;
        case 4: _t->initTable(); break;
        case 5: _t->initImgTable(); break;
        case 6: _t->initListWidget(); break;
        case 7: _t->findNewId(); break;
        case 8: _t->changePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setFirstPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->ImgShow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->VideoPlay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetManager::isNeedInitCam)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetManager::changePage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WidgetManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetManager::startCamera)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WidgetManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetManager::restartCamera)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WidgetManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetManager::initTable)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WidgetManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetManager::initImgTable)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WidgetManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetManager::initListWidget)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (WidgetManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetManager::findNewId)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetManager::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetManager.data,
    qt_meta_data_WidgetManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetManager.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void WidgetManager::isNeedInitCam()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WidgetManager::changePage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WidgetManager::startCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WidgetManager::restartCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WidgetManager::initTable()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WidgetManager::initImgTable()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WidgetManager::initListWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void WidgetManager::findNewId()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
