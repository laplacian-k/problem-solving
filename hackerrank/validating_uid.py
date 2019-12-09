# https://www.hackerrank.com/challenges/validating-uid/problem
import re

T = int(input())

for _ in range(T):
    uid_ = input()
    uid = "".join(sorted(uid_))
    c1 = bool(re.search(r"[A-Z]{2,}", uid))
    c2 = bool(re.search(r"[\d]{3,}", uid))
    c3 = bool(re.match(r"[a-zA-Z0-9]{10}", uid))
    c4 = bool(re.search(r"(.)\1", uid))
    if c1 and c2 and c3 and not c4:
        print("Valid")
    else:
        print("Invalid")
