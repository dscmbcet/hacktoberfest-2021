# Python program to print prime numbers in an interval

def PrintPrimes(lower, upper):
    i = lower
    while(i < upper+1):
        if(i > 1):
            j = 2
            while(j < i):
                if(i % j == 0):
                    break
                j += 1
            else:
                print(i)
            
        i += 1

# Taking inputs

lower = input("Lower Limit: ")
upper = input("Upper Limit: ")

PrintPrimes(lower, upper)
