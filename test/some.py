import random

a = [i for i in range(10)]
random.shuffle(a)
for i in a:
    print("i =", i)
