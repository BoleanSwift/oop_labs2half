

team_point = 10

def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j][1] < arr[j + 1][1]:
                arr[j], arr[j + 1] = arr[j +1], arr[j]
    return arr

team_point = bubbleSort(team_point)