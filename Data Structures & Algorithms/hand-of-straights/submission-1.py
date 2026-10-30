class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n = len(hand)
        map = Counter(hand)

        for currentcard in sorted(map.keys()):
            count = map[currentcard]

            if count ==0: continue
            for j in range(groupSize):
                nextcard = currentcard+j
                if count>map[nextcard]: return False

                map[nextcard] = map[nextcard]-count

        return True;