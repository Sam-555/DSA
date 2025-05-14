#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data=value;
        left=right=nullptr;
    }
};
vector<vector<int>>level_order_traversal(Node*root){
    vector<vector<int>>res;
    if(root==nullptr){ return res;}

    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for (int i=0;i<size;i++)
        {
            Node* n=q.front();
            q.pop();
            if(n->left!=nullptr) q.push(n->left);
            if(n->right!=nullptr) q.push(n->right);
            level.push_back(n->data);
        }
        res.push_back(level);
    }
   return res; 
}
void preorder(Node *node)
{
    if (node==nullptr){
        return;
    }
    std::cout<< node->data<<", ";
    preorder(node->left);
    preorder(node->right);
}
vector<int> iterative_traversal_preorder(Node *root){
    vector<int> preorder_vec;
    if(root==nullptr){ return preorder_vec;}

    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        preorder_vec.push_back(root->data);
        if(root->right!=nullptr)
        {
            st.push(root->right);
        }
        if(root->left!=nullptr){
            st.push(root->left);
        }
    }
    return preorder_vec;
}
vector<int> iterative_inorder(Node* root){
    vector<int> inorder_vec;
    if(root==nullptr) return inorder_vec;

    stack<Node*>st;
    st.push(root);
    

}
vector<int> iterative_postorder(Node* root){
    vector<int> inorder_vec;
    if(root==nullptr) return inorder_vec;

    stack<Node*>st;
    while(!st.empty())
    {

    }
    
}
void postorder(Node *node)
{
    if (node==nullptr){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    std::cout<<node->data<<", ";
}
void inorder(Node *node){
    if(node==nullptr)
    {
        return;
    }
    inorder(node->left);
    std::cout<<node->data<<" ,";
    inorder(node->right);
}
int main()
{
    struct Node *root =  new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(8);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->left=new Node(9);
    root->right->right->right=new Node(10);

    std::cout<<"preorder: ";
    preorder(root);
    std::cout<<"preorder iterative: ";
    vector<int> a=iterative_traversal_preorder(root);
    for(int i=0;i<a.size();i++)
    {
        std::cout<<a[i]<<" ,";
    }
    std::cout<<"postorder: ";
    postorder(root);
    std::cout<<"inorder: ";
    inorder(root);
    std::cout<<"Level Order traversal:";
    vector<vector<int>> b=level_order_traversal(root);
    
}