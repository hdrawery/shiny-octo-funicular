/****************************************************************************
** Meta object code from reading C++ file 'transcode_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../transcode_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transcode_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TranscodePage_t {
    QByteArrayData data[18];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TranscodePage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TranscodePage_t qt_meta_stringdata_TranscodePage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TranscodePage"
QT_MOC_LITERAL(1, 14, 14), // "initListWidget"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "searchVideo"
QT_MOC_LITERAL(4, 42, 9), // "transcode"
QT_MOC_LITERAL(5, 52, 10), // "pageToMain"
QT_MOC_LITERAL(6, 63, 10), // "videoClear"
QT_MOC_LITERAL(7, 74, 10), // "chooseDate"
QT_MOC_LITERAL(8, 85, 11), // "setDateSlot"
QT_MOC_LITERAL(9, 97, 7), // "setPath"
QT_MOC_LITERAL(10, 105, 13), // "setListWidget"
QT_MOC_LITERAL(11, 119, 4), // "name"
QT_MOC_LITERAL(12, 124, 5), // "cover"
QT_MOC_LITERAL(13, 130, 6), // "search"
QT_MOC_LITERAL(14, 137, 11), // "toTranscode"
QT_MOC_LITERAL(15, 149, 12), // "initProgress"
QT_MOC_LITERAL(16, 162, 3), // "max"
QT_MOC_LITERAL(17, 166, 12) // "returnToMain"

    },
    "TranscodePage\0initListWidget\0\0searchVideo\0"
    "transcode\0pageToMain\0videoClear\0"
    "chooseDate\0setDateSlot\0setPath\0"
    "setListWidget\0name\0cover\0search\0"
    "toTranscode\0initProgress\0max\0returnToMain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TranscodePage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       4,    3,   83,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    2,   97,    2, 0x0a /* Public */,
      13,    0,  102,    2, 0x0a /* Public */,
      14,    0,  103,    2, 0x0a /* Public */,
      15,    1,  104,    2, 0x0a /* Public */,
      17,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,

       0        // eod
};

void TranscodePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TranscodePage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initListWidget(); break;
        case 1: _t->searchVideo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->transcode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->pageToMain((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->videoClear(); break;
        case 5: _t->chooseDate(); break;
        case 6: _t->setDateSlot(); break;
        case 7: _t->setPath(); break;
        case 8: _t->setListWidget((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 9: _t->search(); break;
        case 10: _t->toTranscode(); break;
        case 11: _t->initProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->returnToMain(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TranscodePage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TranscodePage::initListWidget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TranscodePage::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TranscodePage::searchVideo)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TranscodePage::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TranscodePage::transcode)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TranscodePage::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TranscodePage::pageToMain)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TranscodePage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TranscodePage::videoClear)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TranscodePage::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_TranscodePage.data,
    qt_meta_data_TranscodePage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TranscodePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TranscodePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TranscodePage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TranscodePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TranscodePage::initListWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TranscodePage::searchVideo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TranscodePage::transcode(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TranscodePage::pageToMain(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TranscodePage::videoClear()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
