#Manacher's Solving
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """

        def Manacher(s):
            newS = '@#' + '#'.join(s) + '#$'
            # print newS
            radius = [0] * len(newS)
            center = right = 0
            for i in range(1, len(newS) - 1):
                if i < right:
                    radius[i] = min(radius[2 * center - i], right - i)
                while newS[i + radius[i] + 1] == newS[i - radius[i] - 1]:
                    radius[i] += 1
                if i + radius[i] > right:
                    center, right = i, i + radius[i]
            # print radius
            return radius

        return sum((v + 1) / 2 for v in Manacher(s))
