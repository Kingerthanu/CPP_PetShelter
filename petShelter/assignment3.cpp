// Benjamin R Spitzauer
// assignment3.cpp
// 2/11/2023

/*

 Purpose: A functioning Binary Search Tree which contains most functions
 expressed in its ADT. Allowing for balance checks, size checks on levels,
 as well as on the whole tree. It also has removal, insertion, and search
 of animal pets contained by each node. It has in-order, post-order, and
 pre-order traversals as well and can find its parent. The main focus
 of this assignment is to display firm knowledge of the data type
 and its interface and how it can be implemented and how its invariants
 associated with its data type are handled in varying functions. This
 assignment also teaches about public interfaces to private member-
 tampering functions.

*/

#include "ShelterBST.h"
#include <random>


/*

  Pre-Condition: None.
  Post-Condition: Does unit tests which have static outcomes in order
  to check quality of functions and if they are working correctly. This
  uses a alphabetically-aligned Binary Tree and works to test how 
  traversals behave, memory allocation, and deallocation as well as reads
  and writes into the Binary Tree. Each should give exactly what is stated
  in the prompts, if not then function is faulty.

*/
void testInvariants()
{

  ShelterBST tree;

  tree.insertPet("Fampa", 14);
  tree.insertPet("Dampa", 12);
  tree.insertPet("Bampa", 4);
  tree.insertPet("Aampa", 1);
  tree.insertPet("Campa", 2);
  tree.insertPet("Eampa", 15);
  //tree.insertPet("Gampa", 19); // <-- Direct root success test
  tree.insertPet("Kampa", 24);
  tree.insertPet("Iampa", 8);
  tree.insertPet("Hampa", 9);
  tree.insertPet("Jampa", 11);
  tree.insertPet("Lampa", 13);

  
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  cout << "\n\nTESTING SEARCH: \n\n";

  cout << "Searching for pet with name Fampa (Successful; Fampa): \n";
  tree.searchPet("Fampa");

  cout << "Searching for pet with name Dampa (Successful; Dampa): \n";
  tree.searchPet("Dampa");

  cout << "Searching for pet with name Jampa (Successful; Jampa): \n";
  tree.searchPet("Jampa");

  cout << "Searching for pet with name Beerus (Non-Successful): \n";
  tree.searchPet("Beerus");

  cout << "DONE TESTING SEARCH \n\n\n";

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  cout << "\n\nTESTING PARENT SEARCH: \n\n";

  // Show order
  tree.preorderDisplay();

  cout << "\nSearching Parent of Eampa (Successful; Dampa): \n";
  tree.findParentDisplay("Eampa");

  cout << "\nSearching Parent of Dampa (Successful; Fampa): \n";
  tree.findParentDisplay("Dampa");

  cout << "\nSearching Parent of Fampa (Non-Successful; null): \n";
  tree.findParentDisplay("Fampa");


  cout << "\n\nDONE TESTING PARENT SEARCH \n\n\n";

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  cout << "\n\nTESTING REMOVALS: \n\n";

  std::cout << "Before removal: ";
  tree.inorderDisplay();

  std::cout << "\nRemoving left internal node.\n";
  tree.removePet("Bampa");

  std::cout << "\nAfter removal: ";
  tree.inorderDisplay();

  std::cout << "\nRemoving left internal node.\n";

  tree.removePet("Campa");

  std::cout << "\nRemoving leaf node.\n";

  tree.removePet("Aampa");

  

  std::cout << "\nAfter removal: ";
  tree.inorderDisplay();

  // Re-add
  tree.insertPet("Bampa", 4);
  tree.insertPet("Aampa", 1);
  tree.insertPet("Campa", 2);

  std::cout << "\nAfter re-insertion: ";
  tree.inorderDisplay();

  cout << "\n\nDONE TESTING REMOVALS \n\n\n";

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\n\nTESTING BALANCE: \n\n";


  std::cout << "(Should be balanced) \n";
  tree.checkBalance();

  std::cout << "Removing Lampa (imbalanced tree (1 - -1) subtree heights)\n";
  tree.removePet("Lampa");

  tree.checkBalance();

  tree.insertPet("Lampa", 13); // Re-Add


  std::cout << "\nDONE TESTING BALANCE \n\n\n";


  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nDISPLAYING TRAVERSAL TYPES: \n\n";

  // inorder display
  tree.inorderDisplay();   

  // preorder display 
  tree.preorderDisplay();   

  // postorder display 
  tree.postorderDisplay();  
 
  std::cout << "\n\nDONE DISPLAYING TRAVERSAL TYPES.\n\n\n";


  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nRemove all leafs (Aampa, Campa, Eampa, Hampa, Jampa, Lampa)"
  << "...\n\n";
  
  tree.removePet("Aampa");
  tree.removePet("Campa");
  tree.removePet("Eampa");
  tree.removePet("Hampa");
  tree.removePet("Jampa");
  tree.removePet("Lampa");

  std::cout << "\nDone removing all leafs.\n\n\n";
  
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nAttempt to add new pet with same name...\n\n";
  tree.insertPet("Fampa", 14);
  tree.insertPet("Dampa", 12);
  tree.insertPet("Bampa", 4);
  std::cout << "\nDone Attempting to add new pet with same name.\n\n\n";

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nDISPLAYING TRAVERSAL TYPES: \n\n";

  // inorder display
  tree.inorderDisplay();   

  // preorder display 
  tree.preorderDisplay();   

  // postorder display 
  tree.postorderDisplay();  
 
  std::cout << "\n\nDONE DISPLAYING TRAVERSAL TYPES.\n\n\n";


  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\n\nTESTING BALANCE: \n\n";


  std::cout << "Should be balanced: \n";
  tree.checkBalance();

  std::cout << "Removing Bampa and add Jampa (imbalanced tree (1 - -1)"
  << " subtree heights)\n";

  tree.removePet("Bampa");
  tree.insertPet("Jampa", 11); 

  tree.checkBalance();

  // Re-Add
  tree.insertPet("Bampa", 4); 
  tree.removePet("Jampa"); // Remove

  std::cout << "\nDONE TESTING BALANCE \n\n\n";


  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  cout << "\nGeneral Test of Each Function: \n\n";

  cout << "(Should return 2)\n";
  tree.getHeight();

  cout << "\n(Should return 5)\n";
  tree.getSize();

  cout << "\n(Should remove)\n";
  tree.removePet("Bampa");
  tree.insertPet("Bampa", 4);

  cout << "\n(Should return 2)\n";
  tree.getCountNodesLevel(1);

  cout << "\n(Should return none)\n";
  tree.getCountNodesLevel(3);

  tree.insertPet("Eampa", 15); // Add new pet to level 2

  cout << "\n(Should return 3)\n";
  tree.getCountNodesLevel(2);

  cout << "\n(Should remove)\n";
  tree.removePet("Eampa");

  cout << "\n(Shouldn't remove)\n";
  tree.removePet("Eampa");

  cout << "\n(Should return 2)\n";
  tree.getCountNodesLevel(2);

  cout << "\n(Should return true)";
  tree.checkBalance();

  tree.destroyTree();

  cout << "\nDONE WITH UNIT TESTING.\n\n";

}


