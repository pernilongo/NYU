print('Please enter the amount of money to convert:')
dollars = int(input('# of dollars:'))
cents = int(input('# of cents:'))

cents += dollars * 100
quarters = cents // 25
cents = cents % 25
dimes = cents // 10
cents = cents % 10
nickels = cents // 5
pennies = cents % 5

print('The coins are', quarters, 'quarters,', dimes, 'dimes,', nickels, 'nickels and', pennies, 'pennies')
