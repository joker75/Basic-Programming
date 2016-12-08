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
    void setHourlyPay(int pay);
    void setWorkHours(int hours);

    // GETTER METHODS
    String getID();
    String getFullName();
    int getHourlyPay();
    int getWorkHours();

    // Calculates total pay
    int calc();
}
