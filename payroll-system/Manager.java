/***************************************
 * This Manager class contains two extra
 * data fields, setter methods, and
 * getter methods. This is to keep track
 * of overtime wages. Instances of this
 * class can be created.
 *
 * Created by Victor on 12/8/2016.
 **************************************/
public class Manager extends abstractPerson {
    // Defines private data fields
    private int overtimeHourlyPay;  // How much pay per hour: validate for positive #'s
    private int overtimeWorkHours;	// How many hours: validate for positive #'s and
                                    // max time (40 hours) overtime (58 hours)
    // SETTER METHODS
    public void setOvertimePay(int pay)     {this.overtimeHourlyPay = pay;}
    public void setOvertimeHours(int hours) {this.overtimeWorkHours = hours;}

    // GETTER METHODS
    public int getOvertimePay()     {return this.overtimeHourlyPay;}
    public int getOvertimeHours()   {return this.overtimeWorkHours;}
}
