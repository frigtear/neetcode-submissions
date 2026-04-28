class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        parenthesis = []

        def helper(lefts_given, rights_allowed):
            if lefts_given == 0 and rights_allowed == 0:
                result.append("".join(parenthesis))
                return

            if lefts_given > 0:
                parenthesis.append("(")
                helper(lefts_given - 1, rights_allowed + 1)
                parenthesis.pop()

            if rights_allowed > 0:
                parenthesis.append(")")
                helper(lefts_given, rights_allowed - 1)
                parenthesis.pop()

        helper(n, 0)
        return result