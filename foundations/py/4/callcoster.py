week_day = input('Enter the day the call started at:')
time24 = int(input('Enter the time the call started at (hhmm):'))
duration = int(input('Enter the duration of the call (in minutes):'))
if week_day.lower() in {'sat', 'sun'}:
    rate = 0.15
elif 800 <= time24 <= 1800:
    rate = 0.40
else:
    rate = 0.25
cost = rate * duration
print('This call will cost', f"${round(cost, 2):.2f}")
