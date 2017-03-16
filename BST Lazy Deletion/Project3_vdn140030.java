/*************************************************
 * Project 3: Lazy Deletion
 * This project allows the user to store elements,
 * of any type, into a Binary Search Tree. The
 * program can implement the following features:
 * - Lazy deletion
 * - Insertion, Deletion, Contains
 * - Finding the minimum and maximum
 * - Printing the sorted order of the tree
 * - Calculate the height, the total number of
 * nodes, and the number of deleted nodes
 * - Input validation with try/catch blocks
 *
 * Created by:  Victor Nguyen on 2/21/2017.
 * Class:       CE 3345
 * Section:     003
 * Semester:    Spring 2017
 ************************************************/
import java.util.*;
public class Project3_vdn140030 {

    // Defines the input variable
    private static Scanner input = new Scanner(System.in);

    public static void main(String [] args){

        // Defines variables
        BSTree<Double> tree = new BSTree <>();
        int menu_option = 0;
        boolean valid_option = true;

        // Introduction
        System.out.println("Binary Search Tree\nwith Lazy Deletion!");

        // Go through menu system
        while(menu_option != 9){
            // PART I \\
            // Prompt the user for validated input
            do{
                // INPUT VALIDATION FOR MENU ACCESS
                // TRY BLOCK
                try{
                    System.out.print(
                            "\nOperations\n" +
                            "\t1. Insert\n" +
                            "\t2. Delete\n" +
                            "\t3. Find the Maximum\n" +
                            "\t4. Find the Minimum\n" +
                            "\t5. Search for an element\n" +
                            "\t6. Inorder Tree Traversal\n" +
                            "\t7. Height\n" +
                            "\t8. Number of Nodes\n" +
                            "\t9. Quit\n");
                    menu_option = input.nextInt();
                    if (menu_option < 1 || menu_option > 9)
                        throw new IllegalArgumentException("Valid menu options are from 1 to 9. ");
                    else
                        valid_option = true;
                }

                // EXCEPTION HANDLING
                // CATCH BLOCK
                catch (InputMismatchException | IllegalArgumentException ex){
                    System.out.println("ERROR! Please enter a positive integer from 1 to 9 " + ex);
                    valid_option = false;   // If this catch block is reached, the input
                                            // is NOT valid! Therefore, this do-while
                                            // loop repeats itself!
                    input.nextLine();       // Discard current input
                }

            // If the input is NOT VALID, repeat this loop.
            }while (!valid_option);

            // PART II \\
            // Perform operations based on menu
            System.out.println("You have entered menu option: " + menu_option);
            switch(menu_option){
                case 1:
                    tree.insert(validate());
                    System.out.println("Element inserted\n\n");
                    break;
                case 2:
                    tree.remove(validate());
                    System.out.println("Element deleted");
                    break;
                case 3:
                    System.out.println("The maximum element is: " + tree.findMax());
                    break;
                case 4:
                    System.out.println("The maximum element is: " + tree.findMin());
                    break;
                case 5:
                    System.out.println("Is the element in this tree? " + tree.contains(validate()));
                    break;
                case 6:
                    System.out.println("Inorder Traversal: ");
                    tree.inorder_traversal();
                    break;
                case 7:
                    System.out.println("Height: " + tree.findHeight());
                    break;
                case 8:
                    System.out.println(tree.getNodes());
                    break;
            }

            // Adds some spacing for user clarity
            System.out.println();
        }

        System.out.println("End of Program. ");
    }

    /*******************************************
     * This function will validate user input. *
     ******************************************/
    private static Double validate(){
        Double value = 0.0;
        boolean valid_num = true;

        // MORE INPUT VALIDATION
        do {
            // Prompts the user + TRY BLOCK
            System.out.println("Please enter any integer number or floating point number: ");
            try {
                value = input.nextDouble();
                valid_num = true;
            }

            // EXCEPTION HANDLING
            // CATCH BLOCK
            catch (InputMismatchException ex) {
                System.out.println("ERROR! Please enter valid numbers " + ex);
                valid_num = false;      // If this catch block is reached, the input
                                        // is NOT valid! Therefore, this do-while
                                        // loop repeats itself!
                input.nextLine();       // Discard current input
            }
        } while(!valid_num);

        // Return valid input
        return value;
    }
}
