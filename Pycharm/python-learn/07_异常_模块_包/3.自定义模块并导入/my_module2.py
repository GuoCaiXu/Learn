def test(a, b):
    print(a - b)

# __all__ 变量
__all__ = ['test_A']

def test_A(a, b):
    print(a + b)

def test_B(a, b):
    print(a - b)
