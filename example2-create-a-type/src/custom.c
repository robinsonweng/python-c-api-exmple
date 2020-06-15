#define PY_SSIZE_T_CLEAN
#include <Python.h>


typedef struct {
    PyObject_HEAD
    /* the field that defines type */
} ExampleObject;


static PyTypeObject ExampleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "custom.Example", // defines the python type name
    .tp_doc = "the example of python types", // the __doc__ in type

    /* in multiple inheritance tasks, we should check parent classed via __base__ to ensure size problem */
    .tp_basicsize = sizeof(ExampleObject), 
    .tp_flags = Py_TPFLAGS_DEFAULT, // setting tpflags to default
    .tp_new = PyType_GenericNew, // equivalent to __new__, but need to  specified explicitly(must required)
};

static PyModuleDef custommodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "custom",
    .m_doc = "example moudle that creates an extension type",
    .m_size = -1,
};

// initalize python module "custom"
PyMODINIT_FUNC
PyInit_custom(void){
    PyObject *m;
    if (PyType_Ready(&ExampleType) < 0) return NULL;

    m = PyModule_Create(&custommodule);
    if (m == NULL) return NULL;

    // release memory
    Py_INCREF(&ExampleType);
    if (PyModule_AddObject(m, "Example", (PyObject *) &ExampleType) < 0){
        // release module & type memory
        Py_DECREF(&ExampleType);
        Py_DECREF(m);
        return NULL;
    }
    return m;
}