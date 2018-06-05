/****************************************************************************
** Meta object code from reading C++ file 'diploma.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../diploma.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diploma.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Diploma[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      20,    8,    8,    8, 0x08,
      31,    8,    8,    8, 0x08,
      42,    8,    8,    8, 0x08,
      54,    8,    8,    8, 0x08,
      63,    8,    8,    8, 0x08,
      75,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Diploma[] = {
    "Diploma\0\0readData()\0readFile()\0"
    "SaveFile()\0algorithm()\0addRow()\0"
    "deleteRow()\0describe()\0"
};

void Diploma::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Diploma *_t = static_cast<Diploma *>(_o);
        switch (_id) {
        case 0: _t->readData(); break;
        case 1: _t->readFile(); break;
        case 2: _t->SaveFile(); break;
        case 3: _t->algorithm(); break;
        case 4: _t->addRow(); break;
        case 5: _t->deleteRow(); break;
        case 6: _t->describe(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Diploma::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Diploma::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Diploma,
      qt_meta_data_Diploma, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Diploma::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Diploma::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Diploma::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Diploma))
        return static_cast<void*>(const_cast< Diploma*>(this));
    return QDialog::qt_metacast(_clname);
}

int Diploma::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
