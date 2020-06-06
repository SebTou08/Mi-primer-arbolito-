#include "Tree.h"

int main()
{
    srand(time(NULL));
    BinaryTree<Person*>* tree = new BinaryTree<Person*>();
    Person* p1 = new Person();
    Person* p2 = new Person();
    Person* p3 = new Person();
    Person* p4 = new Person();
    Person* p5 = new Person(19,"Sebastian Toulier", "Ingenieria de Software");
    auto AddAll = [tree](Person* p) {return (p->getage() > 19) ?  true :  false; };
    tree->Add(p1 , AddAll);
    tree->Add(p2, AddAll);
    tree->Add(p3, AddAll);
    tree->Add(p4, AddAll);
    tree->Add(p5, AddAll);

    auto PrintAll = [](Person* p) {cout <<"     "<<  p->getage() << endl; };
    //tree->InOrder(PrintAll);
    tree->impri(PrintAll);
    system("PAUSE");
    return 0;
    
}

