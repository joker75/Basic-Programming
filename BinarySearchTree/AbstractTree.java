/*************************************
 * This abstract class implements only
 * the getSize function. However,
 * three traversal functions will be
 * overridden in the BST class.
 *
 * Created by Victor on 11/30/2016.
 ************************************/
public abstract class AbstractTree<E>
    implements Tree<E>{

    // Inorder traversal
    // left child, root, right child
    @Override
    public void inorder(){}

    // Postorder traversal
    // left child, right child, root
    @Override
    public void postorder(){}

    // Preorder traversal
    // root, left child, right child
    @Override
    public void preorder(){}

    // Returns true if BST is empty
    @Override
    public boolean isEmpty(){return getSize() == 0;}
}
