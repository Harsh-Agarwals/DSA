arr = [1, 6, 3, 0, -3, 7, 3, 2, 9]
# arr = [7, 3, 8, 9, 11]

def finding_lowest(arr):
    min = arr[0]
    for i in range(1, len(arr)):
        if arr[i] < min:
            min = arr[i]
    return min
    
def bubble_sort(arr):
    for i in range(len(arr)):
        print(i)
        swapped = False
        for j in range(len(arr)-1):
            if arr[j]>arr[j+1]:
                swapped=True
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
        if swapped==False:
            return arr
    return arr
    
def selection_sort(arr):
    for i in range(len(arr)-1):
        mini = arr[i]
        start = arr[i]
        index=i
        for j in range(i+1, len(arr)):
            if arr[j]<mini:
                mini = arr[j]
                index=j
        arr[i]=mini
        arr[index]=start
    print(arr)
        
    
    
lowest = finding_lowest(arr)
print(lowest)
sorteda = bubble_sort(arr)
print(sorteda)
arr = [1, 6, 3, 0, -3, 7, 3, 2, 9]
print("arr", arr)
sorted2 = selection_sort(arr)
print(sorted2)

