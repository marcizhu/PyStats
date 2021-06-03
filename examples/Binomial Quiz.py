from pystats import *

questions = 16 # All the questions in the quiz.
answers   = 4  # Possible answers to each question.
success_fraction = 1.0 / answers

print('In a quiz with {} questions and with a probability of guessing right of {}% or 1 in {}'.format(questions, success_fraction * 100, 1 / success_fraction))
print('Probability of getting exactly 0 answers right by chance is {:1.4f}'.format(dbinom(0, questions, success_fraction)))
print('Probability of getting exactly 1 answers right by chance is {:1.4f}'.format(dbinom(1, questions, success_fraction)))
print('Probability of getting exactly 2 answers right by chance is {:1.4f}'.format(dbinom(2, questions, success_fraction)))
print('Probability of getting exactly 11 answers right by chance is {:1.4f}'.format(dbinom(11, questions, success_fraction)))
print('Probability of getting all 16 answers right by chance is {:1.4e}'.format(dbinom(16, questions, success_fraction)))
print('')
print('Guessed    Probability')
print('----------------------')

for i in range(0, questions+1):
	print(' {:2d}         {:1.3e}'.format(i, dbinom(i, questions, success_fraction)))

print('')
