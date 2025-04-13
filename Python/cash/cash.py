c25 = 0
c10 = 0
c5 = 0
c1 = 0

n = 0
while (n <= 0):
    n = float(input("Change: "))
cents = round(n * 100)

c25 = cents // 25
cents %= 25

c10 = cents // 10
cents %= 10

c5 = cents // 5
cents %= 5

c1 = cents // 1

total = c25 + c10 + c5 + c1

print(f"Total: {total}")
