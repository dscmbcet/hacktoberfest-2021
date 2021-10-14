# Python program to print prime numbers in an interval


def print_primes(lower_limit: int, upper_limit: int) -> None:
    while lower_limit < upper_limit + 1:
        if lower_limit > 1:
            interval = 2
            while interval < lower_limit:
                if lower_limit % interval == 0:
                    break
                interval += 1
            else:
                print(lower_limit)

        lower_limit += 1


# Taking inputs

lower = int(input("Lower Limit: "))
upper = int(input("Upper Limit: "))

print_primes(lower, upper)
