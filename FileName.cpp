#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// Định nghĩa node trong cây biểu thức
class Node {
public:
    string value; // Giá trị của node (toán tử hoặc toán hạng)
    Node* left;   // Con trỏ tới node trái
    Node* right;  // Con trỏ tới node phải

    // Khởi tạo node
    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};

// Cài đặt cây biểu thức
class ExpressionTree {
public:
    Node* root;  // Gốc của cây biểu thức

    // Hàm khởi tạo cây
    ExpressionTree() : root(nullptr) {}

    // Kiểm tra cây rỗng
    bool isEmpty() {
        return root == nullptr;
    }

    // Hàm cài đặt cây biểu thức
    void buildTree() {
        // Xây dựng cây cho biểu thức: (a*5 - b*c^(6/d)) + (h-f)*e^(1/2)
        root = new Node("+");

        // Cây con bên trái: (a*5 - b*c^(6/d))
        Node* left_subtree = new Node("-");
        root->left = left_subtree;
        left_subtree->left = new Node("*");
        left_subtree->left->left = new Node("a");
        left_subtree->left->right = new Node("5");

        left_subtree->right = new Node("*");
        left_subtree->right->left = new Node("b");
        left_subtree->right->right = new Node("^");
        left_subtree->right->right->left = new Node("c");
        left_subtree->right->right->right = new Node("/");
        left_subtree->right->right->right->left = new Node("6");
        left_subtree->right->right->right->right = new Node("d");

        // Cây con bên phải: (h-f)*e^(1/2)
        Node* right_subtree = new Node("*");
        root->right = right_subtree;
        right_subtree->left = new Node("-");
        right_subtree->left->left = new Node("h");
        right_subtree->left->right = new Node("f");

        right_subtree->right = new Node("^");
        right_subtree->right->left = new Node("e");
        right_subtree->right->right = new Node("/");
        right_subtree->right->right->left = new Node("1");
        right_subtree->right->right->right = new Node("2");
    }

    // Duyệt cây theo thứ tự trung tố (In-order)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    // Duyệt cây theo thứ tự tiền tố (Pre-order)
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Duyệt cây theo thứ tự hậu tố (Post-order)
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }

    // Hàm gọi duyệt theo trung tố từ gốc cây
    void printInorder() {
        inorder(root);
        cout << endl;
    }

    // Hàm gọi duyệt theo tiền tố từ gốc cây
    void printPreorder() {
        preorder(root);
        cout << endl;
    }

    // Hàm gọi duyệt theo hậu tố từ gốc cây
    void printPostorder() {
        postorder(root);
        cout << endl;
    }
};

// Hàm main để kiểm thử chương trình
int main() {
    // Khởi tạo cây biểu thức
    ExpressionTree tree;

    // Xây dựng cây cho biểu thức
    tree.buildTree();

    // In các biểu thức theo các thứ tự khác nhau
    cout << "Inorder (Trung Tố): ";
    tree.printInorder();   // In ra biểu thức theo dạng Trung Tố

    cout << "Preorder (Tiền Tố): ";
    tree.printPreorder();  // In ra biểu thức theo dạng Tiền Tố

    cout << "Postorder (Hậu Tố): ";
    tree.printPostorder(); // In ra biểu thức theo dạng Hậu Tố

    return 0;
}
