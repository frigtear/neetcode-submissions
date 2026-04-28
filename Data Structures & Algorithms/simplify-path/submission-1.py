class Solution:
    def simplifyPath(self, path: str) -> str:

        stack = list()
        folders = path.split('/')
        
        for folder in folders:
            if folder:

                if stack and folder == "..":
                    stack.pop()
                elif folder != "." and folder != "..":
                    stack.append(folder)


        return "/" + "/".join(stack)
                


        