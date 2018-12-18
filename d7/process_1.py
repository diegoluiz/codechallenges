file = 'd7/input.txt'
with open(file) as f:
  input = f.read().splitlines()

steps = []
for item in input:
  a = item.replace('Step ','').replace(' can begin.','').split(' must be finished before step ')
  steps.append({ 'from': a[0], 'to': a[1] })

to_process = set(list(filter(lambda x: x not in map(lambda x: x['to'], steps), set(map(lambda x: x['from'], steps)))))
chain = ''

def get_next(chain, to_process):
  for c in sorted(to_process):
    deps = list(filter(lambda x: x['to'] == c, steps))
    len_unprocessed_deps = len(list(filter(lambda x: x['from'] not in chain, deps)))
    if len_unprocessed_deps == 0: return c

while len(to_process) > 0:
  n = get_next(chain, to_process)
  to_process.remove(n)

  for i in filter(lambda x: x['from'] == n, steps):
    to_process.add(i['to'])

  chain += n

print(chain)