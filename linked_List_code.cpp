#include <iostream>

class Node {
public:
    int row, col, value;
    Node* next;

    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    int rows, cols;
    Node* head;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c), head(nullptr) {}

    void set(int r, int c, int v) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            std::cout << "Invalid row or column index." << std::endl;
            return;
        }

        if (v != 0) {
            Node* newNode = new Node(r, c, v);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }

    int get(int r, int c) {
        Node* current = head;
        while (current) {
            if (current->row == r && current->col == c) {
                return current->value;
            }
            current = current->next;
        }
        return 0;
    }
};

int main() {
    SparseMatrix matrix(3, 3);

    matrix.set(0, 0, 1);
    matrix.set(0, 1, 0);
    matrix.set(0, 2, 0);
    matrix.set(1, 0, 0);
    matrix.set(1, 1, 2);
    matrix.set(1, 2, 0);
    matrix.set(2, 0, 0);
    matrix.set(2, 1, 0);
    matrix.set(2, 2, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
