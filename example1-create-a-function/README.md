# example 1

So in order to create a python function in c, there is some tips you need to follow.Let's say you want create a module spam, and a method called `globalvar` and `cuteg41`

1. create a `PyObject` that defines your python function behave
2. define python method's attribute with `PyMethodDef`
3. initialze python method
4. create the modle(spam)
5. import spam module, you should able all the `globalvar` and `cuteg41` method

## How does C handle Python arguments?
In order to handle the args betwoeen Python and c, you have to call `PyArg_ParseTuple()` or `PyArg_ParseTupleAndKeywords()` , if you want handle keyword args. The function were pass in command as string, but since Python don't have force type checking we need to format it as this section in [Python doc](https://docs.python.org/3/c-api/arg.html#strings-and-buffers).<br>
So the `"s"` in the [C extending example](https://docs.python.org/3/extending/extending.html#back-to-the-example) actually means pass the arg as `char*` type, if not, return `NULL` for raising an error.

```c
if (!PyArg_ParseTuple(args, "s", &command)) return NULL;
```


Note: the `PyArg_Parse()` are not avalible in Python3.