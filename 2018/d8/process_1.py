file = 'd8/input.test.txt'
file = 'd8/input.txt'
with open(file) as f:
  input = [int (x) for x in f.read().split(' ')]

print(input)

total_sum = 0
features = []
idx = 0

def process(idx):
  temp_idx = idx
  total = 0
  children_count = input[idx]
  idx += 1
  features_count = input[idx]

  print (temp_idx, ' - process', children_count, features_count)
  idx += 1

  if (children_count != 0):
    for i in range(0, children_count):
      x,y = process(idx)
      idx = x
      total += y

  if (features_count > 0):
    for i in (range(0, features_count)):
      total += input[idx]
      idx += 1
    print (temp_idx, ' - total', total)

  return idx, total
  
idx, total = process(idx)

print(idx, total)

