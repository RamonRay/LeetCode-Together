#using stack
class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        #Adding Zeroes for Starting and Finishing
        heights=[0]+heights+[0]
        #keep the stack index right
        stack=[0]
        maxA=0
        for i in range(len(heights)):
            #heights in stack are all smaller or equal to that of stack[-1]
            while heights[i]<heights[stack[-1]]:
                tmp=stack.pop()
                maxA=max(heights[tmp]*(i-stack[-1]-1),maxA)
            stack.append(i)
        return maxA