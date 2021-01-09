def max_val(lst):
    max = lst[0]
    for x in lst:
        if x > max:
            max = x
    return max

if __name__ == "__main__":
    print(max_val([-19, -3, 20, -1, 5, -25]))
