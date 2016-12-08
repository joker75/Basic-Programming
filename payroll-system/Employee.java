class Employee implements Person{
  	// Defines private variables
	  private String id;			// Employee ID: Set of 8 integers
	  private String fullName;		// Full name: anything as well
	  protected static int hourlyPay;		// How much pay per hour: validate for positive #'s
	  protected static int workHours;		// How many hours: validate for positive #'s and
						                          // max time (40 hours) overtime (58 hours)
}
