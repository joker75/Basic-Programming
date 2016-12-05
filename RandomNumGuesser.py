import random	
def main():
	print ("Guess a number between 1 and 100: ")
	randomNum = random.randint (1,100)		# Creates a random integer literal for every
							# run of the program
	found = False					# Flag variable to see if
							# they guessed it
																	
	while (found == False):				# !found does not work => use found == False 
							# as the alternative
		userGuess = int(input ("Your guess: "))	# The input must be received as an integer
																		# not a string
		# Run through the guessing process
		if (userGuess == randomNum):
			print ("You got it!")
			found = True
		elif (userGuess < randomNum):		# Help the user increase the guess num
			print ("Guess higher.")
		else: #(userGuess < randomNum)		# Help the user decrease the guess num
			print ("Guess lower.")
	# Print congradulations and goodbye
	print("Congrats! Thanks for playing the game!")
# Run the program		
main()	

# SYNTAX NOTES
# x = random.randint (a,b) means a <= x <= b
# Postfix/prefix increment and decrements do not exist => use x+=1 or x-=1
# !found does not work => use found == False 
# The input must be received as an integer, not a string, if you want to evaluate it
