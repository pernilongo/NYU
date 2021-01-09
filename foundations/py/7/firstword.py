def firstword(text):
    idx = text.find(' ')
    return text[:idx] if idx > 0 else text

if __name__ == "__main__":
    print(firstword('the quick brown fox'))
    print(firstword('Mississippi'))
