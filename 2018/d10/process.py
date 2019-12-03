
class Star:
  def __init__(self, id, input):
    self.id = id
    self.i_x = int(input[0].split(', ')[0])
    self.i_y = int(input[0].split(', ')[1])
    self.v_x = int(input[1].split(', ')[0])
    self.v_y = int(input[1].split(', ')[1])

    self.x = self.i_x
    self.y = self.i_y
  
  def init_print(self):
    return "Id: " + str(self.id) + " POS:" + str(self.x) + ','+ str(self.y)+ " VEL:" + str(self.v_x) + ','+ str(self.v_y)

  def print(self):
    return "Id: " + str(self.id) + " POS:" + str(self.x) + ','+ str(self.y)

def get_input():
  file = 'd10/input.test.txt'
  file = 'd10/input.txt'
  with open(file) as f:
    input = []
    c = 0
    for i in f.read().splitlines():
      temp = i.replace('position', '') \
        .replace('=<', '') \
        .replace('>', '') \
        .split(' velocity')
      input.append(Star(c, temp))
      c += 1
  return input

def get_bounderies(stars):
  line_x = sorted([i.x for i in stars ])
  line_y = sorted([i.y for i in stars ])
  left = line_x[0]
  right = line_x[-1]
  bottom = line_y[0]
  top = line_y[-1]

  return top, left, bottom, right

def new_grid(stars, top, left, bottom, right):
  grid = []
  for i in range(bottom, top  + 1):
    grid.append(['.'] * (right - left + 1))

  return grid, (left * -1), (bottom * -1)

def validate(grid):
  for x in range(0, len(grid[0])):
    for y in range(0, len(grid) - 5):
      count = 0
      for i in range(0, 5):
        if grid[y+i][x] == '#': 
          count += 1
      if count >= 5: 
        return True
  return False

def print_grid(grid):
  for row in grid:
    for i in row: print(i, end='')
    print('')
  print('*' * 50)

stars = get_input()
for i in stars: print(i.init_print())

total_seconds = 100000
max_y = 1000
max_x = 1000
grid = None
for second in range(0, total_seconds):
  top, left, bottom, right = get_bounderies(stars)
  print('Another second', second, 'bounduaries', top,left,bottom,right)

  if abs(top - bottom) <= max_y and abs(left - right) <= max_x:
    grid, x_offset, y_offset = new_grid(stars, top, left, bottom, right)
    print(' - grid created', x_offset, y_offset)

  is_valid = False
  for star in stars:
    if (grid is not None): 
      grid[star.y + y_offset][star.x + x_offset] = '#'

    star.x += star.v_x
    star.y += star.v_y
  
  # print(' - Done all movements')

  if (grid is not None) and validate(grid):
    print_grid(grid)

  grid = None

# Another second 10932 bounduaries 145 106 136 167
#  - grid created -106 -136
# #....#..######..#....#...####...#####......###...####...######
# #...#........#..#....#..#....#..#....#......#...#....#.......#
# #..#.........#..#....#..#.......#....#......#...#............#
# #.#.........#...#....#..#.......#....#......#...#...........#.
# ##.........#....######..#.......#####.......#...#..........#..
# ##........#.....#....#..#..###..#..#........#...#..###....#...
# #.#......#......#....#..#....#..#...#.......#...#....#...#....
# #..#....#.......#....#..#....#..#...#...#...#...#....#..#.....
# #...#...#.......#....#..#...##..#....#..#...#...#...##..#.....
# #....#..######..#....#...###.#..#....#...###.....###.#..######

# KZHGRJGZ