#define PY_SSIZE_T_CLEAN
#include "Python.h"


// define method globalvar behave
static PyObject *spam_globalvar(PyObject *self, PyObject *args){

    PyObject *d = PyEval_GetGlobals();
    return d;
}

// define method cuteg41 behave
static PyObject *spam_cuteg41(PyObject *self, PyObject *args){
    return PyUnicode_FromString("cute g41");
}

// initalize globalvar method attribute
static PyMethodDef SpamMethods[]={
    {"globalvar", // name of the method
    spam_globalvar, // method bahave pointer
    METH_VARARGS, // flag bits indicating how the call should be constructed
    "Execute all globalvar"}, // method __doc__

    {"cuteg41",spam_cuteg41,METH_VARARGS,"return a cute g41 string"},
    {NULL,NULL,0,NULL} // the fuck is Sentinel??
    /* Sentinel means a dummy value for value that should exist */
};

// initalize globalvar to spam module
static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT, // always initalize this member to PyModuleDef_HEAD_INIT
    "spam", // the name of module
    "a module that provide globavar", // the module __doc__
    -1, // -1 means that module does not support sub-interpreters
    SpamMethods // the module methods
};

// initalize spam module
static PyObject *SpamError;
PyMODINIT_FUNC PyInit_spam(void){
    PyObject *m;
    m = PyModule_Create(&spammodule);
    // return null to api if error occurred
    if (m==NULL) return NULL;

    // handling error
    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_XINCREF(SpamError);
    if (PyModule_AddObject(m, "error", SpamError) < 0){
        Py_XDECREF(SpamError);
        Py_CLEAR(SpamError);
        Py_DecRef(m);
        return NULL;
    }

    return m;
}