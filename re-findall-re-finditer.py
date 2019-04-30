# Enter your code here. Read input from STDIN. Print output to STDOUT

import re
vowel = "aeiouAEIOU"
arr = re.findall(r"(?<=[^%s])([%s]{2,})(?=[^%s])"%(vowel, vowel, vowel), input())
print('\n'.join(arr or ['-1']))
