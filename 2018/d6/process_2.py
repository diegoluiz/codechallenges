ids = []
for i in range(ord('a'), ord('z')+1): ids.append(chr(i))
for i in range(ord('A'), ord('Z')+1): ids.append(chr(i))
print('ids', ids)

def print_grid(grid):
  for i in grid:
    for j in i:
      print(j,end='')
    print(' ')

def new_grid(top_x, top_y):
  grid = []
  for _ in range(0, (top_y + 1)):
    grid.append(['.'] * (top_x + 1))
  return grid

file = 'd6/input.txt'
with open(file) as f:
  c = 0
  input = []
  for s in f.read().splitlines():
    input.append({'id': ids[c], 'x': int(s.split(', ')[0]), 'y': int(s.split(', ')[1])})
    c += 1

top_x = sorted(input, key=lambda x:x['x'], reverse=True)[0]['x'] + 1
top_y = sorted(input, key=lambda x:x['y'], reverse=True)[0]['y'] + 1
print('Tops:', top_x, top_y)

import math

threshold = 10000

grid = new_grid(top_x, top_y)
for item in input: grid[item['y']][item['x']] = item['id']
mid_y = len(grid) / 2

items = sorted(input, key=lambda x:x['y'])
items_reverse = sorted(input, key=lambda x:x['y'], reverse=True)

for y in range(0, (top_y + 1)):
  for x in range(0, (top_x + 1)):

    total_distance = 0
    l = items if y < mid_y else items_reverse
    for item in l:
      total_distance += abs(item['x'] - x) + abs(item['y'] - y)
      if (total_distance >= threshold):
        break

    if (total_distance < threshold):
        grid[y][x] = '#'

count = 0
for y in range(0, (top_y + 1)):
  for x in range(0, (top_x + 1)):
    if grid[y][x] == '#': count += 1

# print_grid(grid)
print(count)