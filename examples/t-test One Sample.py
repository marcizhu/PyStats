from pystats import *
from math import sqrt

# Significance level of 95%
alpha = 0.05

class Sample:
	pass

sample = Sample()
sample.nr   = 3       # Number of observations
sample.mean = 37.8    # Sample mean
sample.sd   = 0.96437 # Standard deviation

# Population expected mean
expected = 38.9

diff = sample.mean - expected
t_stat = diff * sqrt(sample.nr) / sample.sd
p_value = pt(-abs(t_stat), sample.nr - 1)

print('----------------------------------')
print('Student t test for a single sample')
print('----------------------------------')
print('')
print('Number of Observations                                 = {}'.format(sample.nr))
print('Sample Mean                                            = {:1.5f}'.format(sample.mean))
print('Sample Standard Deviation                              = {:1.5f}'.format(sample.sd))
print('Expected True Mean                                     = {:1.5f}'.format(expected))
print('')
print('Sample Mean - Expected Test Mean                       = {:1.5f}'.format(diff))
print('Degrees of Freedom                                     = {}'.format(sample.nr - 1))
print('T Statistic                                            = {:1.5f}'.format(t_stat))
print('Probability that difference is due to chance           = {:1.5e}'.format(2 * p_value))
print('')
print('Results for Alternative Hypothesis and alpha           = {:1.5e}'.format(alpha))
print('')
print('Alternative Hypothesis     Conclusion')
print('-------------------------------------')
print('Mean != {:1.5f}           {}'.format(expected, ('NOT REJECTED' if p_value < alpha / 2 else 'REJECTED')))
print('Mean  < {:1.5f}           {}'.format(expected, ('NOT REJECTED' if pt(-t_stat, sample.nr - 1) > alpha else 'REJECTED')))
print('Mean  > {:1.5f}           {}'.format(expected, ('NOT REJECTED' if pt( t_stat, sample.nr - 1) > alpha else 'REJECTED')))
print('')
