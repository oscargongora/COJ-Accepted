import string
n = int(raw_input())
while n:
    nbin = bin(n)[2:]
    print 'The parity of {0} is {1} (mod 2).'.format(nbin, nbin.count('1'))
    n = int(raw_input())