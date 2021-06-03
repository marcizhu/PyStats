from pystats import *

# Significance level of 95%
alpha = 0.05

class Sample:
	pass

sample1 = Sample()
sample1.nr = 11     # Number of observations
sample1.sd = 4.9082 # Standard deviation

sample2 = Sample()
sample2.nr = 9      # Number of observations
sample2.sd = 2.5874 # Standard deviation

dist = (sample1.sd / sample2.sd)**2
cdf  = pf(dist, sample1.nr - 1, sample2.nr - 1)
ucv1 = qf(1 - alpha,     sample1.nr - 1, sample2.nr - 1)
ucv2 = qf(1 - alpha / 2, sample1.nr - 1, sample2.nr - 1)
lcv1 = qf(    alpha,     sample1.nr - 1, sample2.nr - 1)
lcv2 = qf(    alpha / 2, sample1.nr - 1, sample2.nr - 1)

print('------------------------------------')
print('F test for equal standard deviations')
print('------------------------------------')
print('')
print('Sample 1:')
print('Number of Observations                                 =  {}'.format(sample1.nr))
print('Sample Standard Deviation                              =  {:1.5f}'.format(sample1.sd))
print('')
print('Sample 2:')
print('Number of Observations                                 =  {}'.format(sample2.nr))
print('Sample Standard Deviation                              =  {:1.5f}'.format(sample2.sd))
print('')
print('Test Statistic                                         =  {:1.5f}'.format(dist))
print('')
print('CDF of test statistic:                                 =  {:1.5f}'.format(cdf))
print('Upper Critical Value at alpha:                         =  {:1.3e}'.format(ucv1))
print('Upper Critical Value at alpha/2:                       =  {:1.3e}'.format(ucv2))
print('Lower Critical Value at alpha:                         =  {:1.3e}'.format(lcv1))
print('Lower Critical Value at alpha/2:                       =  {:1.3e}'.format(lcv2))
print('')
print('Results for Alternative Hypothesis and alpha           =  {:1.5f}'.format(alpha))
print('')
print('Alternative Hypothesis                                       Meaning        Conclusion')
print('--------------------------------------------------------------------------------------')
print('Standard deviations are unequal (two sided test)             s(1) != s(2)   ' + ('NOT REJECTED' if (ucv2 < dist) or (lcv2 > dist) else 'REJECTED'))
print('Standard deviation 1 is less than standard deviation 2       s(1) <  s(2)   ' + ('NOT REJECTED' if lcv1 > dist else 'REJECTED'))
print('Standard deviation 1 is greater than standard deviation 2    s(1) >  s(2)   ' + ('NOT REJECTED' if lcv1 < dist else 'REJECTED'))
print('')
