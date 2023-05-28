#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Authors:
//     ***REMOVED*** ***REMOVED***,
//     ***REMOVED*** ***REMOVED***,
//     ***REMOVED*** ***REMOVED***

// ########################################syntax#############################################
enum Type {
    VOID_T,
    INT_T,
    REAL_T,
    CHAR_T,
    BOOL_T,
    INT_P_T,
    REAL_P_T,
    CHAR_P_T,
    STRING_T,
    NONE_T
};



// ########################################semantics#############################################




typedef struct Var{
    char* name;
    enum Type type;
}Var;

typedef struct VarArr {
    struct Var** vars;
    int len;
    int capacity;
}VarArr;

typedef struct Function
{
    char* name;
    struct VarArr* varArr;
    enum Type returnType;
} Function;

typedef struct FunctionArr {
    struct Function** funcs;
    int len;
    int capacity;
}FunctionArr;

typedef struct Scope
{
    struct VarArr* varArr;
    struct FunctionArr* funcsArr;
    enum Type returnType;
    int nestedBlocks;
    int nestedFuncs;
    struct Scope* useScope;
}Scope;

typedef struct ScopeStack{
    struct Scope** scopes;
    int len;
    int capacity;
}ScopeStack;

typedef struct node {
    char* token;
    struct node** children;
    int child_num;
    enum Type type;
    Scope* scope;
    Scope* use_scope;
    Scope* pointer;
} node;
#define YYSTYPE node* 
// ##########################################################
// FUNCS OF SEMANTICS
node* mknode(char* token, node** children);
node* mknode1(char* token);
node* nl(){return mknode1("\n");};
node* expNode(char* token,node* first,node* second);
void printtree(node *tree, int shift);
char* plusStr(char* str1,char* str2);
char* shifts(int n);
int indexOf(char* str, char chr);
char* shifts(int n);

// ##########################################################
// FUNCS OF SEMANTICS
void semanticsCheck(node* tree);
Var* newVar(char* name, enum Type type);
Var* newVar_(char* name);
VarArr* newVarArr();
void expandVarArr(VarArr* arr);
void appendVarArr(VarArr* arr, Var* newVar);
VarArr* deepCopyVarArr(VarArr* arr);

// ####################################################################
Function* newFunction(char* name, enum Type returnType, VarArr* varArr);
FunctionArr* newFunctionArr();
void expandFunctionArr(FunctionArr* arr);
void appendFunctionArr(FunctionArr* arr, Function* newFunc);
// ####################################################################

Scope* newScope();
Function* searchFunctionInScope(Scope* scope, char* name);
Var* searchVarInScope(Scope* scope, char* name);
ScopeStack* newScopeStack();
void expandScopeStack(ScopeStack* stack);
void pushScope(ScopeStack* stack, Scope* scope);
void popScope(ScopeStack* stack);
Scope* topScope(ScopeStack* stack);
Function* searchFunctionInStack(ScopeStack* stack, char* name);
Var* searchVarInStack(ScopeStack* stack, char* name);
void fillScope(ScopeStack* stack, node* tree,Scope* scope, VarArr* varArr, enum Type returnType);
void fillScopeByTree(ScopeStack* stack, node* tree, Scope* scope);
// ####################################################################

enum Type getTypeAsEnum(char* type);
char* getTypeAsString(enum Type type);
// node* tree expected to be Parent
int indexOfSon(node* tree, char* token);
// node* tree expected to be Parent
enum Type getFunctionType(node* func);
// node* tree expected to be Parent
VarArr* getFunctionVarArr(node* func);



void addVarArrToScope(VarArr* varArr, Scope* scope);
void addFunctionArrToScope(FunctionArr* funcArr, Scope* scope);
void reverseStack(ScopeStack* stack);