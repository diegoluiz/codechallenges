# input = 39
# input = 71
input = 8444

debug = False
grid = []
for y in range(0, 300):
  row = []
  grid.append(row)
  for x in range(0, 300):
    g_y = y + 1
    g_x = x + 1
    # if g_y == 196 and g_x == 217:
    #   debug = True
    rack_id = g_x + 10
    power_level = rack_id * g_y
    power_level += input
    power_level *= rack_id
    
    power_level_str = str(power_level).rjust(3,'0')
    power_level_str = "".join(reversed(power_level_str))

    level = int(power_level_str[2]) - 5
    # print(level, end=' ')
    row.append(level)
  # print('')
  # print(row)

# print(grid[152][100])
# print(grid[216][196])

# for y in grid:
#   for x in y:
#     print(x, end='')
#   print('')

max_total = 0
max_y = 0
max_x = 0
for y in range(0, 298):
  for x in range(0, 298):
    total = grid[y][x] + grid[y][x + 1] + grid[y][x + 2] \
          + grid[y + 1][x] + + grid[y + 1][x + 1] + grid[y+1][x + 2] \
          + grid[y + 2][x] + + grid[y + 2][x + 1] + grid[y + 2][x + 2]
    if total >= max_total:
      max_total = total
      max_x = x
      max_y = y

print(max_total, max_x + 1, max_y + 1)
