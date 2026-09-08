import random
import time
import matplotlib.pyplot as plt


#Bubble Sort function
def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n - i - 1):

            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr


#Function to create random array
def create_array(n):
    arr = []

    for i in range(n):
        arr.append(random.randint(1, 1000))

    return arr


#Lists to store results
sizes = []
times = []


#Test Bubble Sort for different input sizes
for n in range(100, 5001,100):

    arr = create_array(n)
    start = time.time()
    bubble_sort(arr)
    end = time.time()
    execution_time = end - start

    sizes.append(n)
    times.append(execution_time)


#Plot the results
plt.plot(sizes, times)

plt.xlabel("Array Size (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Bubble Sort Execution Time")

plt.show()