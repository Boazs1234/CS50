from cs50 import get_float

change = 0
coins = 0

# promting the user
while change <= 0:
    change = get_float("change: ")

# adding coins and reducing the change

def Reducer(ValueToReduce):
    global change
    global coins
    while change >= ValueToReduce:
        change = round(change - ValueToReduce, 10)
        coins += 1


Reducer(0.25)
Reducer(0.10)
Reducer(0.05)
Reducer(0.01)

print(coins)
