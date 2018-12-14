from itertools import groupby

with open('input.txt') as f:
    input = f.read().splitlines()

boxes_codes = input
count_2 = 0
count_3 = 0

for box_code1 in boxes_codes:
  for box_code2 in boxes_codes:
    if box_code1 == box_code2:
      break

    err = 0
    for c in range(len(box_code1)):
      if box_code1[c] != box_code2[c]:
        err += 1
    if err <= 1:
      print('Box1: ' + box_code1) # uwzfmdjxyxlbgnrotcfpvswaqh
      print('Box2: ' + box_code2) # uwkfmdjxyxlbgnrotcfpvswaqh

# uwfmdjxyxlbgnrotcfpvswaqh