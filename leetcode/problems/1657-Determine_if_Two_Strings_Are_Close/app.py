class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        if set(word1) != set(word2):
            return False


        map_word1 = {}
        map_word2 = {}

        for c in word1:
            if c not in map_word1:
                map_word1[c] = 0
            map_word1[c] += 1

        for c in word2:
            if c not in map_word2:
                map_word2[c] = 0
            map_word2[c] += 1

        word1_char_counts = map_word1.values()
        word2_char_counts = map_word2.values()

        return sorted(word1_char_counts) == sorted(word2_char_counts)

s = Solution()

tests = [
    ('caaabcbbc', 'baaabbbcc', False),
    ('caaabcbbc', 'abaacbbcc', True),
    ('caaabcbbc', 'baaabbbcc', False),
    ('abc', 'bca', True),
    ('aa', 'b', False),
    ('cabbba', 'abbccc', True),
    ('abc', 'aab', False),
    ('aabbcc', 'aabbdd', False),
]


for test in tests:
    word1, word2, expected = test
    r = s.closeStrings(word1, word2)
    print (r == expected)
    # print (expected)

print('Done')