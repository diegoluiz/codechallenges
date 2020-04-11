import sys

sys.setrecursionlimit(10000)

with open('d5/input.txt') as f:
  input = f.read()
  # print('input', input)

def process_rec(text, c = 0):
  # print('process ' + str(c), text)

  found = False
  for i in range(0, len(text)):
    if i >= len(text) - 1:
      break
    
    if text[i].upper() == text[i + 1].upper() and text[i] != text[i + 1]:
      found = True
      new_text =  text[:i] + text[i+2:]
      text = new_text
  
  if found:
    return process_rec(text, c + 1)
  
  return text


# new_text = process_rec(input)
# print(len(new_text))

letters = set()
for letter in input:
  letters.add(letter.lower())

print(str(letters))

letters_length = {}
for letter in letters:
  new_input = input.replace(letter.lower(), '').replace(letter.upper(), '')
  length = len(process_rec(new_input))
  letters_length[letter] = length
  print(letter, length)

print(str(letters_length)) # b -> 6918
