#pragma once

#include <list>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include "Node.h"

// "Helper" functions to build nodes in the tree...
Expression *BinOp(char op, Expression *l, Expression *r)
{
	Expression *result = new Expression('N',l,r);
  	result->op = op;
  	return result;
}

Expression *Variable(string name)
{
Expression *result = new Expression('V',NULL,NULL);
  result->name = name;
  return result;
}

Expression *Constant(int value)
{
Expression *result = new Expression('C',NULL,NULL);
  result->value = value;
  return result;
}

/* Note: You almost certainly do not want to smash together Comparitor
         and Expression classes in anything more complex than the lab */
Expression *Equality(Expression *l, Expression *r)
{
Expression *result = new Expression('N',l,r);
  result->kind = '=';
  return result;
}

Statement *Assign(string target, Expression *val)
{
Statement *result = new Statement('A');
  result->expressions.push_back( Variable(target) );
  result->expressions.push_back(val);
  return result;
}

Statement *If(Expression *condition, Statement *trueSt, Statement *falseSt)
{
Statement *result = new Statement('I');
  result->expressions.push_back(condition);
  result->children.push_back(trueSt);
  result->children.push_back(falseSt);
  return result;
}

Statement *Seq(initializer_list<Statement*> ss)
{
Statement *result = new Statement('S');
  for(auto s : ss)
    result->children.push_back(s);
  return result;
}

void namePass(Expression *tree, map<Expression*,string> &nameMap)
{
   // ...
}

void emitPass(Expression *tree, map<Expression*,string> &nameMap, BBlock *out)
{
  // ...
}

// Returns the last evaluated name
string convert(Expression *in, BBlock *out)
{
map<Expression*,string> naming;
  // TODO: Implement the pseudo code from lec-8 / slides 11 and 12
  //       in the empty procedures above and write the output into
  //       the target BBlock object.
  return naming[in];
}

// TASK: Fill this in to demonstrate understanding of gluing the expression-bit into
//       the statement-bit
void convertAssign(Statement *in, BBlock *out)
{
  // TODO: Convert the assignment statement passed in to 3-address instructions
  //       to fill the target BBlock with.
}

// TASK: Basically - reuse the expression translation (two bits of psuedo code get
//       called from convert() ).
void convertComparitor(Expression *in, BBlock *out)
{
  // TODO: Convert the expression tree with a root comparitor operation into
  //       3-address instructions and fill the target BBlock.
}

// TODO: Double indirection / current pointer / overwriting callers memory
// Tutorially stuff. Fake 3 line example....
// BIG TASK: invent this from slide 26 (lec8) slide 22 (lec8)
void convertIf(Statement *in, BBlock **current)
{
  // TODO: Build the graph structure to implement the if statement
  //       as shown in lecture 8 / slide 22 (and 25). Update the
  //       caller's current pointer before returning.
}

void convertSeq(Statement *in, BBlock **current)
{
  for(auto s: in->children)
  {
    convertStatement(s,current);
  }
}

// Despatch point
void convertStatement(Statement *in, BBlock **current)
{
  switch(in->kind)
  {
    case 'A':
      convertAssign(in,*current);   // Does not update current
    break;
    case 'I':
      convertIf(in,current);
    break;
    case 'S':
      convertSeq(in,current);
    break;
  }
}
