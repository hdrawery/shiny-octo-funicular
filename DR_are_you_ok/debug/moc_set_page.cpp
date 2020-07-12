/****************************************************************************
** Meta object code from reading C++ file 'set_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../set_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetPage_t {
    QByteArrayData data[14];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetPage_t qt_meta_stringdata_SetPage = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SetPage"
QT_MOC_LITERAL(1, 8, 10), // "askCamName"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "applyCamSet"
QT_MOC_LITERAL(4, 32, 12), // "finishCamSet"
QT_MOC_LITERAL(5, 45, 10), // "askCamInfo"
QT_MOC_LITERAL(6, 56, 10), // "setCamName"
QT_MOC_LITERAL(7, 67, 4), // "name"
QT_MOC_LITERAL(8, 72, 8), // "applySet"
QT_MOC_LITERAL(9, 81, 11), // "initSetPage"
QT_MOC_LITERAL(10, 93, 5), // "video"
QT_MOC_LITERAL(11, 99, 3), // "img"
QT_MOC_LITERAL(12, 103, 8), // "interval"
QT_MOC_LITERAL(13, 112, 9) // "cancelSet"

    },
    "SetPage\0askCamName\0\0applyCamSet\0"
    "finishCamSet\0askCamInfo\0setCamName\0"
    "name\0applySet\0initSetPage\0video\0img\0"
    "interval\0cancelSet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    4,   55,    2, 0x06 /* Public */,
       4,    1,   64,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   68,    2, 0x0a /* Public */,
       8,    0,   71,    2, 0x0a /* Public */,
       9,    3,   72,    2, 0x0a /* Public */,
      13,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void,

       0        // eod
};

void SetPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SetPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->askCamName(); break;
        case 1: _t->applyCamSet((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->finishCamSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->askCamInfo(); break;
        case 4: _t->setCamName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->applySet(); break;
        case 6: _t->initSetPage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->cancelSet(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SetPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPage::askCamName)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SetPage::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPage::applyCamSet)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SetPage::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPage::finishCamSet)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SetPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetPage::askCamInfo)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SetPage::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_SetPage.data,
    qt_meta_data_SetPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SetPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SetPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SetPage::askCamName()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SetPage::applyCamSet(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SetPage::finishCamSet(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SetPage::askCamInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
