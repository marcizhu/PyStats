from pystats import *
from math import sqrt

class Sample:
	pass

sample = Sample()
sample.mean = 5.0 # Sample mean
sample.sd   = 2.0 # Standard deviation of sample
sample.nr   = 20  # Number of observations

expected = 7.0 # Expected mean

# For normal distribution:
z = (expected - sample.mean) / (sample.sd / sqrt(sample.nr));
p_value = 2 * pnorm(-abs(z), 0.0, 1.0);

# For t distribution:
#t = (expected - sample.mean) / (sample.sd / sqrt(sample.nr));
#p_value = 2 * pt(-abs(t), sample.nr - 1);

print(f'P-value for the sample: {p_value}');
