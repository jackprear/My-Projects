import numpy as np

#Simulation based on math of a NCAA Basketball game

'''
Description of variables
tm1 - string variable for the name of team 1
tm2 - string variable for the name of team 2
t1oe - adjusted points per possession for team 1, used for final score calculation
t2oe - same variable as above but for team 2
t1AdjO - average offensive efficiency in points/100 possessions for team 1
t2AdjO - same variable as above but for team 2
t1AdjD - average defensive efficiency in points/100 possessions for team 1
t2AdjD - same variable as above but for team 2
t1AvgOppD - The average defensive efficiency that team 1 faces in points/100 possessions
t2AvgOppD - The same as above, but for team 2
t1tempo - The tempo in avg possessions/game of team 1
t2tempo - the same as above but for team 2
gametempo - the average of the two teams' tempos
t1score - variable for the calculation of the final score of team 1
t2score - variable for the calculation of the final score of team 2
'''

#get the data from the keyboard
tm1 = input('Enter the name of Team 1: ')
tm2 = input('Enter the name of Team 2: ')
t1AdjO = float(input('Enter '+ tm1 +"'s AdjO: "))
t1AdjD = float(input('Enter '+tm1+"'s AdjD: "))
t1AvgOppD = float(input('Enter '+tm1+"'s Average OppD: " ))
t1tempo = float(input('Enter '+tm1+"'s tempo: "))

t2AdjO = float(input('Enter '+ tm2 +"'s AdjO: "))
t2AdjD = float(input('Enter '+tm2+"'s AdjD: "))
t2AvgOppD = float(input('Enter '+tm2+"'s Average OppD: " ))
t2tempo = float(input('Enter '+tm2+"'s tempo: "))

gametempo = (t1tempo + t2tempo)/2

t1oe = (t1AdjO/100) + np.log(t2AdjD/t1AvgOppD)
t2oe = (t2AdjO/100) + np.log(t1AdjD/t2AvgOppD)

t1score = t1oe*gametempo
t2score = t2oe*gametempo

print('The final score is: ')
print(tm1,': ',t1score)
print(tm2, ': ', t2score)


