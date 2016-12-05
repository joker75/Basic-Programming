/************************************
 * This is the Linear Equation class.
 * Created by Victor on 9/25/2016.
 ***********************************/
public class LinearEquation{
	// Private data fields
	private double a, b, c, d, e, f, denominator = 0.0;
	
	// Constructor
	LinearEquation(double num1, double num2, double num3, double num4, double num5, double num6){	
	a = num1;
	b = num2;
	c = num3;
	d = num4;
	e = num5;
	f = num6;
	}	
	
	// Gets the value of all variables
	public double getA () { return a; }
	public double getB () {	return b; }
	public double getC () {	return c; }
	public double getD () {	return d; }
	public double getE () {	return e; }	
	public double getF () {	return f; }	

	public boolean isSolvable()		// Store the return value as denominator
	{										// If false, throw exception:
		denominator = (a*d) -(b*c);	// "The equation has no solution."
		if (denominator != 0)
			return true;
		else
			return false;
	}

	// Returns the value of x
	public double getX()
	{	return ( (e*d) - (b*f) ) / denominator; }
	
	// Returns the value of y
	public double getY()
	{	return ( (a*f) - (e*c) ) / denominator; }
}
