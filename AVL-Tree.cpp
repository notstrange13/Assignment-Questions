#include <iostream>
using namespace std;

// AVL Tree Node
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int val)
    {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

// Get height of a node
int getHeight(Node *n)
{
    if (!n)
        return 0;
    return n->height;
}

// Get balance factor
int getBalance(Node *n)
{
    if (!n)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Right rotate
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x; // new root
}

// Left rotate
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y; // new root
}

// Insert a key in AVL tree
Node *insert(Node *node, int key)
{
    // Normal BST insertion
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicate keys not allowed

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Case 1: Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Case 2: Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Case 3: Left Right
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Get node with minimum key
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left)
        current = current->left;
    return current;
}

// Delete a node
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return root;

    // Standard BST delete
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node found
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;

            if (!temp)
            { // No child
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp; // One child
            }
            delete temp;
        }
        else
        {
            // Two children: get inorder successor
            Node *temp = minValueNode(root->right);

            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return root;

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balance factor
    int balance = getBalance(root);

    // Balance cases
    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Traversals
void preOrder(Node *root)
{
    if (root)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of AVL tree: ";
    preOrder(root);
    cout << "\n";

    cout << "Inorder traversal of AVL tree: ";
    inOrder(root);
    cout << "\n";

    root = deleteNode(root, 40);

    cout << "After deleting 40, inorder: ";
    inOrder(root);
    cout << "\n";

    return 0;
}
