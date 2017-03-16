/*******************************************
 * This Binary Search Tree class expands
 * on what the Binary Nodes can do. In
 * this BST, it can implement lazy deletion.
 ******************************************/
public class BSTree <AnyType extends Comparable<? super AnyType>>{
    // Defines variables
    private BinaryNode<AnyType> root;
    private BinaryNode <AnyType> min = null, max = null;
    private static int num_Nodes = -1, num_deletedNodes = 0; // Node counters

    // Construct the BST
    BSTree(){root = null; num_Nodes++;}

    // Checks if the tree is empty
    private boolean isEmpty( ) {return root == null;}

    // Makes the tree empty and reset all node counters
    public void makeEmpty() {root = null; num_Nodes = 0; num_deletedNodes = 0;}

    // Returns the number of nodes in the tree
    String getNodes(){
        return "\nTotal number of nodes: " + num_Nodes
                + "\nTotal number of deleted nodes: " + num_deletedNodes;
    }

    // PUBLIC AND PRIVATE METHOD SECTION \\
    /****************************************
     * Set up the public method for INSERTION
     * Inserts an element and node into the
     * BST.
     ***************************************/
    void insert (AnyType x){
        root = insert(x, root);
        num_Nodes++;            // Keep track of inserted nodes
    }

    // Implement the private method for INSERTION
    private BinaryNode<AnyType> insert(AnyType x, BinaryNode<AnyType> t){

        // Create a new node if necessary
        if (t == null)
            return new BinaryNode<>(x, null, null);

        // Comparing the element to each node of the tree
        int comparison = x.compareTo(t.element);
        if (comparison < 0)
            t.left = insert (x, t.left);        // Move down the left side
        else if (comparison > 0)
            t.right = insert (x, t.right);      // Move down the right side

        else if (comparison == 0 && !t.valid){  // If this element is marked false,
            t.valid = true;                     // mark it true now.
            num_deletedNodes--;                 // Decrement the number of deleted nodes
            num_Nodes--;                        // and normal nodes to offset the increment
                                                // back at the public method
        }

        else                    // If the element is a valid duplicate,
            num_Nodes--;        // Just decrement to offset the increment
                                // back at the public method
                                // Afterwards, ignore the duplicate

        // Continue with the rest of the program
        return t;
    }


    /**************************************
     * Set up the public method for REMOVAL
     * Removes an element by marking the
     * node's valid status to FALSE
     *************************************/
    void remove(AnyType x){root = remove (x, root);}

    // Implement the private method for REMOVAL
    private BinaryNode<AnyType> remove(AnyType x, BinaryNode <AnyType> t){

        // If item does not exist
        if (t == null)
            return null;   // Do nothing

        int comparison = x.compareTo(t.element);

        // Comparing the element to each node of the tree
        if (comparison < 0)
            t.left = remove(x, t.left);
        else if(comparison > 0)
            t.right = remove (x, t.right);
        else {                          // If the element is found,
            t.valid = false;            // just set it false
            num_deletedNodes++;         // Increment the number of deleted nodes
        }
        // Continue with the rest of the program
        return t;
    }


    /**************************************
     * Set up the public method for FINDMIN
     * Finds the minimum by updating the
     * static variable min.
     *************************************/
    AnyType findMin(){
        if (isEmpty())
            return null;

        // If the search for the minimum has
        // not been done yet, go through it.
        if (min == null)
            findMin(root);  // Search for and update the
                            // minimum node by starting
                            // at the root.

        // Return the element of that node
        return min.element;
    }

    // Implement the private method for FINDMIN
    // The primary purpose of this function is to
    // update the minimum node. This node should
    // contain the smallest element.
    // This function SHOULD return null, not the node.
    private AnyType findMin (BinaryNode <AnyType> t){

        // If the tree doesn't exist, return null
        if (t == null)
            return null;

        // If the node is valid,
        if (t.valid)
            min = t;    // Set it to the
                        // supposed minimum

        // Continue searching down the left side
        // This recursive call will end by returning null
        return findMin (t.left);
    }

    /**************************************
     * Set up the public method for FINDMAX
     * Finds the minimum by updating the
     * static variable max.
     *************************************/
    AnyType findMax(){
        if (isEmpty())
            return null;
        // If the search for the maximum has
        // not been done yet, go through it.
        if (max == null)
            findMax(root);  // Search for and update the
                            // maximum node by starting
                            // at the root.
        // Return the element of that node
        return max.element;
    }

    // Implement the private method for FINDMAX
    // The primary purpose of this function is to
    // update the maximum node. This node should
    // contain the largest element.
    // This function SHOULD return null, not the node.
    private AnyType findMax (BinaryNode <AnyType> t){

        // If the tree doesn't exist, return null
        if (t == null)
            return null;

        // If the node is valid,
        if (t.valid)
            max = t;        // Set it to the
                            // supposed maximum

        // Continue searching down the right side
        // This recursive call will end by returning null
        return findMax(t.right);
    }

    /***************************************
     * Set up the public method for CONTAINS
     * Searches for the element by
     * traversing down the tree.
     * Additionally, if there is a match,
     * the valid status has to be checked.
     * True means it exists on the tree;
     * False means it does not.
     **************************************/
    boolean contains (AnyType x){return contains(x, root);}

    // Implement the private method for CONTAINS
    private boolean contains (AnyType x, BinaryNode<AnyType>t) {
        if (t == null)
            return false;

        int comparison = x.compareTo(t.element);

        // Shift to the left
        if (comparison < 0)
            return contains(x, t.left);

        // Shift to the right
        else if (comparison > 0)
            return contains(x, t.right);

        // If the element matches and it is VALID
        else // if (comparison == 0)
            return t.valid;     // Return true or false depending
                                // on if the node's exists
    }

    /************************************************
     * Set up the public method for INORDER_TRAVERSAL
     * Prints the elements of the tree in a sorted
     * order (In order Traversal)
     * *********************************************/
    void inorder_traversal() {
        if (isEmpty())
            System.out.println("Empty Tree");
        else
            inorder_traversal(root);
    }

    // Implements the private method for INORDER_TRAVERSAL
    private void inorder_traversal(BinaryNode<AnyType> t){
        if (t != null){
            inorder_traversal(t.left);          // Start from the left side
            if (!t.valid)
                System.out.print("*");          // Signifies the deleted elements
            System.out.print(t.element + " ");  // Print elements as you go
            inorder_traversal(t.right);         // End with the right side
        }
    }

    /******************************************
     * Set up the public method for FINDHEIGHT
     * Calculates the height of the entire tree
     *****************************************/
    int findHeight(){
        if (isEmpty())
            return -1;
        else
            return findHeight(root);
    }

    // Implements the private method for FINDHEIGHT
    private int findHeight (BinaryNode<AnyType> t){
        // If the tree is null, just return -1
        // as a way of saying that the tree
        // does not exist
        if (t == null)
            return -1;

        // Calculate height by recursively calling
        // left and right subtrees
        else
            return 1 + Math.max( findHeight(t.left), findHeight(t.right) );
    }
}