/*

  Pre-Condition: None.
  Post-Condition: Calls main functions of ShelterBST in order to make sure
  it behaves correctly when empty, or only with one element. Shouldn't
  throw any errors from accession of memory not given to itself.

*/
void testEmpty()
{

  ShelterBST tree;

  cout << "\nGeneral Test of Each Function: \n\n";

  cout << "(Should return True)\n";
  tree.checkBalance();
  
  cout << "(Should return -1)\n";
  tree.getHeight();

  cout << "\n(Should return 0)\n";
  tree.getSize();

  cout << "\n(Shouldn't remove)\n";
  tree.removePet("Fampa");

  cout << "\n(Should return None)\n";
  tree.getCountNodesLevel(1);

  cout << "\n(Should return None)\n";
  tree.getCountNodesLevel(3);

  cout << "\nAdded single node (Eampa).\n";
  tree.insertPet("Eampa", 14); // Add new pet to level 2

  cout << "\n(Should return only Eampa).\n";
  tree.inorderDisplay();

  cout << "\n(Should return None)\n";
  tree.getCountNodesLevel(2);

  cout << "\n(Should remove once; 4 declarations of not in shelter)\n";
  tree.removePet("Eampa");
  tree.removePet("Eampa");
  tree.removePet("Eampa");
  tree.removePet("Eampa");
  tree.removePet("Eampa");

  cout << "\n(Shouldn't remove)\n";
  tree.removePet("Eampa");

  tree.inorderDisplay();

  tree.getHeight();

  cout << "\n(Should return None)\n";
  tree.getCountNodesLevel(2);

  cout << "\n(Should return true)";
  tree.checkBalance();

  tree.getSize();

  tree.destroyTree();

  cout << "\nDONE WITH EMPTY TESTING.\n\n";

}

