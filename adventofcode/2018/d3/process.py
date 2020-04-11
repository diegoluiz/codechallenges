
grid_size = 1000
a = []
with open('input.txt') as f:
    input = [x.replace(':', '').replace('#', '').split(' ') for x in  f.read().splitlines()]
    for line in input:
        obj = {}
        obj = {'id': int(line[0]), 
            'pos': {
                'x': int(line[2].split(',')[0]),
                'y': int(line[2].split(',')[1])
            },
            'size': {
                'x': int(line[3].split('x')[0]),
                'y': int(line[3].split('x')[1])
            }
        }
        a.append(obj)
        # print(obj)

grid = []
for i in range(0, grid_size): 
    grid.append([0] * grid_size)

for obj in a:
    init_x = obj['pos']['x']
    init_y = obj['pos']['y']
    size_x = obj['size']['x']
    size_y = obj['size']['y']

    for x in range(init_x, init_x + size_x):
        for y in range(init_y, init_y + size_y):
            grid[x][y] += 1

def check(obj, grid):
    init_x = obj['pos']['x']
    init_y = obj['pos']['y']
    size_x = obj['size']['x']
    size_y = obj['size']['y']

    for x in range(init_x, init_x + size_x):
        for y in range(init_y, init_y + size_y):
            if grid[x][y] > 1:
                return True
    
    return False

tainted_number = 0
for x in range(0, grid_size):
    for y in range(0, grid_size):
        if grid[x][y] > 1:
            tainted_number += 1
print(tainted_number)

for obj in a:
    o = check(obj, grid)
    if o == False:
        print(obj)

# for i in grid:
    # print (i)

