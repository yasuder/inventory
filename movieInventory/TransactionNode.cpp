//
// Created by Goitom Hadishe on 5/16/18.
//

#include "TransactionNode.h"

TransactionNode::TransactionNode(char actionType, string movieTitle) {
	this->actionType = actionType;
	this->movieTitle = movieTitle;
	prev = nullptr;
}

TransactionNode::~TransactionNode() {
	delete prev;
}

void TransactionNode::printTransaction() {
	cout << "Action Type:   " << actionType << "    Movie Title: " << movieTitle << endl;
}

char TransactionNode::getActionType() {
	return actionType;
}

string TransactionNode::getMovieTitle() {
	return movieTitle;
}
