import sys

sys.setrecursionlimit(10000)

with open('d5/input.test.txt') as f:
  input = f.read()

# print(input)


def process_rec2(text):
  # print('process', text)

  found = False
  for i in range(0, len(text)):
    if i >= len(text) - 1:
      break
    
    # print(text[i], text[i+1], ' ', end='|')
    # print(text[i])
    if text[i].upper() == text[i + 1].upper() and text[i] != text[i + 1]:
      found = True
      new_text =  text[:i] + text[i+2:]
      text = new_text
  
  if found:
    return process_rec2(text)
  
  return text


def process_rec(text):
  # print('process', text)

  i = 0
  new_text = ''
  while i < len(text) - 1:
    if not (text[i].upper() == text[i + 1].upper() and text[i] != text[i + 1]):
      new_text += text[i]
    
    i += 1
  
  if text != new_text:
    return process_rec(new_text)
  
  return new_text
      
def process_loop(text):
  found = True

  while found == True:
    found = False
    for i in range(0, len(text)):
      if i > len(text) - 1:
        break
      
      print(text[i])
      # print(text[i], text[i+1], ' ', end='|')
      # if text[i].upper() == text[i + 1].upper() and text[i] != text[i + 1]:
      #   found = True
      #   new_text =  text[:i] + text[i+2:]
      #   text = new_text

  return text
  


new_text = process_rec(input)

# new_text = process_loop(input)

print(new_text, len(new_text))
print(len(new_text))
