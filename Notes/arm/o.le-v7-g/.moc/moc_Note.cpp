/****************************************************************************
** Meta object code from reading C++ file 'Note.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Note.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Note.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_bb__cascades__Note[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      30,   20,   19,   19, 0x02,
      56,   19,   51,   19, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_bb__cascades__Note[] = {
    "bb::cascades::Note\0\0itemTitle\0"
    "addNoteItem(QString)\0bool\0saveData()\0"
};

void bb::cascades::Note::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Note *_t = static_cast<Note *>(_o);
        switch (_id) {
        case 0: _t->addNoteItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: { bool _r = _t->saveData();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData bb::cascades::Note::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject bb::cascades::Note::staticMetaObject = {
    { &bb::cascades::Application::staticMetaObject, qt_meta_stringdata_bb__cascades__Note,
      qt_meta_data_bb__cascades__Note, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &bb::cascades::Note::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *bb::cascades::Note::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *bb::cascades::Note::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_bb__cascades__Note))
        return static_cast<void*>(const_cast< Note*>(this));
    typedef bb::cascades::Application QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int bb::cascades::Note::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef bb::cascades::Application QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
