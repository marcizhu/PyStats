from pystats import *
from math import sqrt

class Sample:
	pass

sample = Sample()
sample.nr   = 195        # Number of observations
sample.mean = 9.26146    # Sample mean
sample.sd   = 0.02278881 # Standard deviation

# Confidence levels, from 50% to 99.999%
confidence_intervals = [ 0.5, 0.75, 0.9, 0.95, 0.99, 0.999, 0.9999, 0.99999 ]

print('----------------------------------')
print('2-Sided Confidence Limits For Mean')
print('----------------------------------')
print('')
print('Number of observations                                 = {:d}'.format(sample.nr))
print('Sample mean                                            = {:6.6f}'.format(sample.mean))
print('Sample standard deviation                              = {:6.6f}'.format(sample.sd))
print('')
print('')
print('-------------------------------------------------------------------')
print('Confidence       T           Interval         Lower          Upper ')
print(' Value (%)     Value          Width           Limit          Limit ')
print('-------------------------------------------------------------------')

for confidence_interval in confidence_intervals:
	alpha = 1 - (1 - confidence_interval) / 2

	t = qt(alpha, sample.nr - 1)
	width = t * sample.sd / sqrt(sample.nr)
	lower = sample.mean - width
	upper = sample.mean + width

	print('  {:2.3f}       {:3.3f}         {:1.3e}       {:1.5f}        {:1.5f}'.format(confidence_interval * 100, t, width, lower, upper))

print('')
