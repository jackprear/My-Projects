'''
1. Pick Empty Square
2. Try all numbers
3. Find one that works
4. Repeat
5. Backtrack
'''
import pprint
#Make the Board
board = [
    [4,0,7,9,0,0,0,0,0],
    [2,0,5,0,0,3,0,0,0],
    [0,9,0,6,7,0,0,0,0],
    [9,0,0,0,0,0,0,4,0],
    [0,0,0,7,8,6,0,0,0],
    [0,1,0,0,0,0,0,0,6],
    [0,0,0,0,3,2,0,9,0],
    [0,0,0,8,0,0,5,0,3],
    [0,0,0,0,0,4,7,0,1]
]
#Function to print the board
def print_board(bo):
    for i in range(len(bo)):
        if i%3 == 0 and i != 0:
            print('------------------------')
        for j in range(len(bo[0])):
            if j%3 == 0 and j != 0:
                print(' | ', end='')
            if j == 8:
                print(bo[i][j])
            else:
                print(str(bo[i][j]) + ' ', end='')


#Function to find empty positions in the board
#Returns the position of the empty square
def find_empty(bo):
    for i in range(len(bo)):
        for j in range(len(bo[0])):
            if bo[i][j] == 0:
                return (i, j) # row, column

    return None


#Function that checks if the board is valid
def valid(bo, num, pos):
    #Check Row
    for i in range(len(bo[0])):
        if bo[pos[0]][i] == num and pos[1] != i:
            return False
    #Check Column

    for i in range(len(bo)):
        if bo[i][pos[1]] == num and pos[0] != i:
            return False

    #Check the 3x3 box
    box_x = pos[1] // 3
    box_y = pos[0] // 3
    #Loop through the box
    for i in range( box_y *3, box_y*3 +3):
        for j in range(box_x*3, box_x*3+3):
            if bo[i][j] == num and (i,j) != pos:
                return False

    return True

#Function that actually solves the board
def solve(bo):
    find = find_empty(bo)
    if not find:
        return True
    else:
        row, col = find
    for i in range(1,10):
        if valid(bo, i, (row, col)):
            bo[row][col] = i

            if solve(bo):
                return True

        bo[row][col] = 0

    return False

print_board(board)
solve(board)
print('\n\n\n')
print_board(board)




