# Enter your code here. Read input from STDIN. Print output to STDOUT
import re

N = int(input())
for _ in range(N):
    num = str(input())
    print(bool(re.match(r"^[-+]?[0-9]*\.[0-9]+$", num)))
