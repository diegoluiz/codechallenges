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

file = 'd6/input.test.txt'
with open(file) as f:
  c = 0
  input = []
  for s in f.read().splitlines():
    input.append({'id': ids[c], 'x': int(s.split(', ')[0]), 'y': int(s.split(', ')[1])})
    c += 1

top_x = sorted(input, key=lambda x:x['x'], reverse=True)[0]['x'] + 1
top_y = sorted(input, key=lambda x:x['y'], reverse=True)[0]['y'] + 1
print('Tops:', top_x, top_y)

def calculateDangerousGrid():
  grid = new_grid(top_x, top_y)
  for item in input: grid[item['y']][item['x']] = item['id']

  max_d = 150

  def isValid(i_x, i_y, x, y, d):
    if x < 0 or y < 0 or x > top_x or y > top_y:
      return False
    return abs(i_x - x) + abs(i_y - y) == d

  for d in range(1, max_d):
    print('Distance', d)
    temp_grid = new_grid(top_x, top_y)
    for i in input:
      for y in range(i['y'] - d, i['y'] + d + 1):
        for x in range(i['x'] - d, i['x'] + d + 1):
          if isValid(i['x'], i['y'], x, y, d):
            if temp_grid[y][x] != '.' and temp_grid[y][x] != i['id']:
              temp_grid[y][x] = '#'
            else:
              temp_grid[y][x] = i['id']
      # print(i['id'], end=',')
    # print('\n - Done calculation')
    
    # print_grid(temp_grid)
    for y in range(0, (top_y + 1)):
      for x in range(0, (top_x + 1)):
        if grid[y][x] == '.':
          if temp_grid[y][x] == '#':
            grid[y][x] = '#'  
          if temp_grid[y][x] != '.' and temp_grid[y][x] != '#':
            grid[y][x] = temp_grid[y][x]

    should_break = True
    for y in range(0, (top_y + 1)):
      for x in range(0, (top_x + 1)):
        if grid[y][x] == '.':
          should_break = False

    if should_break:
      break
    # print(' - Done replication')
    # print('----------------')
    # print_grid(grid)
    # print('--------------------------')

  # print_grid(grid)
  return grid

def calculateDangerousCounts(grid):
  # print('Getting edges')
  edges = set()
  for y in range(0, (top_y + 1)):
    edges.add(grid[y][0])
    edges.add(grid[y][top_x])

  for x in range(0, (top_x + 1)):
    edges.add(grid[0][x])
    edges.add(grid[top_y][x])
  # print(' - Done Getting edges')
  # print(edges)


  counts = {}
  for y in range(0, (top_y + 1)):
    for x in range(0, (top_x + 1)):
      letter = grid[y][x]
      if letter not in ids:
        continue
      if letter not in counts:
        counts[letter] = 0
      counts[letter] += 1

  for count in sorted(counts, key=counts.__getitem__, reverse=True):
    if count not in edges:
      print(count, counts[count])

# grid = calculateDangerousGrid()
# calculateDangerousCounts(grid)

grid = new_grid(top_x, top_y)
for item in input: grid[item['y']][item['x']] = item['id']
