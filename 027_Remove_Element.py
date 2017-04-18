def remove_element(array, value):
    for entry in array:
        if entry == value:
            array.remove(entry)
    return array

if __name__ == "__main__":
    array=[1,5,3,4,2,1]
    array = remove_element(array,5)
    print(array)
