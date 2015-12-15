/****************************************************************************
** Meta object code from reading C++ file 'videoplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ColorKeyer/videoplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoPlayer_t {
    QByteArrayData data[18];
    char stringdata[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoPlayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoPlayer_t qt_meta_stringdata_VideoPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VideoPlayer"
QT_MOC_LITERAL(1, 12, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 30), // "on_openVideoFileButton_clicked"
QT_MOC_LITERAL(4, 66, 22), // "on_HueMin_valueChanged"
QT_MOC_LITERAL(5, 89, 5), // "value"
QT_MOC_LITERAL(6, 95, 22), // "on_HueMax_valueChanged"
QT_MOC_LITERAL(7, 118, 22), // "on_SatMin_valueChanged"
QT_MOC_LITERAL(8, 141, 22), // "on_SatMax_valueChanged"
QT_MOC_LITERAL(9, 164, 24), // "on_ValueMin_valueChanged"
QT_MOC_LITERAL(10, 189, 24), // "on_ValueMax_valueChanged"
QT_MOC_LITERAL(11, 214, 27), // "on_pixelslider_valueChanged"
QT_MOC_LITERAL(12, 242, 29), // "on_objectsslider_valueChanged"
QT_MOC_LITERAL(13, 272, 30), // "on_varianceslider_valueChanged"
QT_MOC_LITERAL(14, 303, 22), // "on_yaxisbutton_clicked"
QT_MOC_LITERAL(15, 326, 20), // "on_centerscb_clicked"
QT_MOC_LITERAL(16, 347, 25), // "on_exactcenterscb_clicked"
QT_MOC_LITERAL(17, 373, 18) // "on_linescb_clicked"

    },
    "VideoPlayer\0on_playButton_clicked\0\0"
    "on_openVideoFileButton_clicked\0"
    "on_HueMin_valueChanged\0value\0"
    "on_HueMax_valueChanged\0on_SatMin_valueChanged\0"
    "on_SatMax_valueChanged\0on_ValueMin_valueChanged\0"
    "on_ValueMax_valueChanged\0"
    "on_pixelslider_valueChanged\0"
    "on_objectsslider_valueChanged\0"
    "on_varianceslider_valueChanged\0"
    "on_yaxisbutton_clicked\0on_centerscb_clicked\0"
    "on_exactcenterscb_clicked\0on_linescb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       7,    1,   97,    2, 0x08 /* Private */,
       8,    1,  100,    2, 0x08 /* Private */,
       9,    1,  103,    2, 0x08 /* Private */,
      10,    1,  106,    2, 0x08 /* Private */,
      11,    1,  109,    2, 0x08 /* Private */,
      12,    1,  112,    2, 0x08 /* Private */,
      13,    1,  115,    2, 0x08 /* Private */,
      14,    0,  118,    2, 0x08 /* Private */,
      15,    0,  119,    2, 0x08 /* Private */,
      16,    0,  120,    2, 0x08 /* Private */,
      17,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VideoPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoPlayer *_t = static_cast<VideoPlayer *>(_o);
        switch (_id) {
        case 0: _t->on_playButton_clicked(); break;
        case 1: _t->on_openVideoFileButton_clicked(); break;
        case 2: _t->on_HueMin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_HueMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_SatMin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_SatMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_ValueMin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_ValueMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pixelslider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_objectsslider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_varianceslider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_yaxisbutton_clicked(); break;
        case 12: _t->on_centerscb_clicked(); break;
        case 13: _t->on_exactcenterscb_clicked(); break;
        case 14: _t->on_linescb_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject VideoPlayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VideoPlayer.data,
      qt_meta_data_VideoPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoPlayer.stringdata))
        return static_cast<void*>(const_cast< VideoPlayer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VideoPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
