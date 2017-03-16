/******************************
 * This class sets up the basic
 * node of every binary tree.
 *****************************/
class BinaryNode<AnyType> {

    // Defines variables
    AnyType element;            // Data of the Node
    BinaryNode<AnyType> left;   // Link to the left child
    BinaryNode<AnyType> right;  // Link to the right child
    boolean valid;              // LAZY DELETION
                                // True: it exists on the tree
                                // False: it has been removed
                                // and thus, it does not exist
                                // in the search functions

    // Constructors
    BinaryNode(AnyType element){this (element, null, null);}
    BinaryNode (AnyType element, BinaryNode <AnyType> leftTree, BinaryNode <AnyType> rightTree){
        // Assign stuff
        this.element = element;
        left = leftTree;
        right = rightTree;
        valid = true;
    }
}
