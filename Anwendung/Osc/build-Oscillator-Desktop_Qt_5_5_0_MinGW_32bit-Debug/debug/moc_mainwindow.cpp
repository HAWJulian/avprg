/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Oscillator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[382];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "on_frequencySlider_valueChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 5), // "value"
QT_MOC_LITERAL(4, 50, 29), // "on_waveformCombobox_activated"
QT_MOC_LITERAL(5, 80, 5), // "index"
QT_MOC_LITERAL(6, 86, 26), // "on_gainSlider_valueChanged"
QT_MOC_LITERAL(7, 113, 26), // "on_dialAttack_valueChanged"
QT_MOC_LITERAL(8, 140, 25), // "on_dialDecay_valueChanged"
QT_MOC_LITERAL(9, 166, 27), // "on_dialSustain_valueChanged"
QT_MOC_LITERAL(10, 194, 27), // "on_dialRelease_valueChanged"
QT_MOC_LITERAL(11, 222, 30), // "on_comboMidiInputBox_activated"
QT_MOC_LITERAL(12, 253, 6), // "string"
QT_MOC_LITERAL(13, 260, 16), // "onControllerMidi"
QT_MOC_LITERAL(14, 277, 7), // "channel"
QT_MOC_LITERAL(15, 285, 5), // "data1"
QT_MOC_LITERAL(16, 291, 5), // "data2"
QT_MOC_LITERAL(17, 297, 26), // "on_rateSlider_valueChanged"
QT_MOC_LITERAL(18, 324, 12), // "mouseRelease"
QT_MOC_LITERAL(19, 337, 12), // "QMouseEvent*"
QT_MOC_LITERAL(20, 350, 5), // "event"
QT_MOC_LITERAL(21, 356, 25) // "on_posSlider_valueChanged"

    },
    "MainWindow\0on_frequencySlider_valueChanged\0"
    "\0value\0on_waveformCombobox_activated\0"
    "index\0on_gainSlider_valueChanged\0"
    "on_dialAttack_valueChanged\0"
    "on_dialDecay_valueChanged\0"
    "on_dialSustain_valueChanged\0"
    "on_dialRelease_valueChanged\0"
    "on_comboMidiInputBox_activated\0string\0"
    "onControllerMidi\0channel\0data1\0data2\0"
    "on_rateSlider_valueChanged\0mouseRelease\0"
    "QMouseEvent*\0event\0on_posSlider_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       6,    1,   80,    2, 0x08 /* Private */,
       7,    1,   83,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
       9,    1,   89,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x08 /* Private */,
      11,    1,   95,    2, 0x08 /* Private */,
      13,    3,   98,    2, 0x08 /* Private */,
      17,    1,  105,    2, 0x08 /* Private */,
      18,    1,  108,    2, 0x08 /* Private */,
      21,    1,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_frequencySlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_waveformCombobox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_gainSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_dialAttack_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_dialDecay_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_dialSustain_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_dialRelease_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_comboMidiInputBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onControllerMidi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->on_rateSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 11: _t->on_posSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
