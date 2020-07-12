/****************************************************************************
** Meta object code from reading C++ file 'img_menu_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../img_menu_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'img_menu_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImgMenuPage_t {
    QByteArrayData data[16];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImgMenuPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImgMenuPage_t qt_meta_stringdata_ImgMenuPage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImgMenuPage"
QT_MOC_LITERAL(1, 12, 9), // "initTable"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "askMaxCount"
QT_MOC_LITERAL(4, 35, 9), // "searchImg"
QT_MOC_LITERAL(5, 45, 10), // "pageToMain"
QT_MOC_LITERAL(6, 56, 9), // "lookUpImg"
QT_MOC_LITERAL(7, 66, 8), // "imgClear"
QT_MOC_LITERAL(8, 75, 10), // "chooseDate"
QT_MOC_LITERAL(9, 86, 11), // "setDateSlot"
QT_MOC_LITERAL(10, 98, 8), // "setTable"
QT_MOC_LITERAL(11, 107, 4), // "name"
QT_MOC_LITERAL(12, 112, 5), // "cover"
QT_MOC_LITERAL(13, 118, 6), // "search"
QT_MOC_LITERAL(14, 125, 12), // "returnToMain"
QT_MOC_LITERAL(15, 138, 7) // "openImg"

    },
    "ImgMenuPage\0initTable\0\0askMaxCount\0"
    "searchImg\0pageToMain\0lookUpImg\0imgClear\0"
    "chooseDate\0setDateSlot\0setTable\0name\0"
    "cover\0search\0returnToMain\0openImg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImgMenuPage[] = {

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
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    1,   76,    2, 0x06 /* Public */,
       5,    1,   79,    2, 0x06 /* Public */,
       6,    2,   82,    2, 0x06 /* Public */,
       7,    0,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   88,    2, 0x0a /* Public */,
       9,    0,   89,    2, 0x0a /* Public */,
      10,    2,   90,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImgMenuPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImgMenuPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initTable(); break;
        case 1: _t->askMaxCount(); break;
        case 2: _t->searchImg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->pageToMain((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->lookUpImg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->imgClear(); break;
        case 6: _t->chooseDate(); break;
        case 7: _t->setDateSlot(); break;
        case 8: _t->setTable((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 9: _t->search(); break;
        case 10: _t->returnToMain(); break;
        case 11: _t->openImg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImgMenuPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgMenuPage::initTable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImgMenuPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgMenuPage::askMaxCount)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ImgMenuPage::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgMenuPage::searchImg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ImgMenuPage::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgMenuPage::pageToMain)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ImgMenuPage::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgMenuPage::lookUpImg)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ImgMenuPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgMenuPage::imgClear)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImgMenuPage::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ImgMenuPage.data,
    qt_meta_data_ImgMenuPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImgMenuPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImgMenuPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImgMenuPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ImgMenuPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ImgMenuPage::initTable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ImgMenuPage::askMaxCount()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ImgMenuPage::searchImg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImgMenuPage::pageToMain(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ImgMenuPage::lookUpImg(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ImgMenuPage::imgClear()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
