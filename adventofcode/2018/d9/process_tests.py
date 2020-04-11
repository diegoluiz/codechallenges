file = 'd9/input.test.txt'

class Marble:
  def __init__(self, id):
    self.id = id
    self.n = None
    self.p = None

def print_marbles(zero_marble):
  t = zero_marble
  while True:
    print(t.id, end=' ')
    t = t.n
    if zero_marble == t: break
  print('')

items = []
with open(file) as f:
  input = [x.split(': ') for x in f.read().splitlines()]
  for i in input:
    items.append({'input': i[0], 'output': i[1]})
  # items.append({'input': input[0][0], 'output': input[0][1]})

for item in items:
  # 470 players; last marble is worth 72170 points
  # print(item)
  x = item['input'].replace('points', '').split(' players; last marble is worth ')
  players_number = int(x[0])
  marbles_number = int(x[1])

  print('*' * 30)
  print(players_number, marbles_number)
  
  players = {}
  for i in range(0, players_number): players[i] = 0

  root_marble = Marble(0)
  root_marble.n = root_marble
  root_marble.p = root_marble

  zero_marble = root_marble

  for marble_idx in range(1, marbles_number + 1):
    # print ('id',root_marble.id)
    t = root_marble

    marble = Marble(marble_idx)
    
    if marble.id % 23 == 0:
      points = marble.id # add 23 to player
      for i in range(0,7): t = t.p
      points += t.id

      players[marble.id % players_number] += points

      root_marble = t.n
      t.p.n = t.n
      t.n.p = t.p
      # print_points(zero_marble)
      continue


    marble.n = root_marble.n.n
    marble.p = root_marble.n

    root_marble = marble
    t.n.n.p = marble
    t.n.n = marble

    # print_marbles(zero_marble)

  top_player = sorted(players, key=players.__getitem__, reverse=True)[0]
  print(top_player, players[top_player])
  print(item['output'])
