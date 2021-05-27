import random
import sys

if len(sys.argv) == 2:
    try:
        amount = int(sys.argv[1])
    except Exception:
        print("Did you insert a number? 🙄")
    new_list = random.sample(range(amount), amount)
    print(" ".join([str(elem) for elem in new_list]))
