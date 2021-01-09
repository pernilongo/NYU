def remainingwords(text):
    idx = text.find(' ')
    return text[idx+1:] if idx > 0 else ''

if __name__ == "__main__":
    print(remainingwords('the quick brown fox'))
    print(remainingwords('Mississippi'))