/*

  Pre-Condition: None.
  Post-Condition: Does unit tests which have dynamic outcomes in order
  to check quality of functions and if they are working correctly. This
  uses a alphabetically-aligned Binary Tree and works to test how 
  traversals behave, memory allocation, and deallocation as well as reads
  and writes into the Binary Tree. This should reinact a user which is
  unpredictable in their combination of calls to the interface.

*/
void randTests()
{

  std::random_device rand;   // Making seeded gen
  std::mt19937 seed(rand()); // Seeding with quicker gen with seed
  std::uniform_int_distribution<int> randDegree(1, 14); // Range of values

  ShelterBST* shelter = new ShelterBST();

  // Test tree
  shelter->insertPet("Fampa", 14);
  shelter->insertPet("Dampa", 12);
  shelter->insertPet("Bampa", 4);
  shelter->insertPet("Aampa", 1);
  shelter->insertPet("Campa", 2);
  shelter->insertPet("Eampa", 15);
  shelter->insertPet("Gampa", 19); 
  shelter->insertPet("Kampa", 24);
  shelter->insertPet("Iampa", 8);
  shelter->insertPet("Hampa", 9);
  shelter->insertPet("Jampa", 11);
  shelter->insertPet("Lampa", 13);

  for(int i = 0; i < 100; i++){

    cout << '\n';

    switch(randDegree(seed)){

      /*
      
        Must have case in its own scope with variable declarations
        as switch is compiled as single scope and will jump
        declarations which are considered local.

      */
      case 1:
      { 
        cout << "INSERT CALLED\n";
        shelter->insertPet(to_string(randDegree(seed)), 444);
        break;
      }
      case 2:
      {
        cout << "SEARCH CALLED\n";
        shelter->searchPet(to_string(randDegree(seed)));
        break;
      }
      case 3:
      {
        cout << "REMOVAL CALLED\n";
        shelter->removePet(to_string(randDegree(seed)));
        break;
      }
      case 4:
      {
        cout << "PARENT CALLED\n";
        shelter->findParentDisplay(to_string(randDegree(seed)));
        break;
      }
      case 5:
      {
        cout << "SUCCESSOR CALLED\n";
        shelter->findSuccessorDisplay(to_string(randDegree(seed)));
        break;
      }
      case 6:
        cout << "LEAF COUNT CALLED\n";
        shelter->countLeafsDisplay();
        break;
      case 7:
        cout << "GET SIZE CALLED\n";
        shelter->getSize();
        break;
      case 8:
        cout << "GET HEIGHT CALLED\n";
        shelter->getHeight();
        break;
      case 9:
        cout << "CHECK BALANCE CALLED\n";
        shelter->checkBalance();
        break;
      case 10:
        cout << "COUNT AT LEVEL CALLED\n";
        shelter->getCountNodesLevel(randDegree(seed));
        break;
      case 11: 
        cout << "DESTROY CALLED\n";
        shelter->destroyTree();
        break;
      case 12:
        cout << "INORDER CALLED\n";
        shelter->inorderDisplay();
        break;
      case 13:
        cout << "PREORDER CALLED\n"; 
        shelter->preorderDisplay();
        break;
      case 14:
        cout << "POSTORDER CALLED\n";
        shelter->postorderDisplay();
        break;
    }

  }

  // Free Space
  shelter->destroyTree();
  delete shelter;

}

