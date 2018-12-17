file = 'd7/input.test.txt'
file = 'd7/input.txt'
with open(file) as f:
  input = f.read().splitlines()

steps = []
for item in input:
  a = item.replace('Step ','').replace(' can begin.','').split(' must be finished before step ')
  steps.append({ 'from': a[0], 'to': a[1] })

# for i in steps: print(i)

froms = list(filter(lambda x: x not in map(lambda x: x['to'], steps), set(map(lambda x: x['from'], steps))))

to_process = set(froms)
chain = ''
# to_process.add(unique_from)
c = 0  

def get_next(chain, to_process):
  for c in sorted(to_process):
    deps = list(filter(lambda x: x['to'] == c, steps))
    len_unprocessed_deps = len(list(filter(lambda x: x['from'] not in chain, deps)))
    # print(' - deps', c, deps, len_unprocessed_deps)
    if len_unprocessed_deps == 0: return c
    
  # n = (sorted(to_process))[0]

while len(to_process) > 0:
  # n = (sorted(to_process))[0]
  n = get_next(chain, to_process)
  print('processing', n)
  to_process.remove(n)
  # print(to_process)

  for i in filter(lambda x: x['from'] == n, steps):
    # print(' - ', str(i))
    to_process.add(i['to'])

  chain += n
  print(to_process)
  print('-' * 30)

print(chain)