/**********************************
 * This tree interface sets up the
 * proper functions that will be
 * implemented in the AbstractTree
 * abstract class.
 *
 * Created by Victor on 11/30/2016.
 *********************************/
public interface Tree<E> extends Iterable <E> {
    // Public Access Modifier is redundant
    // in public interfaces

    // Returns true if element is in tree
    boolean search(E e);

    // Inserts element into BST
    // Returns true if inserted successfully
    boolean insert(E e);

    // Deletes element from BST
    // Returns true if deleted successfully
    boolean delete (E e);

    // Inorder traversal
    // left child, root, right child
    void inorder();

    // Postorder traversal
    // left child, right child, root
    void postorder();

    // Preorder traversal
    // root, left child, right child
    void preorder();

    // Gets the number of nodes in BST
    int getSize();

    // Returns true if BST is empty
    boolean isEmpty();
}
