// Benjamin R Spitzauer
// ShelterBST.cpp

#include "ShelterBST.h"

ShelterBST::ShelterBST() 
{ 

  this->root = nullptr;

} 

struct ShelterBST::Pet 
{ 

  string name; 
  int age;

  Pet(string toName, int toAge)
  {

    this->name = toName;
    this->age = toAge;

  };
}; 

struct ShelterBST::TreeNode
{ 

  Pet* pet = nullptr; 
  TreeNode* left = nullptr; 
  TreeNode* right = nullptr; 

};

ShelterBST::TreeNode* ShelterBST::insert(TreeNode* root, Pet pet) 
{ 
  
  if(!root){ // If empty spot
    root = new TreeNode;
    root->pet = new Pet(pet);
    
  }
  else if(root->pet->name == pet.name){ // Found Duplicate
    
    cout << "Cannot add pet with same name, " << pet.name << ", sorry.\n";

  }
  else if(pet.name < root->pet->name){
    root->left = insert(root->left, pet);

  }
  else if(pet.name > root->pet->name){
    root->right = insert(root->right, pet);

  }

  // Pet's Node
  return root;

}

ShelterBST::TreeNode* ShelterBST::search(TreeNode* root, string petName) 
{ 

  if(!root){ // If not in tree
    return nullptr;
  }
  else if(root->pet->name == petName){ // If in
    return root;
  }
  else if(root->pet->name > petName){

    return search(root->left, petName);

  }
  else if(root->pet->name < petName){

    return search(root->right, petName);

  }
  
  return nullptr;

}

void ShelterBST::inorder(TreeNode * root) 
{ 
    
  if(!root) return;

  inorder(root->left);
  cout << root->pet->name << "  Age " << root->pet->age << " -> ";
  inorder(root->right);
  

} 

void ShelterBST::preorder(TreeNode * root) 
{ 

  if(!root) return;

  cout << root->pet->name << "  Age " << root->pet->age <<" -> ";
  preorder(root->left);
  preorder(root->right);

} 


void ShelterBST::postorder(TreeNode * root) 
{ 

  if(!root) return;

  postorder(root->left);
  postorder(root->right);
  cout << root->pet->name << "  Age " << root->pet->age << " -> ";

} 

void ShelterBST::insertPet(string name, int age)
{ 

  root = insert(root, Pet(name, age)); 

} 

void ShelterBST::searchPet(string name)
{ 

  TreeNode* result = search(root, name);
  
  cout << ((!result) ? "There is no pet with that name.\n\n" :
  ("Pets name with name " + name + " is age " + to_string(result->pet->age) 
    + "\n\n"));

} 

ShelterBST::TreeNode* ShelterBST::findParent(TreeNode* root, string petName,
 TreeNode* parent)
{
  if(!root){
    return nullptr;
  }
  else if(root->pet->name == petName){
    return parent; // Return previous level's node (parent)
  }
  else if(root->pet->name > petName){

    return findParent(root->left, petName, root);

  }
  else if(root->pet->name < petName){

    return findParent(root->right, petName, root);

  }

  return parent;

  
}

void ShelterBST::inorderDisplay()
{

  cout << "\nIn-Order Traversal: \n";
  inorder(root); 
  cout << "END\n";

} 

void ShelterBST::preorderDisplay()
{

  cout << "\nPre-Order Traversal: \n";
  preorder(root);
  cout << "END\n";

} 

void ShelterBST::postorderDisplay()
{

  cout << "\nPost-Order Traversal: \n";
  postorder(root); 
  cout << "END\n";

} 

void ShelterBST::findParentDisplay(string petName)
{

  TreeNode* parent = findParent(this->root, petName);


  if(!parent){
    cout << "No Parent for " << petName << ".\n";
    return;
  }


  cout << "Parent of " << petName << " is " 
  << parent->pet->name << " with age " << parent->pet->age << "\n";

}


ShelterBST::TreeNode* ShelterBST::findSuccessor(string petName)
{

  TreeNode* petNode = search(this->root, petName);

  if(!petNode || !petNode->right){ // If not in tree or doesn't have succ.
    return nullptr;
  }

  petNode = petNode->right; // Step into right subtree

  while(petNode->left){ // Check farthest left (least in right subtree; succ.)

    petNode = petNode->left;

  }

  return petNode;

}

void ShelterBST::findSuccessorDisplay(string petName)
{

  TreeNode* parent = search(this->root, petName);

  if(!parent){ // Node to find succ. of is not in tree
    cout << "There's no Pet with this name.\n";
    return;
  }

  TreeNode* succ = findSuccessor(petName);

  if(!succ){
    cout << "No Successor for " << petName << ".\n";
    return;
  }

  cout << "Successor of " << petName << " is " << succ->pet->name << '\n';

}

