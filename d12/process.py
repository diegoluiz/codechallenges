file = 'd12/input.test.txt'
file = 'd12/input.txt'


def parse_rule(i):
  x = i.split(' => ')
  i = x[0]
  o = x[0][0:2] + x[1] + x[0][3:5]
  o = '..' + x[1] + '..'
  return {'input': i, 'output': o, 'r': x[1]}

def change_state(state, zero_pos):
  # for i in range(5):
  #   if state[i] == '#':
  #     state = '.' + state
  #     zero_pos += 1

  print(state[0:5])

  if state[0:5] != '.....':
    state = '.....' + state
    zero_pos += 5

  if state[-5:] != '.....':
    print('bla')
    state = state + '.....'

  return state, zero_pos

with open(file) as f:
  input = f.read().splitlines()

zero_pos = 0
initial_state = input[0].replace('initial state: ', '')
rules = [parse_rule(i) for i in input[2:]]
rules_set = {}
for rule in rules: rules_set[rule['input']] = rule['r']

# state, zero_pos = change_state(initial_state, zero_pos)
print('init',initial_state)
for i in rules: print(i)

state = initial_state
for tick in range(0, 20):
  state, zero_pos = change_state(state, zero_pos)
  temp_state = state
  for pos in range(0, len(state)):
    current_pos = state[pos: pos + 5]
    # print(temp_state, pos, current_pos)
    # print('b', state[0: pos + 3])
    # print('a', state[pos + 4:])
    # print('current_pos', current_pos)
    current_rule = rules_set.get(current_pos)
    if current_rule is not None:
      # print('handle there is')
      temp_state = temp_state[0: pos + 2] + current_rule + temp_state[pos + 3:]
    else:
      # print('handle not found (just for the tests)')
      # print('b', state[0: pos + 2])
      # print('a', state[pos + 3:])
      temp_state = temp_state[0: pos + 2] + '.' + temp_state[pos + 3:]

    # print(state, pos)
  state = temp_state
  print(tick + 1,':', state, zero_pos)

print()
print('final', state)

total = 0

for p in range(0, len(state)):
  if state[p] == '#':
    total += (p - zero_pos)

print ('total', total)