# Returns the sum of num1 and num2
def add(num1, num2): 
	return num1 + num2

# Returns the difference of num1 and num2
def sub(num1, num2): 
	return num1 - num2

# Returns the product of num1 and num2
def mul(num1, num2): 
	return num1 * num2

# Returns the quotient of num1 and num2
def div(num1, num2): 
	return num1 / num2	
	
# def the main function	
def main():
	operation = input ("What do you want to do? (+,-,*,/): ")
	if (operation != '+' and operation != '-' and operation != '*' and operation != '/'):
		# invalid operation
		print ("You must enter a "
		"valid operation")
	else:	
		var1 = int(input ("Please enter num1: "))
		var2 = int(input ("Please enter num2: "))
		if (operation == '+'):
			print (add(var1,var2))
		elif (operation == '-'):
			print (sub(var1,var2))
		elif (operation == '*'):
			print (mul(var1,var2))		
		elif (operation == '/'):
			print (div(var1,var2))
			
# Call the main function
x=0		
while(x<2):
	main()
	x+=1
print("Thank you for using this basic calculator. ")