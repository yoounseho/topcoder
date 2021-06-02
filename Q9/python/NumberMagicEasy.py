class NumberMagicEasy:
    def __init__(self):
        pass

    def theNumber(self, answer : str):
        answerlist = [
            "YYYY",
            "YYYN",
            "YYNY",
            "YYNN",
            "YNYY",
            "YNYN",
            "YNNY",
            "YNNN",
            "NYYY",
            "NYYN",
            "NYNY",
            "NYNN",
            "NNYY",
            "NNYN",
            "NNNY",
            "NNNN"
        ]

        for i in range(0, len(answerlist)):
            if answer == answerlist[i]:
                return i+1
        return 0

print(NumberMagicEasy().theNumber("YNYY"))
print(NumberMagicEasy().theNumber("YNNN"))
print(NumberMagicEasy().theNumber("NNNN"))
print(NumberMagicEasy().theNumber("YYYY"))
print(NumberMagicEasy().theNumber("NYNY"))
