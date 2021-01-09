def avg_val(lst):
    sum = 0
    for x in lst:
        sum += x
    return sum / len(lst)

if __name__ == "__main__":
    print(avg_val([19, 2, 20, 1, 0, 18]))
