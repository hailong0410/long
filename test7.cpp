#include<bits/stdc++.h>
using namespace std;
//Declare the global variables
int minimumElement;
int E=42;
/* Define a structure for node in binary tree and declare a global pointer root of type Tree_node */
struct Tree_node
{
//Data variable of node
int data;
//Two ponters of node
Tree_node *left,*right;
}*root;
/* Function to create a node of binary tree with data value as NULL */
Tree_node *createNode(){
//Create a new node Tnode
Tree_node *Tnode=new Tree_node;
//Set the left pointer as NULL
Tnode->left=NULL;
//Set the right pointer as NULL
Tnode->right=NULL;
//Set the data value as NULL
Tnode->data=NULL;
//Return the created node
return Tnode;
}
//Function to create a node of binary tree with given data value
Tree_node *createNode(int data){
//Create a new node Tnode
Tree_node *Tnode=new Tree_node;
//Set the left pointer as NULL
Tnode->left=NULL;
//Set the right pointer as NULL
Tnode->right=NULL;
//Set the data value as given data
Tnode->data=data;
//Return the created node
return Tnode;
}
//Function to create tree with given nodes in level order
void createTree(Tree_node *newNode,queue&q){
//Assign the node at front position of queue to f;
Tree_node *f=q.front();
//If the node has left and right child
if(f->left && f->right)
{
//Pop the element at front position from queue
q.pop();
//Assign next node at frond position to f
f=q.front();
}
//If f is not having the left child
if(!f->left)
//Assign the new node to the left of f
f->left=newNode;
//Otherwise if f is not having right child
else if(!f->right)
//Assign the new node to the right of f
f->right=newNode;
//Insert the new node to queue
q.push(newNode);
}
/* Function to display the nodes of the binary tree in level order */
void levelOrder(Tree_node *root){
cout<<"Elements in the tree in level order given below:"<
//Create a queue q to insert nodes of binary tree
queueq;
//If tree is not empty
if(root){
//Push the root node of the tree into queue
q.push(root);
//While the queue is not empty
while(!q.empty()){
//Assign the node at front position to d
Tree_node *d =q.front();
//Pop the element from the queue
q.pop();
/* Display the data value of node d which is removed from queue */
cout<data<<" "<
//If node d have left child
if(d->left)
//Push the left child to queue
q.push(d->left);
//If node d have right child
if(d->right)
//Push the right child to queue
q.push(d->right);
}
}
}
/* Function to set the minimum of left and right child value to node */
int setMinimumToNode(Tree_node *Tnode) {
//If the node is leaf node
if (Tnode->left== NULL ){
//Return the data value of leaf node
return Tnode->data;
}
//If the node have left and right child
if (Tnode->left!= NULL && Tnode->right != NULL) {
//Assign data of left child of node to x
int x=setMinimumToNode(Tnode->left);
//Assign data of right child of node to y
int y=setMinimumToNode(Tnode->right);
//If mimimum data value is for left child
if(x
//Assign data value of left child to node
Tnode->data=Tnode->left->data;
/* Otherwise if minimum data value is for right child */
else
//Assign data value of right child to node
Tnode->data=Tnode->right->data;
}
}
//Function to replace the minumum value by E
void setMinimumWithE(Tree_node *Tnode)
{
//If tree is empty
if(Tnode==NULL)
return;
//If the data of node is minimum value
if(Tnode->data == minimumElement)
{
//Replace the node data value by E
Tnode->data=E;
}
/* Call recursive function setMinimumWithE() with left child as parameter */
setMinimumWithE(Tnode->left);
/* Call recursive function setMinimumWithE() with right child as parameter */
setMinimumWithE(Tnode->right);
}
/* Function to set the minimum value with E untill the root node data value is E */
void replaceMinimum()
{
//Loop untill the root node data value is E
while(root->data!=E)
{
/* Place the data value of root to variable minimumElement */
minimumElement=root->data;
/* Call the function setMinimumWithE() with root as parameter */
setMinimumWithE(root);
/* Call the function setMinimumToNode() with root as parameter to set the node data value with minimum data value of
children */
setMinimumToNode(root);
cout<<"************************"<
/* Call the function levelOrder() with root as parameter to display the nodes in level order */
levelOrder(root);
}
}
// Main function
int main(){
// Decalre variables
double h;
int j=0;
double num_array;
int a[5];
double num_nodes,leaf_index;
cout<<"Enter number of elements that have to be inserted in to the array"<
/*Input number of elements that have to be inserted into the array */
cin>>num_array;
cout<<"Enter the elements"<
//Input the elements into the array
for(int i=0;i
cin>>a[i];
/* Create a node with null value and assign it to the root */
root=createNode();
//Create a queue q to insert nodes of the binary tree
queueq;
//Push the root node to queue
q.push(root);
//Find the height of the tree
h=ceil(log(num_array) / log(2.0) )+1;
//Find number of nodes in the tree
num_nodes=pow(2,h)-1;
//Find the starting index of the tree
leaf_index=pow(2,h-1)-1;
//Insert nodes into the tree
for(double i=1;i<=num_nodes-1;i++)
{
/* If the index of i is equal or greater than that of staring index of leaf node */
if(i>=leaf_index)
{
/* If all the elements of the array is not inserted */
if(j
{
/* Create a node with data value as element at jth index of array and pass it to function createTree() */
createTree(createNode(a[j]),q);
//Increment index of array
j++;
}
/* Otherwise if all the elements of the array are inserted */
else
{
/* Create node with data value E and pass it to function createTree() */
createTree(createNode(E),q);
}
}
/* If the index of i is less than staring index of leaf node */
else
{
/* Create node with data value as null and pass it to function createTree()*/
createTree(createNode(),q);
}
}
//Display the nodes of the tree in level order
levelOrder(root);
/* Call function setMinimumToNode() with root node as parameter */
setMinimumToNode(root);
cout<<"************************"<
//Display the nodes of the tree in level order
levelOrder(root);
//Call function replaceMinimum()
replaceMinimum();
// Pause the output console
system("pause");
return 0;
}