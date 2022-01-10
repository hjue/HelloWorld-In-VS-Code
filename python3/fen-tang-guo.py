# echo "[1,1,2,2,3,3]" | python3 fen-tang-guo.py

from typing import List
import json
import sys


class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(set(candyType)), len(candyType) // 2)


def stringToIntegerList(input):
    return json.loads(input)


if __name__ == '__main__':
    solution = Solution()

    lines = sys.stdin.readlines()
    print(lines)
    ret = solution.distributeCandies(stringToIntegerList(lines[0]))
    print(ret)
