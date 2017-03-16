// TREE \\
public class RedBlackTree<AnyType extends Comparable<? super AnyType>> {
    // NODE \\
    private static class RedBlackNode<AnyType> {

        // Defines variables
        AnyType element;                // The data in the node
        RedBlackNode<AnyType> left;     // Left child
        RedBlackNode<AnyType> right;    // Right child
        boolean isRed;                  // Checks for color
                                        // Red = True
                                        // Black = False

        // Node Constructors
        RedBlackNode(AnyType theElement) {this(theElement, null, null);}
        RedBlackNode(AnyType theElement, RedBlackNode<AnyType> lt, RedBlackNode<AnyType> rt) {
            element = theElement;
            left = lt;
            right = rt;
            isRed = RedBlackTree.BLACK;
        }
    }

    // Defines variables
    private RedBlackNode<AnyType> header;
    private RedBlackNode<AnyType> nullNode;

    private static final boolean BLACK = false;     // BLACK is false
    private static final boolean RED = true;        // RED is true

    // Used in insert routine and its helpers
    private RedBlackNode<AnyType> current;
    private RedBlackNode<AnyType> parent;
    private RedBlackNode<AnyType> grand;
    private RedBlackNode<AnyType> great;

    // Tree Constructor
    // Assigns null values to left and right children
    // as well as headers.
    RedBlackTree() {
        nullNode = new RedBlackNode<>(null);
        nullNode.left = nullNode.right = nullNode;
        header = new RedBlackNode<>(null);
        header.left = header.right = nullNode;
    }

    // Empties the RBTree
    public void makeEmpty() {
        header.right = nullNode;
    }

    // Checks to see if the tree is empty
    private boolean isEmpty() {
        return header.right == nullNode;
    }

    // Compares the current item with the element
    private int compare(AnyType item, RedBlackNode<AnyType> t) {
        if (t == header) return 1;
        else return item.compareTo(t.element);
    }

    /****************************************
     * Set up the public method for INSERTION
     * Inserts an element and node into the
     * RBTree.
     ***************************************/
    void insert(AnyType item) {
        current = parent = grand = header;
        nullNode.element = item;

        // Go through the tree until an
        // available is found
        while (compare(item, current) != 0) {
            great = grand;
            grand = parent;
            parent = current;
            current = compare(item, current) < 0 ?
                    current.left : current.right;

            // Check if two red children; fix if so
            if (current.left.isRed == RED && current.right.isRed == RED)
                handleReorient(item);
        }

        // Insertion fails if the
        // element is already in the tree
        if (current != nullNode)
            return;

        // Once an available spot is found,
        // create a new node in that spot
        current = new RedBlackNode<>(item, nullNode, nullNode);

        // Attach to parent
        if (compare(item, parent) < 0)
            parent.left = current;
        else
            parent.right = current;

        // Assign red or black to it
        handleReorient(item);
    }

    /*********************************************
     * Set up the public method for PRINT_TREE
     * Prints the elements of the tree in a sorted
     * order (In order Traversal)
     * ******************************************/
    void print_tree() {
        if (isEmpty())
            System.out.println("Empty tree");
        else
            print_tree(header.right);
    }

    // Implements the private method for PRINT_TREE
    private void print_tree(RedBlackNode<AnyType> t) {
        if (t != nullNode) {
            print_tree(t.left);
            if (t.isRed)                // Marks the red node
                System.out.print("*");  // with *
            System.out.print(t.element);
            print_tree(t.right);
        }
    }

    /************************************
     * Set up the public method for REMOVE
     * Removes the node from the RBTree
     ***********************************/
    public void remove(AnyType x) {throw new UnsupportedOperationException();}

    // Finds the minimum of the RBTree
    public AnyType findMin() {
        if (isEmpty())
            return null;

        RedBlackNode<AnyType> itr = header.right;

        // Searches for the leftmost element
        while (itr.left != nullNode)
            itr = itr.left;

        // Return the minimum
        return itr.element;
    }

    // Finds the maximum of the RBTree
    public AnyType findMax() {
        if (isEmpty())
            return null;

        RedBlackNode<AnyType> itr = header.right;

        // Searches for the rightmost element
        while (itr.right != nullNode)
            itr = itr.right;

        // Returns the maximum
        return itr.element;
    }

    /***************************************
     * Set up the public method for CONTAINS
     * Searches for the element by
     * traversing down the tree.
     **************************************/
    boolean contains(AnyType x) {
        nullNode.element = x;
        current = header.right;

        // Traverses down the tree until there is a match
        // Endless for loop
        for (; ; ) {
            if (x.compareTo(current.element) < 0)
                current = current.left;
            else if (x.compareTo(current.element) > 0)
                current = current.right;
            else
                return current != nullNode;
        }
    }

    // Recolors the nodes
    private void handleReorient(AnyType item) {
        // Do the isRed flip
        current.isRed = RED;
        current.left.isRed = BLACK;
        current.right.isRed = BLACK;

        if (parent.isRed == RED)   // Have to rotate
        {
            grand.isRed = RED;
            if ((compare(item, grand) < 0) !=
                    (compare(item, parent) < 0))
                parent = rotate(item, grand);  // Double rotation
            current = rotate(item, great);
            current.isRed = BLACK;
        }
        header.right.isRed = BLACK; // Make root black
    }

    // Performs the four rotations: LL, RR, LR, & RL
    private RedBlackNode<AnyType> rotate(AnyType item, RedBlackNode<AnyType> parent) {
        if (compare(item, parent) < 0)
            return parent.left = compare(item, parent.left) < 0 ?
                    rotateWithLeftChild(parent.left) :  // LL
                    rotateWithRightChild(parent.left);  // LR
        else
            return parent.right = compare(item, parent.right) < 0 ?
                    rotateWithLeftChild(parent.right) :  // RL
                    rotateWithRightChild(parent.right);  // RR
    }

    // Rotate with the left child
    private RedBlackNode<AnyType> rotateWithLeftChild(RedBlackNode<AnyType> k2) {
        RedBlackNode<AnyType> k1 = k2.left;
        k2.left = k1.right;
        k1.right = k2;
        return k1;
    }

    // Rotate with the right child
    private RedBlackNode<AnyType> rotateWithRightChild(RedBlackNode<AnyType> k1) {
        RedBlackNode<AnyType> k2 = k1.right;
        k1.right = k2.left;
        k2.left = k1;
        return k2;
    }
}
