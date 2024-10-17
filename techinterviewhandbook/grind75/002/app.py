from typing import List

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        matches = {
             ']': '[',
             '}': '{',
             ')': '('
        }

        for c in s:
            if c not in matches:
                stack.append(c)
                continue
            
            if len(stack) < 1:
                return False

            x = stack.pop()
            if x != matches[c]:
                return False

        if len(stack) > 0:
            return False

        return True


if __name__ == '__main__':
    s = Solution()
    print(s.isValid("()[]{}")) #true
    print(s.isValid("(]")) #false