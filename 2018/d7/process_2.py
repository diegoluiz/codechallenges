file = 'd7/input.test.txt'
file = 'd7/input.txt'

parallelism = 5
overhead = 60

class Worker:
  def __init__(self, id):
    self.id = id
    self.current = None
    self.last = None
    self.freeTick = 0

with open(file) as f:
  input = f.read().splitlines()

step_times = {}
steps = []
for item in input:
  a = item.replace('Step ','').replace(' can begin.','').split(' must be finished before step ')
  steps.append({ 'from': a[0], 'to': a[1] })

workers = [Worker(i) for i in range(0, parallelism)]
froms = list(filter(lambda x: x not in map(lambda x: x['to'], steps), set(map(lambda x: x['from'], steps))))

to_process = set(froms)
chain = ''
tick = 0

def get_task_time(task):
  return ord(task) - 64 + overhead

def get_next(chain, to_process):
  for c in sorted(to_process):
    deps = list(filter(lambda x: x['to'] == c, steps))
    len_unprocessed_deps = len(list(filter(lambda x: x['from'] not in chain, deps)))
    if len_unprocessed_deps == 0: return c
  return None

def anyWorking(workers):
  for worker in workers:
    if worker.current is not None: return True
  return False

while len(to_process) > 0 or anyWorking(workers):
  print('Tick', tick,'# Items to process', len(to_process), anyWorking(workers))

  for worker in workers:
    if worker.freeTick <= tick and worker.current is not None:
      chain += worker.current
      worker.last = worker.current
      worker.current = None
      print('Finished task', worker.last)
      for i in filter(lambda x: x['from'] == worker.last, steps):
        to_process.add(i['to'])

  for worker in workers:
    if worker.current is None:
      n = get_next(chain, to_process)
      if n is None: continue
      worker.current = n
      worker.freeTick = tick + get_task_time(n)
      print('Start task', worker.current, 'until tick', worker.freeTick)
      to_process.remove(n)

  print('Tick', tick,'# Items to process', len(to_process), anyWorking(workers))
  tick += 1

print(chain, tick - 1)
