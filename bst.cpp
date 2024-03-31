#include <iostream>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this -> data = data;
        this -> right = nullptr;
        this -> left = nullptr;
    }

    void insert (int data){
        if(this -> data == 0){
            this -> data = data;

        } else {
            if (data < this -> data){
                if (left == 0){
                    left = new node(data);
                } else {
                    left -> insert(data);
                }

            } else if (data > this -> data){
                if (right == 0){
                    right = new node(data);
                } else {
                    right -> insert(data);
                }
            }
        }
    }

    void preorder(){
        cout << data << " ";
        if (left != nullptr){
            left -> preorder();
        } 
        if (right != nullptr){
            right -> preorder();
        } 
    }

    void inorder(){
        if (left != nullptr){
            left -> inorder();
        } 
        cout << data << " ";
        if (right != nullptr){
            right -> inorder();
        } 
    }

    void postorder(){
        if (left != nullptr){
            left -> postorder();
        } 
        if (right != nullptr){
            right -> postorder();
        } 
        cout << data << " ";
    }
};

int main(){
    cout << "binary tree" << endl;
    node* root = new node(0);
    int nums[] = {149, 143, 135, 152, 140, 12, 115, 136, 132, 158,126, 137, 157, 122, 125, 139, 16, 18, 118, 124, 19, 116, 119, 133, 121, 14, 155,162, 113, 17, 161, 174, 1100, 167, 199, 182, 177, 170, 172, 192, 186, 148, 138,131, 111};

    for(int num:nums){
        root -> insert(num);
    }

    cout << "Preorder     :";
    root -> preorder();

    cout << "\n\nInorder      :";
    root -> inorder();

    cout << "\n\nPostorder    :";
    root -> postorder();
    delete root;
    return 0;
}
