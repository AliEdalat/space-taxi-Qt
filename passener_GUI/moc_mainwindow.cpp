/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     118,   11,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     191,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     258,   11,   11,   11, 0x08,
     283,   11,   11,   11, 0x08,
     308,   11,   11,   11, 0x08,
     333,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_register_button_clicked()\0"
    "on_Back_register_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_add_dest_clicked()\0on_remove_dest_clicked()\0"
    "on_request_trip_clicked()\0"
    "on_getcode_clicked()\0on_charge_clicked()\0"
    "on_Trip_status_clicked()\0"
    "on_rate_driver_clicked()\0"
    "on_cancel_trip_clicked()\0"
    "handle_estimate_command()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_register_button_clicked(); break;
        case 3: _t->on_Back_register_clicked(); break;
        case 4: _t->on_pushButton_6_clicked(); break;
        case 5: _t->on_add_dest_clicked(); break;
        case 6: _t->on_remove_dest_clicked(); break;
        case 7: _t->on_request_trip_clicked(); break;
        case 8: _t->on_getcode_clicked(); break;
        case 9: _t->on_charge_clicked(); break;
        case 10: _t->on_Trip_status_clicked(); break;
        case 11: _t->on_rate_driver_clicked(); break;
        case 12: _t->on_cancel_trip_clicked(); break;
        case 13: _t->handle_estimate_command(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE