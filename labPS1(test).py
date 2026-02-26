import math
from fractions import Fraction

def C(n, k):
    return math.comb(n, k)

def P(n, k):
    return math.factorial(n) // math.factorial(n - k)

# Задания

def task_1():
    n = 120000
    return n * (n - 1)

def task_2():
    return P(5, 2)

def task_3():
    return math.factorial(8)

def task_4():
    return math.factorial(7)

def task_5():
    return C(8, 3)

def task_6():
    return C(16, 6)

def task_7():
    return Fraction(C(6, 2), C(14, 2))

def task_8():
    return Fraction(C(8, 2), C(14, 2))

def task_9():
    return Fraction(C(4, 3), C(9, 3))

def task_10():
    total = C(9, 3)
    only_white = C(4, 3)
    only_red = C(5, 3)
    return Fraction(total - only_white - only_red, total)

def task_11():
    total = 7 ** 3
    good = P(7, 3)
    return Fraction(good, total)

def task_12():
    total = 7 ** 3
    good = C(3, 2)
    return Fraction(good, total)

def task_13():
    total = 10 ** 4
    good = P(10, 4)
    return Fraction(good, total)

def task_14():
    total = 10 ** 4
    good = C(4, 2) * 9 ** 2
    return Fraction(good, total)

def task_15():
    total = 9 ** 5
    good = P(9, 5)
    return Fraction(good, total)

def task_16():
    total = 9 ** 5
    good = C(5, 2) * 8 ** 3
    return Fraction(good, total)

def task_17():
    return Fraction(2 * math.factorial(5), math.factorial(6))

def task_18():
    return Fraction(math.factorial(5), math.factorial(6))

def task_19():
    return Fraction(math.factorial(4), math.factorial(7))

def task_20():
    return 18 * 17

# Вывод

tasks = [
    task_1(), task_2(), task_3(), task_4(), task_5(),
    task_6(), task_7(), task_8(), task_9(), task_10(),
    task_11(), task_12(), task_13(), task_14(), task_15(),
    task_16(), task_17(), task_18(), task_19(), task_20()
]

for i, result in enumerate(tasks, start=1):
    print(f"Задание {i}: {result}")
