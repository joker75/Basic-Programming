/***********************************
 * This BST class defines all of the
 * methods and data fields.
 *
 * Created by Victor on 11/30/2016.
 **********************************/
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Stack;

public class BST<E extends Comparable<E>>
    extends AbstractTree<E>{
    // Defines protected variables
    private TreeNode root;
    private int size = 0;

    // Creates a default BST
    BST(){}

    // Creates a BST from an array of objects
    BST(E[] objects){
        for (int i = 0;  i <objects.length; i++){
            insert(objects[i]);
        }
    }

    // This inner class does not access any instance
    // members defined in its outer class
    static class TreeNode<E extends Comparable<E>>{
        protected E element;
        protected TreeNode<E> left;
        protected TreeNode<E> right;
        public TreeNode(E e){
            element = e;
        }
    }

    // Returns true if element is in BST
    @Override
    public boolean search(E e){
        // Defines a TreeNode variable as root
        TreeNode<E> current = root;

        while (current != null) {
            // Move to the left
            if (e.compareTo(current.element) < 0)
                current = current.left;

            // Move to the right
            else if (e.compareTo(current.element) > 0)
                current = current.right;

            // Else, element is found
            else
                return true;
        }

        // If current element does not exist,
        return false;
    }

    // Inserts element into BST
    // Returns true if inserted successfully
    @Override
    public boolean insert(E e) {
        if (root == null)
            root = createNewNode(e);    // Create a new root
        else {
            // Locate the parent node
            TreeNode<E> parent = null;
            TreeNode<E> current = root;
            while (current != null)
                if (e.compareTo(current.element) < 0) {
                    parent = current;
                    current = current.left;
                }
                else if (e.compareTo(current.element) > 0) {
                    parent = current;
                    current = current.right;
                }
                // Otherwise,
                // Duplicate node not inserted
                else
                    return false;

            // Create the new node and attach it to the parent node
            if (e.compareTo(parent.element) < 0)
                parent.left = createNewNode(e);
            else
                parent.right = createNewNode(e);
        }

        // Element inserted successfully
        size++;
        return true;
    }

    private TreeNode<E> createNewNode(E e){return new TreeNode<>(e);}

    @Override
    public void inorder() {inorder(root);}
    // Inorder Traversal
    private void inorder(TreeNode<E> root){
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.element + " ");
        inorder(root.right);
    }

    @Override
    public void postorder() {postorder(root);}
    // Postorder Traversal
    private void postorder(TreeNode<E> root) {
        if (root == null) return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.element + " ");
    }

    @Override
    public void preorder(){preorder(root);}
    // Preorder Traversal
    private void preorder (TreeNode<E> root) {
        if (root == null) return;
        System.out.print(root.element + " ");
        preorder(root.left);
        preorder(root.right);
    }

    // Gets the number of nodes in BST
    @Override
    public int getSize() {return size;}

    // Returns root of the tree
    public TreeNode getRoot(){return root;}

    // Returns node for specific element
    // Returns null if element is not in tree
    private TreeNode<E> getNode (E element){
        // Defines a TreeNode variable as root
        TreeNode<E> current = root;

        while (current != null) {
            // Move to the left
            if (element.compareTo(current.element) < 0)
                current = current.left;

                // Move to the right
            else if (element.compareTo(current.element) > 0)
                current = current.right;

                // Else, element is found
            else
                return current;
        }

        // If current element does not exist,
        return null;
    }

    // Returns true if the node for the element
    // is a leaf
    private boolean isLeaf (E element){
        if (!search(element)){  // If element is not in the tree
            return false;       // Return false
        }
        else if(getNode(element).left != null || getNode(element).right != null ){
            return false;           // If the left or right element of
                                    // this node does exist,
                                    // return false
        }
        return true;    // All else, return true
    }


    // Returns a path from the root
    // leading to the specified element
    // To store the path from leaf to root,
    // temp variables must be considered
    public ArrayList getPath (E e){
        ArrayList list = new ArrayList<>(); // Store the real paths
        Stack temp = new Stack();           // Recall stack is a LIFO (Last In First Out)
        TreeNode<E> current = root;

        // Check for leaves!
        if (!isLeaf(e))         // Ignore the nodes that have children
            return null;        // We're looking for leaves (no children)!

        // This while loop will add elements
        // from root to leaf
        while (current != null) {                       // Push the root to the bottom of stack
            temp.push(current.element);                 // Add nodes to the list
            if (e.compareTo(current.element) < 0)       // Comparisons
                current = current.left;
            else if (e.compareTo(current.element) > 0)  // Comparisons
                current = current.right;
            else
                break;
        }

        // Reverse the paths!
        while (!temp.isEmpty())     // Pop the last element
            list.add(temp.pop());   // as the first element
                                    // for the list!!
        // Return an array list of nodes
        return list;
    }


    // Deletes element from BST
    // Returns true if deleted successfully
    @Override
    public boolean delete(E e) {
        // Locate the node to be deleted and also locate
        // parent node
        TreeNode<E> parent = null;
        TreeNode<E> current = root;
        while(current!= null) {
            if (e.compareTo(current.element) < 0){
                parent = current;
                current = current.left;
            }
            else if (e.compareTo(current.element) > 0){
                parent = current;
                current = current.right;
            }
            // Otherwise, element is in the tree pointed
            // at by current
            else
                break;
        }

        // Element is not in the tree
        if (current == null)
            return false;

        // Case 1: current has no left child
        if (current.left == null) {
            // Connect parent with the right child
            // of the current node
            if (parent == null){
                root = current.right;
            }
            else{
                if (e.compareTo(current.element) < 0)
                    parent.left = current.right;
                else
                    parent.right = current.right;
            }
        }

        // Case 2: current has a left child
        // Locate the rightmost node in the
        // left subtree of the current node
        // and also its parent
        else{
            TreeNode<E> parentOfRightMost = current;
            TreeNode<E> rightMost = current.left;

            while(rightMost.right != null){
                parentOfRightMost = rightMost;
                rightMost = rightMost.right;    // Keep going to the right
            }

            // Replace the element in current
            // by the element in rightMost
            current.element = rightMost.element;

            // Eliminate rightmost node
            if (parentOfRightMost.right == rightMost)
                parentOfRightMost.right = rightMost.left;
            // SPECIAL CASE: parent of rightmost node == current
            else
                parentOfRightMost.left = rightMost.left;
        }

        // Element deleted successfully
        size--;
        return true;
    }

    @Override
    public Iterator<E> iterator() {return new InorderIterator();}

    // Inner class InorderIterator
    private class InorderIterator implements Iterator<E>{
        // Store the elements in a list
        private ArrayList<E> list = new ArrayList <>();
        private int current = 0;

        // Traverse BST and store elements in a list
        // INORDER TRAVERSAL
        public InorderIterator(){inorder();}
        private void inorder(){inorder(root);}
        private void inorder(TreeNode<E> root){
            if (root == null) return;
            inorder (root.left);
            list.add(root.element);
            inorder(root.right);
        }

        // Checks if next element exists
        @Override
        public boolean hasNext() {
            // Checks if current element is within
            // range of the list size
            if (current < list.size())
                return true;

            // Otherwise,
            return false;
        }

        // Gets current element
        // Then moves to the next
        // element
        @Override
        public E next() {return list.get(current++);}

        // Removes current element
        @Override
        public void remove() {
            delete(list.get(current));  // Delete current element
            list.clear();               // Clear the list
            inorder();                  // Rebuild the list
        }
    }

    // Removes all elements from the tree
    public void clear(){
        root = null;
        size = 0;
    }
}
