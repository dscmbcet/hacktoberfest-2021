# Python program to print prime numbers in an interval


def print_primes(lower_limit: int, upper_limit: int) -> None:
    # iterating the lower interval till it reaches the upper interval
    for i in range(lower_limit, upper_limit + 1):
        if lower_limit > 1:
            interval = 2
            # now as 2 is always prime, we check further
            for j in range(interval, i+1):
                # if they divide, it is not a prime
                if i % j == 0:
                    break
            else:
                print(i)

# Taking inputs

lower = int(input("Lower Limit: "))
upper = int(input("Upper Limit: "))

print_primes(lower, upper)
