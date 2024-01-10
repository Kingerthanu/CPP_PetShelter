// Benjamin R Spitzauer
// ShelterBST.h

#ifndef SHELTERBST_H 
#define SHELTERBST_H

#include <string>
#include <iostream>

using namespace std;
 
class ShelterBST { 
  private:  

    /*

      Pre-Condition: Must intake a name and age for constructor
      Post-Condition: Will set toName, as well as toAge to member's variables.

    */  
    struct Pet;

    /*

      Pre-Condition: None; will always have a empty constructor.
      Post-Condition: Will initialize data members' to default value of nullptr.

    */
    struct TreeNode;


    TreeNode* root;


    // ~~~~~~~~~~~~~~Private Prototypes~~~~~~~~~~~~~~~~~~~~~

    /*

      Pre-Condition: Root of tree and pet to be added to tree.
      Post-Condition: Return TreeNode* containing new pet; or nullptr if fail.

    */
    TreeNode* insert(TreeNode * root, Pet pet);

    /*

      Pre-Condition: Root of tree to be searched and name to find.
      Post-Condition: Return TreeNode* of pet with name; else nullptr if fail.

    */
    TreeNode* search(TreeNode *root, string petName);

    /*

      Pre-Condition: Root of tree and pet to be looked for in tree
      (parent is implicit).

      Post-Condition: Return TreeNode* of pet with petName.

    */
    TreeNode* findParent(TreeNode* root, string petName,
     TreeNode* parent = nullptr);
    
    /*

      Pre-Condition: Node to find successor of.
      Post-Condition: Return TreeNode* containing in-order successor of root's
      parent.

    */
    TreeNode* findSuccessor(string petName);
    
    /*

      Pre-Condition: Take in root of tree to be traversed.
      Post-Condition: Prints each node in the order left -> middle -> right.

    */
    void inorder(TreeNode* root);

    /*

      Pre-Condition: Take in root of tree to be traversed.
      Post-Condition: Prints each node in the order middle -> left -> right.

    */
    void preorder(TreeNode* root);

    /*

      Pre-Condition: Take in root of tree to be traversed.
      Post-Condition: Prints each node in the order left -> right -> middle.

    */
    void postorder(TreeNode* root);

    /*

      Pre-Condition: Take in root of tree.
      Post-Condition: Counts each node with zero children (leafs).

    */
    int countLeafs(TreeNode* root);

    /*

      Pre-Condition: Take in root of tree.
      Post-Condition: Returns integer amount of nodes in root's tree.

    */
    int size(TreeNode* root);

    /*

      Pre-Condition: Take in root of tree.
      Post-Condition: Returns largest height expressed in root's tree.

    */
    int countHeight(TreeNode* root);

    /*

      Pre-Condition: Take in root of tree.
      Post-Condition: Returns true if all left, and right subtrees differ at 
      max by 1.

    */
    bool getBalance(TreeNode* root);

    /*

      Pre-Condition: Take in root of tree.
      Post-Condition: Deletes pet with petName in binary tree and reconstructs
      root's tree to uphold Binary Tree definition. Return removed nodes spot;
      else if removal brings a empty tree, return nullptr to symbolize a now
      empty tree.

    */
    TreeNode* remove(string petName);

    /*

      Pre-Condition: Take in root of tree.
      Post-Condition: Deletes every TreeNode; going from leafs to root.

    */
    TreeNode* destroy(TreeNode* root);

    /*

      Pre-Condition: Take in root of tree, and stage to count.
      Post-Condition: Counts amount of TreeNodes at that given stage.

    */
    int countNodesLevel(TreeNode* root, int stage);


    // ~~~~~~~~~~~~~~~~~END Prototypes~~~~~~~~~~~~~~~~~~~~~

 
  public: 

    /*

      Pre-Condition: None.
      Post-Condition: Initializes root member to empty.

    */
    ShelterBST();

    /*

      Pre-Condition: Take in name and age of pet to be added to tree.
      Post-Condition: Add pet to root's tree.

    */
    void insertPet(string name, int age);

    /*

      Pre-Condition: Pet name of animal to find parent of.
      Post-Condition: Display result of findParent for user.

    */
    void findParentDisplay(string petName);

    /*

      Pre-Condition: Pet name of animal to find successor of.
      Post-Condition: Display successor of pet with petName for user.

    */
    void findSuccessorDisplay(string petName);

    /*

      Pre-Condition: None.
      Post-Condition: Display amount of leafs in this->roots tree for user.

    */
    void countLeafsDisplay();

    /*

      Pre-Condition: None.
      Post-Condition: Display amount of nodes in this->roots tree for user.

    */
    void getSize();

    /*

      Pre-Condition: None.
      Post-Condition: Display height of this->roots tree for user.

    */
    void getHeight();

    /*

      Pre-Condition: None.
      Post-Condition: Display the balance of this->roots tree for user.

    */
    void checkBalance();


    /*

      Pre-Condition: Level of BST to count Nodes at.
      Post-Condition: Display the amount of TreeNodes at that given level.

    */
    void getCountNodesLevel(int toStage);

    /*

      Pre-Condition: Name of pet to be removed from root's tree.
      Post-Condition: Remove petName from root's tree.

    */
    void removePet(string petName);

    /*

      Pre-Condition: None.
      Post-Condition: Call destroy for user.

    */
    void destroyTree();

    /*

      Pre-Condition: Take in name of pet to be found.
      Post-Condition: Prints if pet was able to be found in tree, and its age.

    */
    void searchPet(string name);

    /*

      Pre-Condition: None.
      Post-Condition: Display inorder traversal for user.

    */
    void inorderDisplay();

    /*

      Pre-Condition: None.
      Post-Condition: Display preorder traversal for user.

    */
    void preorderDisplay();

    /*

      Pre-Condition: None.
      Post-Condition: Display postorder traversal for user.

    */
    void postorderDisplay();

    /*

      Pre-Condition: None.
      Post-Condition: Does unit tests which have static outcomes in order
      to check quality of functions and if they are working correctly. This
      uses a alphabetically-aligned Binary Tree and works to test how 
      traversals behave, memory allocation, and deallocation as well as reads
      and writes into the Binary Tree. Each should give exactly what is stated
      in the prompts, if not then function is faulty.

    */
    void testInvariants();

    /*

      Pre-Condition: None.
      Post-Condition: Calls main functions of ShelterBST in order to make sure
      it behaves correctly when empty, or only with one element. Shouldn't
      throw any errors from accession of memory not given to itself.

    */
    void testEmpty();



}; 

#endif 