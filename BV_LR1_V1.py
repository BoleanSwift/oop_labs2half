import glob

team_point = []

for file in glob.glob('C:/Users/Bogdan/Desktop/Scripts & Codes/Python 2 half/laba1/Introduction-To-Programming/labs_spring_2020/examples_2/var2/*.csv'):
    with open(file) as f:
        first_line = True
        num_lines = 0
        for line in f:
            if first_line:
                num_lines = int(line)
                first_line = False
                continue
            array = line.split(',')
            team = [array[0], 0]
            for i in range(1, len(array)):
                if array[i][0]  > array[i][2]:
                    team[1] += 3
                elif array[i][0] == array[i][2]:
                    team[1] += 1
            team_point.append(team)

def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j][1] < arr[j + 1][1]:
                arr[j], arr[j + 1] = arr[j +1], arr[j]
    return arr

team_point = bubbleSort(team_point)