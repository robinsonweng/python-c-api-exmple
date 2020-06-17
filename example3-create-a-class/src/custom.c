#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "structmember.h"


typedef struct {
    PyObject_HEAD 
    PyObject *first;
    PyObject *last;
    int number;
} ExampleObject;

static void
Example_dealloc(ExampleObject *self) {
    Py_XDECREF(self->first);
    Py_XDECREF(self->last);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
Example_new(PyTypeObject *type, PyObject *args, PyObject *kwds){
    ExampleObject *self;
    self = (ExampleObject *) type->tp_alloc(type, 0);

    if (self != NULL){
        self->first = PyUnicode_FromString(""); // this will set Python none
        if (self->first == NULL){
            Py_DECREF(self);
            return NULL;
        }

        self->last = PyUnicode_FromString("");
        if (self->last == NULL){
            Py_DECREF(self);
            return NULL;
        }
        self->number = 0;
    }
    return (PyObject *) self;
}

static int
Example_init(ExampleObject *self, PyObject *args, PyObject *kwds){
    static char *kwlist[] = {"first", "last", "number", NULL};
    PyObject *first = NULL, *last = NULL, *tmp;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
                                     "|OOi", kwlist,
                                     &first, &last,
                                     &self->number))
        return -1;
    
    if (first){
        tmp = self->first;
        Py_INCREF(first);
        self->first = first;
        Py_XDECREF(tmp);
    }
    if (last){
        tmp = self->last;
        Py_INCREF(last);
        self->last = last;
        PY_XDECREF(tmp);
    }
    return 0;
}

static PyMemberDef Example_members[] = {
    {"first", T_OBJECT_EX, offsetof(ExampleObject, first), 0, "first name"},
    {"last", T_OBJECT_EX, offsetof(ExampleObject, last), 0, "last name"},
    {"number", T_INT, offsetof(ExampleObject, number), 0, "custom number"},
    {NULL} /* Sentinel */
};

static PyObject * 
Example_name(ExampleObject *self, PyObject *Py_UNUSED(ignored1)){
    if (self->first == NULL){
        PyErr_SetString(PyExc_AttributeError, "first");
        return NULL;
    }
    
}