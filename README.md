# Python-C-extension-via-python-api

Some practice and demo about python c extension via python api, also some general notes.

## There are four parts of creating Python function in c:

- Python header files
  - `Python.h`
    - Incording to Python document, this header preprocess alot of things (such as `stdlib.h`, `stdio.h`), so you shuould always include it first before any other staderd header file.
    - `#define PY_SSIZE_T_CLEAN`  
- Method functions
  - The file then definds the function to be called in Python, use two python object as input, then returns a python object back to interpreter as result, or return a NULL to trigger an exception(Note: return a NULL didn't handle an error).
  - Incording to `Python Programming` by Mark Lutz
    > you shuould use more specific type names, but don't always have to, because Python calls them by pointer, not name.
- Registration table
  - The `Python.h` file provides an initalized table (e.g `PyMethodDef`, `PyModuleDef`)that maps function attribute to function pointers(address)
- Initialzation funciton 
  - Finally, the `Python.h` provide a initialzation function, witch Python call the fist time when this module is imported into a python Program. When `Py_Init_module` is called, the function will bulid a dict table in the current module.Once so initialized, calls from Python are routed through registration table's function table.
