
input = 8444
# input = 42

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
    row.append(level)

max_total = 0
max_y = 0
max_x = 0
max_s = 0
for y in range(0, 298):
  for x in range(0, 298):
    m = x if x < y else y
    for s in range(2, 300 - m):
      total = grid[y][x]
      for i in  range(0, s):
        total += grid[y][x + s] + grid[y + s][x] + grid[y + s][x + s]
      # total = grid[y][x] + grid[y][x + 1] + grid[y][x + 2] \
      #       + grid[y + 1][x] + + grid[y + 1][x + 1] + grid[y+1][x + 2] \
      #       + grid[y + 2][x] + + grid[y + 2][x + 1] + grid[y + 2][x + 2]
        if total >= max_total:
          max_total = total
          max_x = x
          max_y = y
          max_s = s

print(max_total, max_x + 1, max_y + 1)
