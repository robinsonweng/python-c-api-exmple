where cl >nul 2>nul || "%VS160COMNTOOLS%..\..\VC\vcvarsall.bat" amd64
set INCLUDE=C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0\ucrt;C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0\shared
set LIB=C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\um\x64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\ucrt\x64
python setup.py build_ext --inplace


# dll
# gcc -shared -Wall -o adder.dll -fPIC add.c -IC "C:\Users\user\AppData\Local\Programs\Python\Python36\include" -LC "C:\Users\user\AppData\Local\Programs\Python\Python36\libs"
