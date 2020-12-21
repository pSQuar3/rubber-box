void func(Node *t, int f)
{

}


Inorder:

2 4 5 6 1 3

Postorder:

6 5 4 2 3 1

start

1. initialise a dequeue
2. print the root
3. check if there is a left root. print it if there is
4. check if there is a right root. print it if it is there

5. function(root->left,1,0)
6. function(root->right,0,1)


procedure function(Node n,int l,int r)
    
    if(n == NULL) then exit the function
    1. function(n->left,l--,r)
    2. if l == r and left node exists then  print left node
    3. if l == r and right node exists then print right node;
    4. function(n->right, l,r++);
//    if(l > r)
//        print n;
//
//    2. function(n->right,l++,r);

end
