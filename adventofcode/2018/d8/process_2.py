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

  children = []
  if children_count != 0:
    for i in range(0, children_count):
      x,y = process(idx)
      idx = x
      children.append(y)

  if (features_count > 0):
    print(temp_idx,'   - c',children)
    for i in (range(0, features_count)):
      print(temp_idx,'   - f', input[idx])
      if children_count == 0:
        total += input[idx]
      else:
        total += children[input[idx] - 1] if (input[idx] - 1) < len(children) else 0
      idx += 1
    print (temp_idx, ' - total', total)

  return idx, total
  
idx, total = process(idx)

print(idx, total)

