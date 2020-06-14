# example 1

So in order to create a python function in c, there is some tips you need to follow.Let's say you want create a module spam, and a method called `globalvar` and `cuteg41`

1. create a `PyObject` that defines your python function behave
2. define python method's attribute with `PyMethodDef`
3. initialze python method
4. create the modle(spam)
5. import spam module, you should able all the `globalvar` and `cuteg41` method