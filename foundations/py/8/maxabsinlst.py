def max_abs_val(lst):
    max = abs(lst[0])
    for x in lst:
        if abs(x) > max:
            max = abs(x)
    return max

if __name__ == "__main__":
    print(max_abs_val([-19, -3, 20, -1, 0, -25]))
