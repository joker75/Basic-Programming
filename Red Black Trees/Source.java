/************************************************
 * Project 4: Red-Black Trees
 * This project allows the user to store elements
 * of any type into a Red-Black Tree. The program
 * can implement the following features:
 * - Insertion
 * - Search
 * - Print Tree
 *
 * Created by:  Victor Nguyen on 3/15/2017.
 * Class:       CE 3345
 * Section:     003
 * Semester:    Spring 2017
 ***********************************************/
import java.util.*;
public class Source {
    // Defines static scanner variable
    private static Scanner input = new Scanner(System.in);

    // Main testing program
    public static void main( String [] args )
    {
        RedBlackTree<Integer> tree = new RedBlackTree<>();
        int menu_option = 0;
        boolean valid_option = true;    // Assume true

        // Introduction
        System.out.println("Red-Black Tree Test Program\n");

        // MENU SYSTEM \\
        while (menu_option != 4){
            // PART I \\
            // Prompt the user for validated input
            do{
                // INPUT VALIDATION FOR MENU ACCESS
                // TRY BLOCK
                try{
                    System.out.print(
                            "\nOperations\n" +
                            "\t1. Insert\n" +
                            "\t2. Contains\n" +
                            "\t3. Print Tree\n" +
                            "\t4. Quit\n");
                    menu_option = input.nextInt();
                    if (menu_option < 1 || menu_option > 4)
                        throw new IllegalArgumentException("Valid menu options are from 1 to 4. ");
                    else
                        valid_option = true;
                }
                // EXCEPTION HANDLING
                // CATCH BLOCK
                catch (InputMismatchException | IllegalArgumentException ex){
                    System.out.println("ERROR! Please enter a positive integer from 1 to 4 " + ex);
                    valid_option = false;   // If this catch block is reached, the input
                                            // is NOT valid! Therefore, this do-while
                                            // loop repeats itself!
                    input.nextLine();       // Discard current input
                }

                // If the input is NOT VALID, repeat this loop.
            }while(!valid_option);

            // PART II \\
            // Perform operations based on menu
            System.out.println("You have entered menu option: " + menu_option);
            switch(menu_option){
                case 1:
                    // Insert
                    tree.insert(validate());
                    System.out.println("Element inserted.\n\n");
                    break;
                case 2:
                    // Search | Contains
                    System.out.println("Is the element in this tree? " + tree.contains(validate()));
                    break;
                case 3:
                    // Print tree
                    System.out.println("Sorted order: ");
                    tree.print_tree();
                    break;
            }

            // Add some spacing for user clarity
            System.out.println();
        }

        // Conclude the program
        System.out.println("End of program. ");
    }

    /*******************************************
     * This function will validate user input. *
     ******************************************/
    private static Integer validate(){
        Integer value = 0;
        boolean valid_num = true;

        // MORE INPUT VALIDATION
        do {
            // Prompts the user + TRY BLOCK
            System.out.println("Please enter only integer numbers: ");
            try {
                value = input.nextInt();
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