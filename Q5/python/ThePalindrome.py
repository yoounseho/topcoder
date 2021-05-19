
class ThePalindrome:
    def __init__(self):
        pass

    def find(self, s : str):
        count = 1
        for i in range(0,s.__len__()):
            count = i
            bDiff = False
            for j in range(0,s.__len__()):
                if j+1 == int(s.__len__()/2) or i + j >= s.__len__():
                    break

                if s[j + i] != s[s.__len__()-1-j]:
                    bDiff = True
                    break


            if not bDiff:
                break

        return s.__len__() + count


print(ThePalindrome().find("abab"))
print(ThePalindrome().find("abacaba"))
print(ThePalindrome().find("qwerty"))
print(ThePalindrome().find("abdfhdyrbdbsdfghjkllkjhgfds"))
print(ThePalindrome().find("abcccc"))