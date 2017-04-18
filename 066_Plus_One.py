def plus_one(number):
    num_digit=len(number)
    number[num_digit-1] += 1
    for digit in range(num_digit-1,0,-1):
        if number[digit] == 10:
            number[digit] = 0
            number[digit-1] += 1
        else:
            break
    if number[0] == 10:
        number[0] = 1
        for i in range(1,num_digit):
            number[i] = 0
        number.append(0)
    return number

if __name__ == "__main__":
    print plus_one([0])
