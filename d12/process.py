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

# state, zero_pos = change_state(initial_state, zero_pos)
print('init',initial_state)
for i in rules: print(i)

for i in range(0, 1):
  state, zero_pos = change_state(initial_state, zero_pos)
  temp_state = state

  print(state, zero_pos)
  for i in range(0 - zero_pos, len(state)):
    print(str(i)[-1], end='')
  print()
  
  # last_rule = -1
  for rule in rules:
    idx = temp_state.find(rule['input'])
    while idx != -1:
    # idx = state.find(rule['input'])
    # if (idx >= 0):
      last_rule = idx
      print(idx + 1, rule['input'], temp_state)
      temp_state = temp_state[0: idx] + rule['output'] + temp_state[idx + 5:]
      idx = temp_state.find(rule['input'])

      # temp_state
    # break
  print(temp_state, zero_pos)


