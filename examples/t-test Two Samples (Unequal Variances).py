from pystats import *
from math import sqrt

# Significance level of 95%
alpha = 0.05

class Sample:
	pass

sample1 = Sample()
sample1.nr   = 249    # Number of observations
sample1.mean = 20.145 # Sample mean
sample1.sd   = 6.4147 # Standard deviation

sample2 = Sample()
sample2.nr   = 79     # Number of observations
sample2.mean = 30.481 # Sample mean
sample2.sd   = 6.1077 # Standard deviation

# Degrees of freedom
t1  = (sample1.sd**2 / sample1.nr)**2 / (sample1.nr - 1)
t2  = (sample2.sd**2 / sample2.nr)**2 / (sample2.nr - 1)
dof = (sample1.sd**2 / sample1.nr + sample2.sd**2 / sample2.nr)**2 / (t1 + t2)

# t-statistic:
t_stat = (sample1.mean - sample2.mean) / sqrt(sample1.sd**2 / sample1.nr + sample2.sd**2 / sample2.nr)

# p-value
p_value = 2 * pt(-abs(t_stat), dof)

print('--------------------------------------------------')
print('Student t test for two samples (unequal variances)')
print('--------------------------------------------------')
print('')
print('Sample 1:')
print('Number of Observations                                 = {}'.format(sample1.nr))
print('Sample Mean                                            = {:1.5f}'.format(sample1.mean))
print('Sample Standard Deviation                              = {:1.5f}'.format(sample1.sd))
print('')
print('Sample 2:')
print('Number of Observations                                 = {}'.format(sample2.nr))
print('Sample Mean                                            = {:1.5f}'.format(sample2.mean))
print('Sample Standard Deviation                              = {:1.5f}'.format(sample2.sd))
print('')
print('Degrees of Freedom                                     = {:1.5f}'.format(dof))
print('T Statistic                                            = {:1.5f}'.format(t_stat))
print('Probability that difference is due to chance           = {:1.5e}'.format(p_value))
print('')
print('Results for Alternative Hypothesis and alpha           = {:1.5f}'.format(alpha))
print('')
print('Alternative Hypothesis               Conclusion')
print('-------------------------------------------------')
print('Sample 1 Mean != Sample 2 Mean       ' + ('NOT REJECTED' if pt(-abs(t_stat), dof) < alpha / 2 else 'REJECTED'))
print('Sample 1 Mean <  Sample 2 Mean       ' + ('NOT REJECTED' if pt(     t_stat,  dof) < alpha     else 'REJECTED'))
print('Sample 1 Mean >  Sample 2 Mean       ' + ('NOT REJECTED' if pt( 1 - t_stat,  dof) < alpha     else 'REJECTED'))
print('')
