x = input('Enter an odd length string:')
middle = len(x) // 2

print('Middle character:', x[middle])
print('First half:', x[:middle])
print('Second half:', x[middle+1:])
