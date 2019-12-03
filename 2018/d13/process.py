file = 'd13/input.test.txt'
# file = 'd13/input.txt'

with open(file) as f:
  input = f.read().splitlines()
  input_map = [list(row) for row in input]

raw_map = input_map

for row in raw_map:
  print(row)
