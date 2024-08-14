/****************************************************************************
** Meta object code from reading C++ file 'userGUI.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../userGUI.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
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
struct qt_meta_stringdata_CLASSUserWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUserWidgetENDCLASS = QtMocHelpers::stringData(
    "UserWidget",
    "seeTutorialGUI",
    "",
    "seeWatchListGUI",
    "goBackGUI",
    "filterByPresenterGUI",
    "setPresenterGUI",
    "addToWatchListGUI",
    "removeWatchListGUI",
    "openFileGUI",
    "setUpOpenButton",
    "setUpBackButton",
    "goToNextTutorialGUI",
    "setUpWatchListButton",
    "seeTutorialButton"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x0a,    1 /* Public */,
       3,    0,   93,    2, 0x0a,    2 /* Public */,
       4,    0,   94,    2, 0x0a,    3 /* Public */,
       5,    0,   95,    2, 0x0a,    4 /* Public */,
       6,    0,   96,    2, 0x0a,    5 /* Public */,
       7,    0,   97,    2, 0x0a,    6 /* Public */,
       8,    0,   98,    2, 0x0a,    7 /* Public */,
       9,    0,   99,    2, 0x0a,    8 /* Public */,
      10,    0,  100,    2, 0x0a,    9 /* Public */,
      11,    0,  101,    2, 0x0a,   10 /* Public */,
      12,    0,  102,    2, 0x0a,   11 /* Public */,
      13,    0,  103,    2, 0x0a,   12 /* Public */,
      14,    0,  104,    2, 0x0a,   13 /* Public */,

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

       0        // eod
};

Q_CONSTINIT const QMetaObject UserWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserWidget, std::true_type>,
        // method 'seeTutorialGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'seeWatchListGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goBackGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterByPresenterGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setPresenterGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addToWatchListGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeWatchListGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openFileGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setUpOpenButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setUpBackButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goToNextTutorialGUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setUpWatchListButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'seeTutorialButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UserWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->seeTutorialGUI(); break;
        case 1: _t->seeWatchListGUI(); break;
        case 2: _t->goBackGUI(); break;
        case 3: _t->filterByPresenterGUI(); break;
        case 4: _t->setPresenterGUI(); break;
        case 5: _t->addToWatchListGUI(); break;
        case 6: _t->removeWatchListGUI(); break;
        case 7: _t->openFileGUI(); break;
        case 8: _t->setUpOpenButton(); break;
        case 9: _t->setUpBackButton(); break;
        case 10: _t->goToNextTutorialGUI(); break;
        case 11: _t->setUpWatchListButton(); break;
        case 12: _t->seeTutorialButton(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *UserWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
