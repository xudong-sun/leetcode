def string2int(string):
    value = 0
    for char in string:
        value = value * 10 + int(char)
    return value

def compare_version_numbers(version1, version2):
    values1 = version1.split('.')
    values2 = version2.split('.')
    length1 = len(values1)
    length2 = len(values2)
    length = max(length1, length2)
    for i in range(length):
        value1 = string2int(values1[i]) if i<length1 else 0
        value2 = string2int(values2[i]) if i<length2 else 0
        if value1 < value2:
            return -1
        elif value1 > value2:
            return 1
    return 0

if __name__ == "__main__":
    print compare_version_numbers("13.1", "9.8.2")
