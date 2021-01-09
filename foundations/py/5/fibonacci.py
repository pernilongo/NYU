n = int(input('Please enter a positive integer greater than 1:'))

p1 = 1
print(p1)
p2 = 1
print(p2)

for i in range(n-2):
    p2 += p1
    p1 = p2 - p1
    print(p2)
