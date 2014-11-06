import re

data1 = []
data2 = []

re1 = re.compile(r"^[a-z ]+(?=\:)")
re2 = re.compile(r"(?<=\<)[a-z ]+(?=\>)")

for line in open("bnf-another-draft.md", "r").readlines():
    data1 += re1.findall(line)
    data2 += re2.findall(line)

print("=== defined ===")
print(set(data1))
print("=== used ===")
print(set(data2))
print("=== undefined ===")
print(set(data2) - set(data1))
