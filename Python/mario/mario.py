size = 0
while (size < 1 or size > 8):
    size = int(input("Size: "))
for i in range(size):
    for j in range(size):
        if (size - i - 2 < j):
            print("#", end = "")
        else:
            print(" ", end = "")
    print()
