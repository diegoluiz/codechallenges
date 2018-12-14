
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

    for x in range(init_x, init_x + size_x - 1):
        for y in range(init_y, init_y + size_y - 1):
            grid[x][y] += 1

tainted_count = 0
tainted_list = set()

def check(obj, grid):
    init_x = obj['pos']['x']
    init_y = obj['pos']['y']
    size_x = obj['size']['x']
    size_y = obj['size']['y']

    for x in range(init_x, init_x + size_x - 1):
        for y in range(init_y, init_y + size_y - 1):
            if grid[x][y] > 1:
                return True
    
    return False


for obj in a:
    o = check(obj, grid)
    if o == True:
        tainted_count += 1
        # tainted_list.add(obj)

for i in grid:
    print (i)
# print(tainted_count)
# print(tainted_list)

