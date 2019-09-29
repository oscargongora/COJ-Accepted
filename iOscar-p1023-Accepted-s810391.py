import string
T = 12
A = 0
while T:
        A += float(raw_input())
        T -= 1       
print '$' + str(round(A*100/12)/100)       