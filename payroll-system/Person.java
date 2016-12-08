// This Person class will act as the 
// main class from which all other 
// classes will inherit from.

// should be an interface. 
public interface Person {
  	// SETTER METHODS
	void setID(String input);
	void setFullName(String input);
	void setHourlyPay(int pay);
	void setWorkHours(int hours);
	
	// GETTER METHODS
	String getID();
	String getFullName();
	int getHourlyPay();
	int getWorkHours():
	
	// Calculates total pay
	int calc();
}
