with open('input.txt') as f:
    input = [int(s) for s in f.read().splitlines()]

c = 0
freq_history = []
freq = 0

while True:
  c = c + 1
  for number in input:
    freq = freq + number
    if freq in freq_history:
      print('Freq: ' + str(freq)) # 76787
      quit()

    freq_history.append(freq)
    # print(freq)
  print('Processed whole list ' + str(c) + ' time. Number of items in freq_history: ' + str(len(freq_history)) + '. Freq:' + str(freq))
  # print(freq_history)

