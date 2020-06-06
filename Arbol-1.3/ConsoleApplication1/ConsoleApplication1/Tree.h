#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<ctime>
#include "Persona.h"
#include<stdlib.h>
#include<fstream>
#include<sstream>
using namespace std;
template<typename TypeGen>
class Node {
public:
	TypeGen data;
	Node* left;
	Node* right;
	Node(){}
	Node(TypeGen data) {
		left = right = nullptr;
		this->data = data;
	}
};

template<typename TypeGen>
class BinaryTree {
private:
	Node<TypeGen>* root;
	
	void _add(Node<TypeGen>*& node, TypeGen data, function<bool(TypeGen)>AddCritery) {

		if (node == nullptr)
			node = new Node<TypeGen>(data);

		else if (AddCritery) { _add(node->left, data, AddCritery); }
		else  { _add(node->right, data,AddCritery); }
	}

	void _InOrder(Node<TypeGen>* node, function<void(TypeGen)>PrintCritery) {
		if (node == nullptr)
			return;
		else {
			_InOrder(node->left, PrintCritery);
			PrintCritery(node->data);
			_InOrder(node->right, PrintCritery);
		}
	}

	void printBT(const std::string& prefix, const Node<TypeGen>* node, bool isLeft, function<void(TypeGen)>PrintCritery)
	{
		if (node != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──");

			// print the value of the node
			PrintCritery(node->data);	//std::cout << node->data << std::endl;
		

			// enter the next tree level - left and right branch
			printBT(prefix + (isLeft ? "│   " : "    "), node->left, true, PrintCritery);
			printBT(prefix + (isLeft ? "│   " : "    "), node->right, false, PrintCritery);
		}
	}

	void printBT(const Node<TypeGen>* node, function<void(TypeGen)>PrintCritery)
	{
		printBT("", node, false,PrintCritery);
	}

	void print_tree_structure(Node<TypeGen>* bt, int spaces, function<void(TypeGen)>PrintCritery)
	{
		if (bt != NULL)
		{
			print_tree_structure(bt->right, spaces + 5,PrintCritery);
			for (int i = 0; i < spaces; i++)
				cout << ' ';
			PrintCritery(bt->data);//cout << "   " << bt->g << endl;
			print_tree_structure(bt->left, spaces + 5,PrintCritery);
		}
	}

public:
	BinaryTree() { root = nullptr; }
	void Add(TypeGen data, function<bool(TypeGen)>AddCritery) { _add(root, data, AddCritery); }
	void InOrder(function<void(TypeGen)>PrintCritery) { _InOrder(root, PrintCritery); }
	void PrintAsTree(function<void(TypeGen)>PrintCritery) { printBT(root,PrintCritery); }
	void impri(function<void(TypeGen)>PrintCritery) { print_tree_structure(root, 1, PrintCritery); }

	
};