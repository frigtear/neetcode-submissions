class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        def helper(lp, rp, path):
            result = list()
    
            if lp == 0 and rp == 0:
                return [path]

            if lp > 0:
                result += helper(lp - 1, rp, path + "(")
            if lp < rp:
                result += helper(lp, rp-1, path + ")")
            
            return result

        return helper(n, n, "")



            
