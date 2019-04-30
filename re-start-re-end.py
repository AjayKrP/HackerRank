# Enter your code here. Read input from STDIN. Print output to STDOUT

import re
s = input()
k = input()
s_ = 0

if re.search(k, s):
    while s_ + len(k) < len(s):
        arr = re.search(k, s[s_:])
        print((s_ + arr.start(), s_ + arr.end() - 1))
        s_ += arr.start() + 1
else:
    print((-1, -1))
