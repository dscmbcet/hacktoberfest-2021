# Python Program to print the sand-glass pattern

n_row = int(input("Enter number of rows: "))

# Inverted part
for i in range(0, n_row):
    for j in range(0, i):
        print(end = ' ')
    for k in range(i, n_row):
        print("* ",end = ' ')
    print('\n')

