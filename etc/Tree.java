// Simple code for a basic int-only binary tree
// Need to add, remove 
// Adapted from https://www.baeldung.com/java-binary-tree
class Tree {
    class Node {
        private int data;
        private Node left, right;
        Node(int data) {
            this.data = data;
            right = null; 
            left = null;
        }
    }
    private Node rootNode; 
    public Tree(int rootData) {
        rootNode = new Node(rootData); 
        rootNode.data = rootData;
    }

    private Node add(Node current, int data) {
        if (current == null) {
            return new Node(data);
        }
        if (data < current.data) {
            current.left = add(current.left, data);
        }
        else if (data > current.data) {
            current.right = add(current.right, data);
        }
        else {
            return current;
        }
        return current;
    }

    public void addNode(int value) {
        rootNode = add(rootNode, value);
    }

    public Node delete(Node current, int data) {
        if (current == null) {
            return null; 
        }

        if (data == current.data) {
            if (current.left == null && current.right == null) {
                return null;
            }
            if (current.right == null) {
                return current.left;
            }
            if (current.left == null) {
                return current.right;
            }
            else {
                int smallestValue = findSmallestValue(current.right);
                current.data = smallestValue;
                current.right = delete(current.right, smallestValue);
                return current;
            }
        }
        
        if (data < current.data) {
            current.left = delete(current.left, data);
        }
        current.right = delete(current.right, data);
        return current;
    }

    private int findSmallestValue(Node root) {
        return root.left == null ? root.data : findSmallestValue(root.left);
    }
} 