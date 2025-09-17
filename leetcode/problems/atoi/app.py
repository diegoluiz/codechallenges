def m(i: str) -> int:
    r = 0
    is_negative = False
    if i[0] == '-':
        is_negative = True
        i=i[1:]

    for c in i:
        x = ord(c) - ord('0')
        r *= 10
        r += x
        
    return r if not is_negative else r * -1


tests = [
    ("12345", 12345),
    ("012345", 12345),
    ("-12345", -12345),
    ("-012345", -12345)
]

for test in tests:
    r = m(test[0])
    print(r==test[1])