/*

  Pre-Condition: Shelter to be interfaced wih used in requests.
  Post-Condition: Allows user to use functions declared in ShelterBST class.
  Will return a boolean expression to be used as a flag for main-loop to tell
  loop to stop when user asks it to.

*/
bool request(ShelterBST*& shelter)
{

  int userResponse;

  std::cout << "\nWelcome to the ShelterBST (animal shelter),"
  << " What would you like to do?\n"
  << "1. Insert a Pet\n"
  << "2. Search a Pet\n"
  << "3. Remove a Node\n"
  << "4. Find Parent of Node\n"
  << "5. Find Successor of Node\n"
  << "6. Count Leaf Nodes\n"
  << "7. Get BST Size\n"
  << "8. Get BST Height\n"
  << "9. Check if Balanced\n"
  << "10. Get Amount of Nodes at Level in BST\n"
  << "11. Destroy BST\n"
  << "12. In-Order Traverse\n"
  << "13. Pre-Order Traverse\n"
  << "14. Post-Order Traverse\n"
  << "15. Test Invariants\n"
  << "16. Test Empty\n"
  << "17. Test Random\n"
  << "18. Exit\n"
  << "Reponse (1-18): ";

  std::cin >> userResponse;

  switch(userResponse){

    /*
    
      Must have case in its own scope with variable declarations
      as switch is compiled as single scope and will jump
      declarations which are considered local.

    */
    case 1:
    { 
      std::string petsName;
      std::cout << "Whats the name of the Pet and Age? ";
      std::cin >> petsName >> userResponse;
      shelter->insertPet(petsName, userResponse);
      break;
    }
    case 2:
    {
      std::string petsName;
      std::cout << "Whats the name of the Pet? ";
      std::cin >> petsName;
      shelter->searchPet(petsName);
      break;
    }
    case 3:
    {
      std::string petsName;
      std::cout << "What Pet to remove from BST? ";
      std::cin >> petsName;
      shelter->removePet(petsName);
      break;
    }
    case 4:
    {
      std::string petsName;
      std::cout << "Pet of animal to find parent of in BST? ";
      std::cin >> petsName;
      shelter->findParentDisplay(petsName);
      break;
    }
    case 5:
    {
      std::string petsName;
      std::cout << "What Pet to find successor of in BST? ";
      std::cin >> petsName;
      shelter->findSuccessorDisplay(petsName);
      break;
    }
    case 6:
      shelter->countLeafsDisplay();
      break;
    case 7:
      shelter->getSize();
      break;
    case 8:
      shelter->getHeight();
      break;
    case 9:
      shelter->checkBalance();
      break;
    case 10:
      cout << "What level do you want to count amount of nodes at? ";
      cin >> userResponse;
      shelter->getCountNodesLevel(userResponse);
      break;
    case 11:
      shelter->destroyTree();
      break;
    case 12:
      shelter->inorderDisplay();
      break;
    case 13:
      shelter->preorderDisplay();
      break;
    case 14:
      shelter->postorderDisplay();
      break;
    case 15:
      testInvariants();
      break;
    case 16:
      testEmpty();
      break;
    case 17:
      randTests();
      break;
    case 18:
      cout << "\n\n"; // Clear from sys prompts
      return false; // Exit
  }


  return true;
};


int main()
{

  ShelterBST* petShelter = new ShelterBST();

  bool loopFlag = true; 

  while(loopFlag){

    // Keep requesting user response until they say so
    loopFlag = request(petShelter);

  }

  // Free Space
  petShelter->destroyTree();
  delete petShelter;

}
