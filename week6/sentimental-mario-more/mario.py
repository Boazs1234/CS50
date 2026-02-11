height = 0

# promting the user
while height < 1 or height > 8:
    try:
        height = int(input("Height: "))
    except ValueError:
        print("Enter a valid height")

# printing the blocks
for i in range(height):
    print(" " * (height - 1 - i), end="")
    print("#" * (i + 1) + "  " + "#" * (i + 1))
