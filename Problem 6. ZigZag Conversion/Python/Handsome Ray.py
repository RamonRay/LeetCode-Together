class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if len(s)<2 or numRows<2:
            return s
        ans=''
        index=0
        round=2*numRows-2
        for i in range(numRows):
            index=i
            mark=1
            while index<len(s):
                ans+=s[index]
                #print index,i
                if i!=0 and i!=numRows-1:
                    if mark==1:
                        index+=round-i*2
                        mark=-1
                    else:
                        index+=i*2
                        mark=1
                else:
                    index+=round
        return ans