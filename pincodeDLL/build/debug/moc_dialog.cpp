/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDialogENDCLASS = QtMocHelpers::stringData(
    "Dialog",
    "sendString",
    "",
    "clickHandler",
    "numberClickedHandler",
    "undoClickHandler",
    "onUndoClicked",
    "onN1Clicked",
    "onN2Clicked",
    "onN3Clicked",
    "onN4Clicked",
    "onN5Clicked",
    "onN6Clicked",
    "onN7Clicked",
    "onN8Clicked",
    "onN9Clicked",
    "onN0Clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  107,    2, 0x08,    3 /* Private */,
       4,    0,  108,    2, 0x08,    4 /* Private */,
       5,    0,  109,    2, 0x08,    5 /* Private */,
       6,    0,  110,    2, 0x08,    6 /* Private */,
       7,    0,  111,    2, 0x08,    7 /* Private */,
       8,    0,  112,    2, 0x08,    8 /* Private */,
       9,    0,  113,    2, 0x08,    9 /* Private */,
      10,    0,  114,    2, 0x08,   10 /* Private */,
      11,    0,  115,    2, 0x08,   11 /* Private */,
      12,    0,  116,    2, 0x08,   12 /* Private */,
      13,    0,  117,    2, 0x08,   13 /* Private */,
      14,    0,  118,    2, 0x08,   14 /* Private */,
      15,    0,  119,    2, 0x08,   15 /* Private */,
      16,    0,  120,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Dialog, std::true_type>,
        // method 'sendString'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clickHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'numberClickedHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'undoClickHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUndoClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN1Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN2Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN3Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN4Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN5Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN6Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN7Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN8Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN9Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onN0Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendString((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->clickHandler(); break;
        case 2: _t->numberClickedHandler(); break;
        case 3: _t->undoClickHandler(); break;
        case 4: _t->onUndoClicked(); break;
        case 5: _t->onN1Clicked(); break;
        case 6: _t->onN2Clicked(); break;
        case 7: _t->onN3Clicked(); break;
        case 8: _t->onN4Clicked(); break;
        case 9: _t->onN5Clicked(); break;
        case 10: _t->onN6Clicked(); break;
        case 11: _t->onN7Clicked(); break;
        case 12: _t->onN8Clicked(); break;
        case 13: _t->onN9Clicked(); break;
        case 14: _t->onN0Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog::*)(QString );
            if (_t _q_method = &Dialog::sendString; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Dialog::sendString(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
