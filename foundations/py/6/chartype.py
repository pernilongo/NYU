ch = input('Enter a character:')

if ch.isupper():
    print(ch, 'is an upper case letter.')
elif ch.islower():
    print(ch, 'is a lower case letter.')
elif ch.isdigit():
    print(ch, 'is a digit.')
else:
    print(ch, 'is a non-alphanumeric character.')
