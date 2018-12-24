file = 'd12/input.test.txt'
# file = 'd12/input.txt'


def parse_rule(i):
  x = i.split(' => ')
  return {'input': x[0], 'output': x[1]}

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

state, zero_pos = change_state(initial_state, zero_pos)


print('init',initial_state)
print('state',state, zero_pos)
for i in rules: print(i)
