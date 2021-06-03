from pystats import *

flips = 10
success_fraction = 0.5 # = 50% = 1/2 for a 'fair' coin.

print('Using Binomial distribution to predict how many heads and tails.')
print('')
print(f'For {flips} coin flips:')
print('Probability of getting no heads is {:5.5f}'.format(dbinom(0, flips, success_fraction)))
print('Probability of getting at least one head is {:5.5f}'.format(1 - dbinom(0, flips, success_fraction)))
print('Probability of getting 0 or 1 heads is {:5.5f}'.format(dbinom(0, flips, success_fraction) + dbinom(1,  flips, success_fraction)))
print('Probability of getting 9 or 10 heads is {:5.5f}'.format(dbinom(9, flips, success_fraction) + dbinom(10, flips, success_fraction)))
print('Probability of between 4 and 6 heads (4 or 5 or 6) is {:5.5f}'.format(pbinom(6, flips, success_fraction) - pbinom(3, flips, success_fraction)))
print('Probability of between 3 and 7 heads (3, 4, 5, 6 or 7) is {:5.5f}'.format(pbinom(7, flips, success_fraction) - pbinom(2, flips, success_fraction)))
print('')
print('Probability of getting exactly (==) heads')

for i in range(flips + 1):
	prob = dbinom(i, flips, success_fraction)
	print('  {:2d}      {:7.7f}  or 1 in {:8.3f}'.format(i, prob, 1.0 / prob))

print('\n\nProbability of getting upto (<=) heads')

for i in range(flips + 1):
	prob = pbinom(i, flips, success_fraction)
	print('  {:2d}      {:7.7f}  or 1 in {:8.3f}'.format(i, prob, 1.0 / prob))

print('')
