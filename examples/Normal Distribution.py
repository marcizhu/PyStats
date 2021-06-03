from pystats import *

mean = 3.95  # mean of the samples
stddev = 0.1 # standard deviation of the samples

lower_bound = 3.9
upper_bound = 4.1

print('Fraction under lower bound [ P(X <= {:1.4f}) ] = {:1.4f}'.format(lower_bound, pnorm(lower_bound, mean, stddev)))
print('Fraction over upper bound [ P(X > {:1.4f}) ] = {:1.4f}'.format(upper_bound, 1-pnorm(upper_bound, mean, stddev)))

frac = pnorm(upper_bound, mean, stddev) - pnorm(lower_bound, mean, stddev)
print('Fraction between both bounds [ P({:1.4f} <= X <= {:1.4f}) ] = {:1.4f}'.format(lower_bound, upper_bound, frac))
print('95% of samples are under {:1.4f}'.format(qnorm(0.95, mean, stddev)))
