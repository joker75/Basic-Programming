/**************************************
 * This interface has the basic methods
 * for a person working at a company.
 * No instances of this interface can
 * be created.
 *
 * Created by:  Victor on 12/8/2016.
 *              vdn140030
 *              CS 2336.005
 *              FALL 2016
 *************************************/
public interface Person {
    // SETTER METHODS
    void setID(String input);
    void setFullName(String input);
    void setHourlyPay(double pay);
    void setWorkHours(double hours);

    // GETTER METHODS
    String getID();
    String getFullName();
    double getHourlyPay();
    double getWorkHours();

    // Calculates total pay
    double calc();
}