int ShelterBST::countLeafs(TreeNode* root)
{

  if(!root){
    return 0;
  }
  else if(!root->left && !root->right){ // If leaf
    return 1;

  }

  return countLeafs(root->left) + countLeafs(root->right);

}

void ShelterBST::countLeafsDisplay()
{

  cout << "There is " << countLeafs(this->root)
   << " leaf node(s) in the Shelter\n";

}

int ShelterBST::size(TreeNode* root)
{

  if(!root){
    return 0;
  }

  return (1 + size(root->left) + size(root->right));

}

void ShelterBST::getSize()
{

  cout << "\nSize of tree is " << size(this->root) << ".\n\n";

}

int ShelterBST::countHeight(TreeNode* root)
{

  if(!root){ // Empty
    return -1;
  }
  else if((!root->left && !root->right)){ // Leaf / Root
    return 0;
  }

  return max((countHeight(root->left)), (countHeight(root->right))) + 1;

}

void ShelterBST::getHeight()
{

  cout << "\nHeight of tree is " << countHeight(this->root) << "\n\n";

}

bool ShelterBST::getBalance(TreeNode* root)
{

  if(!root){
    return true; // Empty is balanced
  }

  if((abs((countHeight(root->left) - countHeight(root->right))) <= 1)
  && (getBalance(root->left) && getBalance(root->right))){
    return true;
  }

  return false; // This far, not balanced


}

void ShelterBST::checkBalance()
{

  cout << "\nIs Shelter's Tree Balanced? " 
  << ((this->getBalance(root) == 1) ? "Yes" : "No") << "\n\n";

}

int ShelterBST::countNodesLevel(TreeNode* root, int stage)
{

  if(!root){
    return 0;
  }
  else if(stage == 0){ // Is level to count
    return 1;
  }
  
  // Step down a level in each subtree
  return (countNodesLevel(root->left, stage-1) + 
  countNodesLevel(root->right, stage-1));

}

void ShelterBST::getCountNodesLevel(int toStage)
{

  if(toStage > countHeight(this->root)){
    cout << "Tree doesn't have a level there. \n";
    return;
  }

  cout << "There is " << countNodesLevel(this->root, toStage) << " nodes on level " 
  << toStage << "\n";

}

ShelterBST::TreeNode* ShelterBST::remove(string petName)
{

  TreeNode* node = search(this->root, petName); // Find node to remove
  
  if (!node){ // If not in tree
    cout << "Pet with name " << petName << " is not in the Shelter.\n";
    return nullptr;
  }
  else{

    if(!node->right && !node->left){ // If leaf

      TreeNode* parent = findParent(this->root, petName);

      if(parent){ // If not root (Has parent)
        // Prevent dangle ptr
        if(parent->left == node){ 
          parent->left = nullptr;
        }
        else{
          parent->right = nullptr; 
        }
      }
      else{ // Is root
        delete this->root->pet; // This->root not node to prevent seg. fault
        delete this->root;
        this->root = nullptr; // Set empty
        return nullptr;
      }

      delete node->pet;
      delete node;

    }
    else if(!node->right){ // Only has left child

      // Successor-priority removal.
      TreeNode* parent = findParent(this->root, petName);

      if(parent){ // Set parent to current's next
        if(parent->left == node){
          parent->left = node->left;
        }
        else{
          parent->right = node->left;
        }
      }
      else{ // Remove root, swap with child
        TreeNode* child = this->root->left;
        delete this->root->pet;
        delete this->root;
        this->root = child;
        return node;
      }

      delete node->pet;
      delete node;
      
    }
    else{ // If has two children or right

      // Successor-priority removal.
      TreeNode* succ = findSuccessor(petName);

      TreeNode* parent = findParent(this->root, succ->pet->name);

      if(node != parent){ // Get succ child and make it parent's
        parent->left = succ->right;
      }
      else{
        parent->right = succ->right;
      }

      delete node->pet;
      node->pet = succ->pet; // Swap
      delete succ;

    }

  }
  cout << petName << " was removed from the Shelter.\n";

  // Return new root
  return node;
}

void ShelterBST::removePet(string petName)
{

  // Returns removed node's address.
  remove(petName);

}

ShelterBST::TreeNode* ShelterBST::destroy(TreeNode* root)
{

  if(!root){
    return nullptr;
  }

  // Remove leafs
  destroy(root->left);
  destroy(root->right);

  // Remove root
  delete root->pet;
  delete root;

  // Return empty pointer
  return nullptr;

}

void ShelterBST::destroyTree()
{

  // Set root as empty
  root = destroy(root);

}




