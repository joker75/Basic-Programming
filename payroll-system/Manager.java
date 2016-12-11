/***************************************
 * This Manager class contains two extra
 * data fields, setter methods, and
 * getter methods. This is to keep track
 * of overtime wages. Instances of this
 * class can be created.
 *
 * Created by Victor on 12/8/2016.
 **************************************/
class Manager extends abstractPerson {
    // Defines private data fields
    private double overtimeHourlyPay;   // How much pay per hour: validate for positive #'s
    private double overtimeWorkHours;   // How many hours: validate for positive #'s and
                                        // max time (40 hours) overtime (58 hours)
    // SETTER METHODS
    void setOvertimePay(double pay)  {this.overtimeHourlyPay = pay;}
    void setOvertimeHours(double hours) {this.overtimeWorkHours = hours;}

    // GETTER METHODS
    double getOvertimePay()  {return this.overtimeHourlyPay;}
    double getOvertimeHours(){return this.overtimeWorkHours;}

    // Calculates overtime pay
    // total pay = hours * rate
    double OverTimeCalc()    {return this.overtimeHourlyPay * this.overtimeWorkHours;}
    double totalCalc()       {return calc() + OverTimeCalc();}

}
