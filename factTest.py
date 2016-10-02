# Factorial function
# 	Computes n!
#	Returns the factorial of n.

def fact(n):
	if (n == 0):
		return 1
	else:
		return n * fact (n-1)

def main():
	n=0						# Input value
	while (n >= 0):
		n = int(input ("Please enter a number (or a negative number to end the program): "))
		if (n<0):
			break
		print (n, "! = ", fact(n))
		
	print ("Thank you for using the program! ")
	
main()	