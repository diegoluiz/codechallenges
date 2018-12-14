from datetime import datetime

class Shift:
  def __init__(self, guard_id, start_time):
    self.guard_id = guard_id
    self.start_time = start_time
    self.actions = []
    
  def end_shift(self):
    self.end_time = None
  
  def add_action(self, action, time):
    self.actions.append({ 'action': action, 'time': time, 'minute': time.minute })
    
  def is_sleeping(self, minute):
    y = [x for x in self.actions if x['minute'] <= minute]
    if len(y) == 0:
      return False
    
    y = y[-1]
    if y['action'] == 'sleep':
      return True

    return False
    
  def calculate_sleep_time(self):
    time_sleeping = 0
    for minute in range(0, 60):
      x = self.is_sleeping(minute)
      if x == True:
        time_sleeping += 1
    return time_sleeping

with open('d4/input.txt') as f:
    input = sorted(f.read().splitlines())

shifts = []
shift = None

for record in input:
  time = datetime.strptime(record[1:17], "%Y-%m-%d %H:%M")
  guard_id = record[26:record.find(' ', 26)]
  if record.find('begins shift') > 0:
    if shift is not None:
      shift.end_shift()
    shift = Shift(guard_id, time)
    shifts.append(shift)

  if record.find('falls asleep') >= 0:
    shift.add_action('sleep', time)

  if record.find('wakes up') >= 0:
    shift.add_action('wake', time)

guards = {}
for shift in shifts:
  sleep_time = shift.calculate_sleep_time()
  if shift.guard_id not in guards:
    guards[shift.guard_id] = 0
  
  guards[shift.guard_id] += sleep_time

top_sleeper = sorted(guards, key=guards.__getitem__, reverse=True)[0]
# print (top_sleeper, guards[top_sleeper])

guard_shifts = []
for shift in shifts:
  if shift.guard_id == top_sleeper:
    guard_shifts.append(shift)

print('Top Sleeper #' + str(shift.guard_id) + '. Slept for ' + str(guards[shift.guard_id]) + ' minutes')
for x in range(0, 6):
  for y in range(0, 10):
    print(x,end='')

print('')
for x in range(0, 6):
  for y in range(0, 10):
    print(y,end='')

print('')

for shift in guard_shifts:
  for minute in range(0, 60):
    if shift.is_sleeping(minute) == True:
      print('#',end='')
    else:
      print('.', end='')
  print('')

minute_set = {}
for minute in range(0, 60):
  minute_set[minute] = 0
  for shift in guard_shifts:
    if shift.is_sleeping(minute):
      minute_set[minute] += 1

top_minute = sorted(minute_set, key=minute_set.__getitem__, reverse=True)[0]
print('Top minute slept ' + str(top_minute))
print(int(top_sleeper) * int(top_minute))

guards = {}
for shift in shifts:
  if shift.guard_id not in guards:
    guards[shift.guard_id] = []
  guards[shift.guard_id].append(shift)
  
guard_minute_set = {}
for i in guards:
  minute_set = {}
  guard_minute_set[i] = minute_set
  for minute in range(0, 60):
    minute_set[minute] = 0
    for shift in guards[i]:
      if shift.is_sleeping(minute):
        minute_set[minute] += 1

top_minute = 0
top_guard = 0
top = 0

for minute in range(0, 60):
  for guard in guard_minute_set:
    for sleep_minute in guard_minute_set[guard]:
      if guard_minute_set[guard][sleep_minute] > top:
        top = guard_minute_set[guard][sleep_minute]
        top_minute = sleep_minute
        top_guard = guard

print('Top value: ' + str(top) + ' at minute ' + str(top_minute) + ' for guard ' + str(top_guard))

print(' ' * 8, end='')
for x in range(0, 60):
    print(str(x).rjust(2),end='|')

print('')

for i in guard_minute_set:
  print(i.ljust(5), end='-> ')
  for j in guard_minute_set[i]:
    print(str(guard_minute_set[i][j]).ljust(2), end='|')
    
  print('')

print(int(top_minute) * int(top_guard))
