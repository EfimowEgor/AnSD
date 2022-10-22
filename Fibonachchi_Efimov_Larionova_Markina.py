import sys
import time

def qwe():
    try:
        n = int(input())
        if n < 1:
            raise ValueError
        else:
            return n
    except ValueError:
        print('text')
        sys.exit()


def fib(n):
    if n == 1:
        return 0
    elif n == 0:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


def fib_iter(n):
    '''
    Рассматривается последовательность вида 0 1 1 2 3 ...
    '''
    cur = 1
    prev = 0
    for i in range(n - 1):
        fib_sum = cur + prev
        prev = cur
        cur = fib_sum
    return prev


def fib_23(n):
    a = [0 , 1]
    for i in range(n - 2):
        tmp_sum = a[i] + a[i + 1]
        a.append(tmp_sum)
    return a[-1]

n = qwe()

tic = time.perf_counter_ns()
print(fib(n))
toc = time.perf_counter_ns()
print(f'{toc - tic:0.4f}')

tic_1 = time.perf_counter_ns()
print(fib_iter(n))
toc_1 = time.perf_counter_ns()
print(f'{toc_1 - tic_1:0.4f}')

tic_2 = time.perf_counter_ns()
print(fib_23(n))
toc_2 = time.perf_counter_ns()
print(f'{toc_2 - tic_2:0.4f}')
