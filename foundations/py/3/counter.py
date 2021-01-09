print('Please enter the number of coins:')
quarters = int(input('# of quarters:'))
dimes = int(input('# of dimes:'))
nickels = int(input('# of nickels:'))
pennies = int(input('# of pennies:'))

cents = quarters * 25 + dimes * 10 + nickels * 5 + pennies

print('The total is', (cents // 100), 'dollars and', (cents % 100), 'cents')
