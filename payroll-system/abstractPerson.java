public abstract abstractPerson implements Person{
  	// SETTER METHODS
	public abstract void setID(String input);
	public abstract void setFullName(String input);
	public abstract void setHourlyPay(int pay);
	public abstract void setWorkHours(int hours);
	
	// GETTER METHODS
	public abstract String getID();
	public abstract String getFullName();
	public abstract int getHourlyPay();
	public abstract int getWorkHours():
	
	// Calculates total pay
	public abstract static int calc();
}
