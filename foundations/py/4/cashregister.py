def show(label, price):
    print(label,  '=', f"{round(price, 2):.2f}")

price1 = float(input('Enter price of the first item:'))
price2 = float(input('Enter price of the second item:'))
club_card = input('Does customer have a club card? (Y/N):').lower() == 'y'
tax_rate = float(input('Enter tax rate, e.g. 5.5 for 5.5% tax:'))
base_price = price1 + price2
if price1 < price2:
    discount_price = price1/2 + price2
else:
    discount_price = price1 + price2/2
if club_card:
    discount_price *= 0.9
total_price = discount_price * (1 + tax_rate/100)
show('Base price',  base_price)
show('Price after discounts', discount_price)
show('Total price', total_price)
