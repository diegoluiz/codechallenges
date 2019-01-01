file = 'd12/input.test.txt'
# file = 'd12/input.txt'


def parse_rule(i):
  x = i.split(' => ')
  i = x[0]
  o = x[0][0:2] + x[1] + x[0][3:5]
  o = '..' + x[1] + '..'
  return {'input': i, 'output': o, 'r': x[1]}

def change_state(state, zero_pos):
  for i in range(5):
    if state[i] == '#':
      state = '.' + state
      zero_pos += 1

    if state[0 - i - 1] == '#':
      state = state + '.'

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
for tick in range(0, 1):
  state, zero_pos = change_state(state, zero_pos)
  temp_state = state

  # for i in range(0 - zero_pos, len(state)- zero_pos):
  #   print(str(i)[-1], end='')
  # print()
  for i in range(0, len(state)):
    print(str(i)[-1], end='')
  print()
  print(state, tick, zero_pos)
  
  for rule in rules:
    idx = state.find(rule['input'])
    last_idx = 0

    state = state.replace(rule['input'], rule['output'])
    # if idx == -1:
    #   state = state[0: idx + 3] + '.' + state[idx + 4:]
    #   continue

    # while idx != -1:
    #   print(state, rule['input'], idx, state[idx: idx+5])
    #   state = state[0: idx + 3] + rule['r'] + state[idx + 4:]
    #   idx = state.find(rule['input'], last_idx + len(rule['input']))
    #   # print(idx + 1, rule['input'], temp_state)
    #   # temp_state = temp_state[0: idx] + rule['output'] + temp_state[idx + 5:]
    #   # idx = temp_state.find(rule['input'], last_idx + len(rule['input']))
    #   last_idx = idx

  #     # temp_state
  #   # break
  # # print(temp_state, zero_pos)
  # # state = temp_state
  print(state, 'final')


