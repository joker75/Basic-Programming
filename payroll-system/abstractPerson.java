/*************************************
 * This abstract class implements the
 * methods of the Person interface.
 * No instances of this abstract class
 * can be created.
 *
 * Created by:  Victor on 12/8/2016.
 *              vdn140030
 *              CS 2336.005
 *              FALL 2016
 ************************************/
public abstract class abstractPerson implements Person{
    // Defines private variables
    private String id;		    // Employee ID: Set of 8 integers
    private String fullName;    // Full name: anything
    private double hourlyPay;   // How much pay per hour: validate for positive #'s
    private double workHours;	// How many hours: validate for positive #'s and
                                // max time (40 hours)

    // SETTER METHODS
    public void setID(String input)         {this.id = input;}
    public void setFullName(String input)   {this.fullName = input;}
    public void setHourlyPay(double pay)    {this.hourlyPay = pay;}
    public void setWorkHours(double hours)  {this.workHours = hours;}

    // GETTER METHODS
    public String getID()           {return this.id;}
    public String getFullName()     {return this.fullName;}
    public double getHourlyPay()    {return this.hourlyPay;}
    public double getWorkHours()    {return this.workHours;}

    // Calculates total pay
    // total pay = hours * rate
    public double calc(){return this.hourlyPay * this.workHours;}
}
