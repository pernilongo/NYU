def isleapyear(year):
    return ((year % 4) == 0 and (year % 100) != 0) or (year % 400) == 0

if __name__ == "__main__":
    year = int(input('Year:'))
    if isleapyear(year):
        print('Year {0} was a leap year'.format(year))
