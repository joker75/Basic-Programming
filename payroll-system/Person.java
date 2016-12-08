// This Person class will act as the 
// main class from which all other 
// classes will inherit from.

// should be an interface. 
public class Person {
	// Defines private variables
	private String id;			// Employee ID: Set of 8 integers
	private String fullName;		// Full name: anything as well
	protected static int hourlyPay;		// How much pay per hour: validate for positive #'s
	protected static int workHours;		// How many hours: validate for positive #'s and
						// max time (40 hours) overtime (58 hours)	
	
	// SETTER METHODS
	public void setID(String input){this.id = input;}		
	public void setBirthDate(String input){this.fullName = input;}
	public void setHourlyPay(int pay){Person.hourlyPay = pay;}
	public void setWorkHours(int hours){Person.workHours = hours;}
	
	// GETTER METHODS
	public String getID(){return this.id;}
	public String getBirthDate(){return this.fullName; }
	public int hourlyPay(){return Person.hourlyPay;}
	public int getWorkHours(){return Person.workHours;}
	public static int calc(){return hourlyPay * workHours;}
}
