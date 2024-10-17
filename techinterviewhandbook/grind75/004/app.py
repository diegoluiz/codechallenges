from typing import List
import math

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = math.inf
        max_price = 0
        max_sum = 0
        
        for price in prices:
            if price < min_price:
                min_price = price
                max_price = 0
            if price > max_price:
                t = price - min_price
                max_sum = max(t, max_sum)

        return max_sum
        
if __name__ == '__main__':
    s = Solution()
    print(s.maxProfit([7,1,5,3,6,4])) # expected 5
    print(s.maxProfit([7,6,4,3,1])) # expected 0