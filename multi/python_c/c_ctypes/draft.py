import ctypes


class PyTestStruct(ctypes.Structure):
    _fields_ = [
        ("integer", ctypes.c_int),
        ("c_str", ctypes.c_char_p),
        ("ptr", ctypes.c_void_p),
        ("array", (ctypes.c_int * 2) * 8),
    ]


class TestClib:
    def __init__(self):
        self.clib = ctypes.cdll.LoadLibrary("./libhello.so")

    def hello(self, test_struct):
        func = self.clib.hello
        func.restype = ctypes.POINTER(PyTestStruct)
        func.argtypes = [ctypes.POINTER(PyTestStruct)]

        return func(ctypes.byref(test_struct))


test_struct = PyTestStruct()
test_struct.integer = 1
test_struct.c_str = "Hello, C".encode()
test_struct.ptr = 0xFFFFFFFF
test_struct.array[2][1] = 624

testClib = TestClib()
ret = testClib.hello(test_struct)
print(ret.contents.integer)
