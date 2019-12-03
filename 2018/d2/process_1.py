from itertools import groupby

with open('input.txt') as f:
    input = f.read().splitlines()

boxes_codes = [sorted(list(x)) for x in input]
count_2 = 0
count_3 = 0

for box_code in boxes_codes:
  counts = [len(list(group)) for key, group in groupby(box_code)]
  if 2 in counts:
    count_2 += 1
  if 3 in counts:
    count_3 += 1

  # for key, group in groupby(box_code):
  #   l = len(list(group))
  #   if l == 2:
  #     count_2.add(key)
  #   if l == 3:
  #     count_3.add(key)
    
print(count_2)
print(count_3)

print(count_2 * count_3) # 5727