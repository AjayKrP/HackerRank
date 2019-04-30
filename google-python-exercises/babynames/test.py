import re

f = open('baby1990.html', 'r')
text = f.read()
result = list()
first = re.findall('(?<=Popularity in )(.*?)(?=</h3>)', text)
arr = re.findall(r'<td>(\d+)</td><td>(\w+)</td><td>(\w+)</td>', text)

result.append(first[0])
arr.sort(key=lambda x: x[1])

for i in arr:
    s = ""
    s += str(i[0]) + " " + i[1] + " " + i[2]
    result.append(s)

print(result)

