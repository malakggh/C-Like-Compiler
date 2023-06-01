#include "helper.h"
// Authors:
//     ***REMOVED*** ***REMOVED***,
//     ***REMOVED*** ***REMOVED***,
//     ***REMOVED*** ***REMOVED***
node* mknode(char* token, node** children) {
    char* newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr, token);
    node* newnode = (node*)malloc(sizeof(node));
    newnode->token = newstr;

    int len = 0;
    while(children[len]!=NULL)
        len++;
    newnode->child_num = len;

    node** temp = (node**)malloc(sizeof(node*) * len);
    for(int i=0; i<len; i++){
        temp[i] = children[i];
    }
    newnode->children = temp;
    newnode->type = NONE_T;
    newnode->scope = NULL;
    newnode->use_scope = NULL;
    newnode->pointer = NULL;
    newnode->exp_node = NULL;
    return newnode;
}

node* mknode1(char* token) {
    char* newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr, token);
    node* newnode = (node*)malloc(sizeof(node));
    newnode->token = newstr;
    newnode->children = NULL;
    newnode->child_num = 0;
    newnode->type = NONE_T;
    newnode->scope = NULL;
    newnode->use_scope = NULL;
    newnode->pointer = NULL;
    newnode->exp_node = NULL;
    return newnode;
}

node* expNode(char* token,node* first,node* second){
    node* temp = mknode("#",(node*[]){
    mknode1(token),nl(),
    mknode("",(node*[]){first,NULL}),nl(),
    mknode("",(node*[]){second,NULL}),nl(),
    mknode1(")"),nl(),NULL});
    temp->use_scope = newScope();
    addVarArrToScope(first->use_scope->varArr, temp->use_scope);
    addVarArrToScope(second->use_scope->varArr, temp->use_scope);
    addFunctionArrToScope(first->use_scope->funcsArr, temp->use_scope);
    addFunctionArrToScope(second->use_scope->funcsArr, temp->use_scope);
    return temp;
}

expressionNode* mkExpNode(char* name,node* left,node* right){
    expressionNode* temp = (expressionNode*)malloc(sizeof(expressionNode));
    strcpy(temp->name,name);
    temp->left = left;
    temp->right = right;
    temp->result = NONE_T;
    temp->leaf_type = NOT_LEAF;
    return temp;
}


int hasNewLine_REAL = 1;
void printtree_REAL(node* tree, int shift) {
    if (tree == NULL) {
        return;
    }
    if(strcmp("\n",tree->token)==0){
        printf("%sNewLine\n",shifts((shift)*4));
    }else if(strcmp("",tree->token)==0){
        printf("%sEmpty",shifts((shift)*4));
    }else{
        if (tree->type != NONE_T)
            printf("%s%s{%s}",shifts((shift)*4),tree->token,getTypeAsString(tree->type));
        else
            printf("%s%s",shifts((shift)*4),tree->token);

    }
    
    for (int i = 0; i < tree->child_num; i++) {
        if (strcmp(tree->children[i]->token,"#")==0){
                if (hasNewLine_REAL == 1)
                        printtree_REAL(tree->children[i],shift);//zay el loo7 flatter()
                else
                        printtree_REAL(tree->children[i],0);
                continue;
        }
        if (!(tree->children[i]->token == NULL || strcmp(tree->children[i]->token,"")==0)){
                if (indexOf(tree->children[i]->token,'\n')!=-1){
                        if (hasNewLine_REAL == 0){
                                hasNewLine_REAL = 1;
                                printtree_REAL(tree->children[i],0);
                                continue;
                        }else
                                hasNewLine_REAL = 1;
                }else{
                        if (hasNewLine_REAL == 0)
                                hasNewLine_REAL = 0;
                        else{
                                hasNewLine_REAL = 0;
                                printtree_REAL(tree->children[i],shift+1);
                                continue;
                        }
                }
                        

                if (hasNewLine_REAL == 1)
                        printtree_REAL(tree->children[i],shift+1);
                else
                        printtree_REAL(tree->children[i],0);
        }else{
                if (hasNewLine_REAL == 1)
                        printtree_REAL(tree->children[i],shift+1);//zay el loo7 flatter()
                else
                        printtree_REAL(tree->children[i],0);
        }
    }
}

int hasNewLine = 1;

void printtree(node* tree, int shift) {
    if (tree == NULL) {
        return;
    }
    if (!(tree->token == NULL || strcmp(tree->token,"")==0)){
        if (tree->token[0] != '#')
                printf("%s%s",shifts((shift)*4),tree->token);
    }

    for (int i = 0; i < tree->child_num; i++) {
        if (tree->children[i]->token[0] == '#'){
            if (hasNewLine == 1)
                printtree(tree->children[i],shift);//zay el loo7 flatter()
            else
                printtree(tree->children[i],0);
            continue;
        }
        if (!(tree->children[i]->token == NULL || strcmp(tree->children[i]->token,"")==0)){
            if (indexOf(tree->children[i]->token,'\n')!=-1){
                if (hasNewLine == 0){
                    hasNewLine = 1;
                    printtree(tree->children[i],0);
                    continue;
                }else
                    hasNewLine = 1;
            }else{
                if (hasNewLine == 0)
                    hasNewLine = 0;
                else{
                    hasNewLine = 0;
                    printtree(tree->children[i],shift+1);
                    continue;
                }
            }
                    

            if (hasNewLine == 1)
                printtree(tree->children[i],shift+1);
            else
                printtree(tree->children[i],0);
        }else{
            if (hasNewLine == 1)
                printtree(tree->children[i],shift+1);//zay el loo7 flatter()
            else
                printtree(tree->children[i],0);
        }
    }
}

char* shifts(int n){
        if (n<=0){
                char* temp = malloc(1);
                temp[0]='\0';
                return temp;
        }
        char* temp = malloc(n+1);
        for(int i=0; i<n; i++){
                temp[i] = ' ';
        }
        temp[n]='\0';
        return temp;
}

char* plusStr(char* str1,char* str2){
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        char* result = (char*)malloc(len1 + len2 + 1);
        strcpy(result, str1);
        strcpy(result + len1, str2);
        return result;
}

int indexOf(char* str, char chr) {
    char* result = strchr(str, chr);
    if (result == NULL) {
        return -1;
    } else {
        return result - str;
    }
}

// ########################################semantics#############################################

Var* newVar(char* name, enum Type type) {
    Var* var = (Var*)malloc(sizeof(Var));
    char* newstr = (char*)malloc(sizeof(name) + 1);
    strcpy(newstr, name);
    var->name = newstr;
    var->type = type;
    return var;
}
Var* newVar_(char* name){
    Var* var = (Var*)malloc(sizeof(Var));
    char* newstr = (char*)malloc(sizeof(name) + 1);
    strcpy(newstr, name);
    var->name = newstr;
    var->type = NONE_T;
    return var;
}
VarArr* newVarArr() {
    VarArr* arr = (VarArr*)malloc(sizeof(VarArr));
    arr->len = 0;
    arr->capacity = 1;
    arr->vars = (Var**)malloc(sizeof(Var*) * arr->capacity);
    return arr;
}
void expandVarArr(VarArr* arr) {
    if (arr->len == arr->capacity) {
        arr->capacity *= 2;
        arr->vars = (Var**)realloc(arr->vars, sizeof(Var*) * arr->capacity);
    }
}
void appendVarArr(VarArr* arr, Var* newVar) {
    expandVarArr(arr);
    arr->vars[arr->len] = newVar;
    arr->len++;
}
VarArr* deepCopyVarArr(VarArr* arr){
    if (arr == NULL) return NULL;
    VarArr* newArr = newVarArr();
    for(int i=0; i<arr->len; i++){
        appendVarArr(newArr, newVar(arr->vars[i]->name, arr->vars[i]->type));
    }
    return newArr;
}

// ####################################################################

Function* newFunction(char* name, enum Type returnType, VarArr* varArr) {
    Function* func = (Function*)malloc(sizeof(Function));
    char* newstr = (char*)malloc(sizeof(name) + 1);
    strcpy(newstr, name);
    func->name = newstr;
    func->returnType = returnType;
    func->varArr = varArr;
    return func;
}

FunctionArr* newFunctionArr() {
    FunctionArr* arr = (FunctionArr*)malloc(sizeof(FunctionArr));
    arr->len = 0;
    arr->capacity = 1;
    arr->funcs = (Function**)malloc(sizeof(Function*) * arr->capacity);
    return arr;
}
void expandFunctionArr(FunctionArr* arr) {
    if (arr->len == arr->capacity) {
        arr->capacity *= 2;
        arr->funcs = (Function**)realloc(arr->funcs, sizeof(Function*) * arr->capacity);
    }
}
void appendFunctionArr(FunctionArr* arr, Function* newFunc) {
    expandFunctionArr(arr);
    arr->funcs[arr->len] = newFunc;
    arr->len++;
}


// ####################################################################

Scope* newScope() {
    Scope* scope = (Scope*)malloc(sizeof(Scope));
    scope->varArr = newVarArr();
    scope->funcsArr = newFunctionArr();
    scope->returnType = NONE_T;
    scope->nestedBlocks = 0;
    scope->nestedFuncs = 0;
    scope->useScope = NULL;
    return scope;
}

Function* searchFunctionInScope(Scope* scope, char* name) {
    for (int i = 0; i < scope->funcsArr->len; i++) {
        if (strcmp(scope->funcsArr->funcs[i]->name, name) == 0) {
            return scope->funcsArr->funcs[i];
        }
    }
    return NULL;
}

Var* searchVarInScope(Scope* scope, char* name) {
    for (int i = 0; i < scope->varArr->len; i++) {
        if (strcmp(scope->varArr->vars[i]->name, name) == 0) {
            return scope->varArr->vars[i];
        }
    }
    return NULL;
}

ScopeStack* newScopeStack() {
    ScopeStack* stack = (ScopeStack*)malloc(sizeof(ScopeStack));
    stack->len = 0;
    stack->capacity = 1;
    stack->scopes = (Scope**)malloc(sizeof(Scope*) * stack->capacity);
    return stack;
}

void expandScopeStack(ScopeStack* stack) {
    if (stack->len == stack->capacity) {
        stack->capacity *= 2;
        stack->scopes = (Scope**)realloc(stack->scopes, sizeof(Scope*) * stack->capacity);
    }
}

void pushScope(ScopeStack* stack, Scope* scope) {
    expandScopeStack(stack);
    stack->scopes[stack->len] = scope;
    stack->len++;
}

void popScope(ScopeStack* stack) {
    stack->len--;
}

Scope* topScope(ScopeStack* stack) {
    return stack->scopes[stack->len - 1];
}

Function* searchFunctionInStack(ScopeStack* stack, char* name) {
    for (int i = stack->len - 1; i >= 0; i--) {
        Function* func = searchFunctionInScope(stack->scopes[i], name);
        if (func != NULL) {
            return func;
        }
    }
    return NULL;
}

Var* searchVarInStack(ScopeStack* stack, char* name) {
    for (int i = stack->len - 1; i >= 0; i--) {
        Var* var = searchVarInScope(stack->scopes[i], name);
        if (var != NULL) {
            return var;
        }
    }
    return NULL;
}

enum Type searchTypeInStack(ScopeStack* stack){
    for (int i = stack->len - 1; i >= 0; i--) {
        if (stack->scopes[i]->returnType != NONE_T) {
            return stack->scopes[i]->returnType;
        }
    }
    return NONE_T;
}


void addVarArrToScope(VarArr* varArr, Scope* scope){
    if (varArr == NULL || scope == NULL) return;
    for(int i=0; i<varArr->len; i++){
        appendVarArr(scope->varArr, varArr->vars[i]);
    }
}

void addFunctionArrToScope(FunctionArr* funcArr, Scope* scope){
    if (funcArr == NULL || scope == NULL) return;
    for(int i=0; i<funcArr->len; i++){
        appendFunctionArr(scope->funcsArr, funcArr->funcs[i]);
    }
}

// ####################################################################

// build entier logical scope stack for the whole program
// build stack..
// add global scope
// add each required scope 

void printVarArr(VarArr* varArr){
    if (varArr == NULL){
        printf("varArr: []");
        return;
    }
    printf("varArr: [");
    for (int i = 0; i < varArr->len; i++) {
        if (i == varArr->len-1)
            printf("%s-%s]", varArr->vars[i]->name, getTypeAsString(varArr->vars[i]->type));
        else
            printf("%s-%s, ", varArr->vars[i]->name, getTypeAsString(varArr->vars[i]->type));
    }
    if (varArr->len == 0)
        printf("]");
}

void printFunctionArr(FunctionArr* funcsArr){
    if (funcsArr == NULL){
        printf("funcsArr: []\n");
        return;
    }
    printf("funcsArr: [");
    for (int i = 0; i < funcsArr->len; i++) {
        printf("{%s, ",funcsArr->funcs[i]->name);
        printVarArr(funcsArr->funcs[i]->varArr);
        printf(", %s}", getTypeAsString(funcsArr->funcs[i]->returnType));
        if (i != funcsArr->len-1)
            printf(", ");
    }
    printf("]\n");
}

void printUseScope(Scope* scope){
    if (scope == NULL) {
        return;
    }
    if (scope->funcsArr->len==0 && scope->varArr->len==0) return;
    printf("\n\nUse Scope: \n");
    printf("\t---- Variables ----\n\t");
    printVarArr(scope->varArr);
    printf("\n");
    
    printf("\t---- Functions ----\n\t");
    printFunctionArr(scope->funcsArr);
}

void printScope(Scope* scope, int i) {
    if (scope == NULL) {
        printf("scope %d: NULL\n", i);
        return;
    }
    printf("################# Start of Scope %d #####################\n", i);
    printf("Declartions: \n");
    printf("\tReturn Type: %s\n", getTypeAsString(scope->returnType));
    // printf("\tNested Blocks: %d\n", scope->nestedBlocks);
    // printf("\tNested Functions: %d\n\n", scope->nestedFuncs);
    
    printf("\t---- Variables ----\n\t");
    printVarArr(scope->varArr);
    printf("\n");
    
    printf("\t---- Functions ----\n\t");
    printFunctionArr(scope->funcsArr);
    printUseScope(scope->useScope);
    printf("################# End of Scope %d #######################\n", i);
}


void printScopeStack(ScopeStack* stack){
    if (stack == NULL){
        printf("stack: NULL\n");
        return;
    }
    printf("stack:\n");
    for (int i = 0; i < stack->len; i++) {
        printScope(stack->scopes[i], i);
    }
}

void reverseStack(ScopeStack* stack){
    if (stack == NULL) return;
    // reverse the stack in place
    int i = 0;
    int j = stack->len-1;
    while(i<j){
        Scope* temp = stack->scopes[i];
        stack->scopes[i] = stack->scopes[j];
        stack->scopes[j] = temp;
        i++;
        j--;
    }
}



void printSemanticOrder(node* tree){
    if (tree == NULL) return;


    for(int i=0; i<tree->child_num; i++){
        node* child = tree->children[i];
        if (strcmp(child->token,"(BODY")==0){
            printf("BODY:\n");
            printtree(tree->children[i+2],0);
        }
        if (strcmp(child->token,"(BLOCK")==0){
            printf("BLOCK:\n");
            printtree(tree->children[i+2]->children[0],0);
        }
        if (strcmp(child->token,"#global_scope")==0){
            printf("global_scope:\n");
            printtree(child->children[0],0);
            break;
        }
        if (strcmp(child->token,"#statement_block")==0 && 
            !(strcmp(child->children[0]->token,"#new_block")==0)){
                printf("#statement_block:\n");
                printtree(child->children[0],0);
        }
    }
    for(int i=0; i<tree->child_num; i++){
        printSemanticOrder(tree->children[i]);
    }

}
// here to continue
// trying to print the scopes in the right order
void startSemanticCheck(node* tree,ScopeStack* stack){
    if (tree == NULL) return;


    for(int i=0; i<tree->child_num; i++){
        node* child = tree->children[i];
        if (strcmp(child->token,"(BODY")==0){
            pushScope(stack,tree->children[i+2]->pointer);
            // printf("pushing function %s scope\n",tree->children[i-11]->token);
        }
        if (strcmp(child->token,"(BLOCK")==0){
            pushScope(stack,tree->children[i+2]->children[0]->pointer);
        }
        
        if (strcmp(child->token,"#statement_block")==0 && 
            !(strcmp(child->children[0]->token,"#new_block")==0)){
                pushScope(stack,child->children[0]->pointer);
        }
    }

    for(int i=0; i<tree->child_num; i++){
        startSemanticCheck(tree->children[i],stack);
    }
    int printCheck = 0;
    for(int i=0; i<tree->child_num; i++){
        node* child = tree->children[i];
        if (strcmp(child->token,"(BODY")==0){
            if(printCheck) printScopeStack(stack);
            if(printCheck) printf("-*-*-*-*processing this scope-*-*-*-*\n");
            processScope(stack,tree->children[i+2]);
            if(printCheck) printScope(topScope(stack), stack->len-1);
            popScope(stack);
            child->token = "(BODY-DONE";
        }
        if (strcmp(child->token,"(BLOCK")==0){
            if(printCheck) printScopeStack(stack);
            if(printCheck) printf("-*-*-*-*processing this scope-*-*-*-*\n");
            processScope(stack,tree->children[i+2]->children[0]);
            if(printCheck) printScope(topScope(stack), stack->len-1);
            popScope(stack);
            child->token = "(BLOCK-DONE";
        }
        if (strcmp(child->token,"#statement_block")==0 && 
            !(strcmp(child->children[0]->token,"#new_block")==0)){
                if(printCheck) printScopeStack(stack);
                if(printCheck) printf("-*-*-*-*processing this scope-*-*-*-*\n");
                processScope(stack,child->children[0]);
                if(printCheck) printScope(topScope(stack), stack->len-1);
                popScope(stack);
                child->token = "#statement_block-DONE";
        }
    }
}

void semantic_for_each_function(node* tree,ScopeStack* stack, Scope* global_scope){
    if (tree == NULL) return;
    for(int i=0; i<tree->child_num; i++){
        node* child = tree->children[i];
        if (strcmp(child->token,"#global_scope")==0){
            // printf("semantics test for function: %s\n",child->children[0]->children[2]->children[0]->token);
            addFunctionArrToScope(child->children[0]->pointer->funcsArr, global_scope);
            startSemanticCheck(child->children[0],stack);
            break;
        }
    }
    for(int i=0; i<tree->child_num; i++){
        semantic_for_each_function(tree->children[i],stack,global_scope);
    }
}

int mainFound = 0;

void semantic(node* tree,ScopeStack* stack, Scope* global_scope){
    if (mainFound == 0){
        printf("Error: main function is not defined\n");
        exit(1);
    }
    semantic_for_each_function(tree,stack,global_scope);
}

// check if main exists once and if it's void and has no args
void mainCheck(Scope* scopeOfFunc){
    Function* currentFunction = scopeOfFunc->funcsArr->funcs[0];
    if (mainFound && strcmp(currentFunction->name,"main")==0){
        printf("Error: main function is defined more than once\n");
        exit(1);
    }
    if (!(strcmp(currentFunction->name,"main")==0))
        return;
    mainFound = 1;

    if (currentFunction->returnType != VOID_T){
        printf("Error: main function must return void\n");
        exit(1);
    }

    if (currentFunction->varArr->len != 0){
        printf("Error: main function must not have any arguments\n");
        exit(1);
    }


}

void processScope(ScopeStack* stack, node* tree){
    checkEveryVarOrFunctionInScopeIfDefinedBeforeUse(stack);
    // printScope(topScope(stack), stack->len-1);
    getEachExpression(tree,stack);

}

void getEachExpression(node* tree, ScopeStack* stack){
    if (tree == NULL) return;
    for (int i = 0; i < tree->child_num; i++) {
        getEachExpression(tree->children[i],stack);
    }
    for (int i = 0; i < tree->child_num; i++) {
        node* child = tree->children[i];
        if (strcmp(child->token,"#ret_st")==0){
            node* exp = child->children[1];
            getExpType(exp->exp_node,stack);
            if (exp->exp_node->result != searchTypeInStack(stack)){
                printf("Error: return type is not the same as the function return type\n");
                exit(1);
            }
            child->token = "#ret_st-DONE";
            return;
        }else if (strcmp(child->token,"(IF")==0){
            node* exp = tree->children[i+2]->children[0];
            getExpType(exp->exp_node,stack);
            if (exp->exp_node->result != BOOL_T){
                printf("Error: if condition must be of type bool\n");
                exit(1);
            }
            child->token = "(IF-DONE";
            return;
        }else if(strcmp(child->token,"(IF-ELSE")==0){
            node* exp = tree->children[i+2]->children[0];
            getExpType(exp->exp_node,stack);
            if (exp->exp_node->result != BOOL_T){
                printf("Error: if condition must be of type bool\n");
                exit(1);
            }
            child->token = "(IF-ELSE-DONE";
            return;
        }else if(strcmp(child->token,"(DO-WHILE-INIT")==0){
            node* exp = tree->children[i+2]->children[0];
            getExpType(exp->exp_node,stack);
            if (exp->exp_node->result != BOOL_T){
                printf("Error: do-while condition must be of type bool\n");
                exit(1);
            }
            child->token = "(DO-WHILE-INIT-DONE";
            return;
        }else if(strcmp(child->token,"(WHILE-INIT")==0){
            node* exp = tree->children[i+2]->children[0];
            getExpType(exp->exp_node,stack);
            if (exp->exp_node->result != BOOL_T){
                printf("Error: while condition must be of type bool\n");
                exit(1);
            }
            child->token = "(WHILE-INIT-DONE";
            return;
        }else if(strcmp(child->token,"(FOR-INIT")==0){
            node* exp = tree->children[i+3]->children[0];
            getExpType(exp->exp_node,stack);
            if (exp->exp_node->result != BOOL_T){
                printf("Error: for condition must be of type bool\n");
                exit(1);
            }
            child->token = "(FOR-INIT-DONE";
            return;
        }else if(strcmp(child->token,"#assignment_st")==0){
            node* exp = child->children[4]->children[0];
            node* lhs = child->children[1];
            getExpType(exp->exp_node,stack);
            // part 14 is here
            if (strcmp(lhs->token,"#derefId")==0){
                Var* var = getVarOrExit(stack, lhs->children[1]->token);
                if (dereferenceOf(var->type) != exp->exp_node->result){
                    printf("Error: assignment type is not the same as the variable type\n");
                    exit(1);
                }
            }else if (strcmp(lhs->token,"#stringAtIndex")==0){
                Var* var = getVarOrExit(stack, lhs->children[0]->token);
                if (var->type != STRING_T){
                    printf("Error: operator [] can only be used on STRING\n");
                    exit(1);
                }
                node* index = lhs->children[2];
                getExpType(index->exp_node,stack);
                if (index->exp_node->result != INT_T){
                    printf("Error: index of string must be of type INT\n");
                    exit(1);
                }
                if (exp->exp_node->result != CHAR_T || exp->exp_node->result != NULL_T){
                    printf("Error: STRING[index] can only be assigned to CHAR or NULL\n");
                    exit(1);
                }

            }else{
                // var
                Var* var = getVarOrExit(stack, lhs->token);
                if (var->type != exp->exp_node->result){
                    printf("Error: assignment type is not the same as the variable type\n");
                    exit(1);
                }
            }

            child->token = "#assignment_st-DONE";
            return;
        }else if(strcmp(child->token,"#var_string_opt")==0){
            node* index = child->children[2];
            getExpType(index->exp_node,stack);
            if (index->exp_node->result != INT_T){
                printf("Error: index of string must be of type INT\n");
                exit(1);
            }
            child->token = "#var_string_opt-DONE";
            return;
        }
    }
}


enum Type addressOf(enum Type type){
    if (type == INT_T) return INT_P_T;
    if (type == REAL_T) return REAL_P_T;
    if (type == CHAR_T) return CHAR_P_T;
    printf("Error: operator & can only be used on INT, REAL, CHAR\n");
    exit(1);
}

enum Type dereferenceOf(enum Type type){
    if (type == INT_P_T) return INT_T;
    if (type == REAL_P_T) return REAL_T;
    if (type == CHAR_P_T) return CHAR_T;
    printf("Error: operator * can only be used on INT*, REAL*, CHAR*\n");
    exit(1);
}

Var* getVarOrExit(ScopeStack* stack, char* name){
    Var* var = searchVarInStack(stack, name);
    if (var == NULL){
        printf("Error: variable (%s) is used before being defined\n", name);
        exit(1);
    }
    return var;
}

void checkUpdateArithmeticOperation(expressionNode* expressionNode, char operator){
    if (expressionNode->left->exp_node->result == INT_T && expressionNode->right->exp_node->result == INT_T){
        expressionNode->result = INT_T;
    }else if (expressionNode->left->exp_node->result == REAL_T && expressionNode->right->exp_node->result == REAL_T){
        expressionNode->result = REAL_T;
    }else if (expressionNode->left->exp_node->result == INT_T && expressionNode->right->exp_node->result == REAL_T){
        expressionNode->result = REAL_T;
    }else if (expressionNode->left->exp_node->result == REAL_T && expressionNode->right->exp_node->result == INT_T){
        expressionNode->result = REAL_T;
    }else{
        printf("Error: operator %c can only be used on INT, REAL\n", operator);
        exit(1);
    }
}

// for bool operations the operands must be of bool type and the result is always bool
void checkUpdateBoolOperation(expressionNode* expressionNode, char* operator){
    if (expressionNode->left->exp_node->result == BOOL_T && expressionNode->right->exp_node->result == BOOL_T){
        expressionNode->result = BOOL_T;
    }else{
        printf("Error: operator %s can only be used on BOOL\n", operator);
        exit(1);
    }
}

// for comparison operations the operands must be int or real and the result is always bool
void checkUpdateComparisonOperation(expressionNode* expressionNode, char* operator){
    if (expressionNode->left->exp_node->result == INT_T && expressionNode->right->exp_node->result == INT_T){
        expressionNode->result = BOOL_T;
    }else if (expressionNode->left->exp_node->result == REAL_T && expressionNode->right->exp_node->result == REAL_T){
        expressionNode->result = BOOL_T;
    }else if (expressionNode->left->exp_node->result == INT_T && expressionNode->right->exp_node->result == REAL_T){
        expressionNode->result = BOOL_T;
    }else if (expressionNode->left->exp_node->result == REAL_T && expressionNode->right->exp_node->result == INT_T){
        expressionNode->result = BOOL_T;
    }else{
        printf("Error: operator %s can only be used on INT, REAL\n", operator);
        exit(1);
    }
}

// for == and != the two operands muse be of the same type of (int, real, char, bool, int*, real*, char*) and the result is always bool
void checkUpdateEqualityOperation(expressionNode* expressionNode, char* operator){
    if (expressionNode->left->exp_node->result != expressionNode->right->exp_node->result){
        printf("Error: operator %s can only be used on operands of the same type\n", operator);
        exit(1);
    }
    enum Type type = expressionNode->left->exp_node->result;
    if (type == INT_T || type == REAL_T || type == CHAR_T || type == BOOL_T || type == INT_P_T || type == REAL_P_T || type == CHAR_P_T){
        expressionNode->result = BOOL_T;
    }else{
        printf("Error: operator %s can only be used on INT, REAL, CHAR, BOOL, INT*, REAL*, CHAR*\n", operator);
        exit(1);
    }
}


void getExpType(expressionNode* expressionNode, ScopeStack* stack){
    if (expressionNode->leaf_type != NOT_LEAF) {
        // we are dealing with leaf
        if (expressionNode->leaf_type == ID_LEAF){
            Var* var = getVarOrExit(stack, expressionNode->name);
            expressionNode->result = var->type;
        }else if(expressionNode->leaf_type == FUNC_CALL){
            Function* func = searchFunctionInStack(stack, expressionNode->name);
            if (func == NULL){
                printf("Error: function (%s) is used before being defined\n", expressionNode->name);
                exit(1);
            }
            expressionNode->result = func->returnType;
        }else if(expressionNode->leaf_type == LEN_OF_STR){
            Var* var = getVarOrExit(stack, expressionNode->name);
            if (var->type != STRING_T){
                printf("Error: len function can only be used on strings\n");
                exit(1);
            }
            expressionNode->result = INT_T;

        }else if(expressionNode->leaf_type == ADDRESS_OF){
            Var* var = getVarOrExit(stack, expressionNode->name);
            expressionNode->result = addressOf(var->type);
        }
        else if(expressionNode->leaf_type == DEREFERENCE){
            Var* var = getVarOrExit(stack, expressionNode->name);
            expressionNode->result = dereferenceOf(var->type);
        }
        return;
    }
    if (expressionNode->left != NULL)
        getExpType(expressionNode->left->exp_node,stack);
    if (expressionNode->right != NULL)
        getExpType(expressionNode->right->exp_node,stack);
    if (strcmp(expressionNode->name,"+")==0){
        checkUpdateArithmeticOperation(expressionNode, '+');
    }else if (strcmp(expressionNode->name,"-")==0){
        checkUpdateArithmeticOperation(expressionNode, '-');
    }else if (strcmp(expressionNode->name,"*")==0){
        checkUpdateArithmeticOperation(expressionNode, '*');
    }else if (strcmp(expressionNode->name,"/")==0){
        checkUpdateArithmeticOperation(expressionNode, '/');
    }else if (strcmp(expressionNode->name, "&&")==0){
        checkUpdateBoolOperation(expressionNode, "&&");
    }else if (strcmp(expressionNode->name, "||")==0){
        checkUpdateBoolOperation(expressionNode, "||");
    }else if (strcmp(expressionNode->name, "<=")==0){
        checkUpdateComparisonOperation(expressionNode, "<=");
    }else if (strcmp(expressionNode->name, ">=")==0){
        checkUpdateComparisonOperation(expressionNode, ">=");
    }else if (strcmp(expressionNode->name, "<")==0){
        checkUpdateComparisonOperation(expressionNode, "<");
    }else if (strcmp(expressionNode->name, ">")==0){
        checkUpdateComparisonOperation(expressionNode, ">");
    }else if (strcmp(expressionNode->name, "==")==0){
        checkUpdateEqualityOperation(expressionNode, "==");
    }else if (strcmp(expressionNode->name, "!=")==0){
        checkUpdateEqualityOperation(expressionNode, "!=");
    }else if (strcmp(expressionNode->name, "!")==0){
        if (expressionNode->left->exp_node->result != BOOL_T){
            printf("Error: operator ! can only be used on BOOL\n");
            exit(1);
        }
        expressionNode->result = BOOL_T;
    }else if (strcmp(expressionNode->name, "addressOfChar")==0){
        if (expressionNode->left->exp_node->result != STRING_T){
            printf("Error: operator [] can only be used on STRING\n");
            exit(1);
        }
        if (expressionNode->right->exp_node->result != INT_T){
            printf("Error: operator [] can only be used with INT\n");
            exit(1);
        }
        expressionNode->result = CHAR_P_T;
    }else if (strcmp(expressionNode->name, "charAt")==0){
        if (expressionNode->left->exp_node->result != STRING_T){
            printf("Error: operator [] can only be used on STRING\n");
            exit(1);
        }
        if (expressionNode->right->exp_node->result != INT_T){
            printf("Error: operator [] can only be used with INT\n");
            exit(1);
        }
        expressionNode->result = CHAR_T;
    }

}

void checkDuplicateVarOrFuncInScope(Scope* scope){
    if (scope == NULL) return;
    for(int j=0; j<scope->varArr->len; j++){
        Var* var = scope->varArr->vars[j];
        for(int k=j+1; k<scope->varArr->len; k++){
            Var* var2 = scope->varArr->vars[k];
            if (strcmp(var->name,var2->name)==0){
                printf("Error: found duplicate variable (%s) in the same scope\n", var->name);
                exit(1);
            }
        }
    }
    for(int j=0; j<scope->funcsArr->len; j++){
        Function* func = scope->funcsArr->funcs[j];
        for(int k=j+1; k<scope->funcsArr->len; k++){
            Function* func2 = scope->funcsArr->funcs[k];
            if (strcmp(func->name,func2->name)==0){
                printf("Error: found duplicate function (%s) in the same scope\n", func->name);
                exit(1);
            }
        }
    }
    
}


void checkEveryVarOrFunctionInScopeIfDefinedBeforeUse(ScopeStack* stack){
    Scope* currentScope = topScope(stack)->useScope;
    if (currentScope == NULL) return;
    for(int i=0; i<currentScope->varArr->len; i++){
        Var* var = currentScope->varArr->vars[i];
        Var* var2 = searchVarInStack(stack, var->name);
        if (var2 == NULL){
            printf("Error: variable (%s) is used before being defined\n", var->name);
            exit(1);
        }
        // update the type of the variable in the current scope
        var->type = var2->type;
    }
    for(int i=0; i<currentScope->funcsArr->len; i++){
        Function* func = currentScope->funcsArr->funcs[i];
        Function* func2 = searchFunctionInStack(stack, func->name);
        if (func2 == NULL){
            printf("Error: function (%s) is used before being defined\n", func->name);
            exit(1);
        }
        // update the type of the function in the current scope
        func->returnType = func2->returnType;
    }
}


int howManyBlockIhaveInside(node* tree,int count){
    if (tree == NULL) return count;
    if (strcmp(tree->token,"(BLOCK")==0){
        count++;
    }
    for(int i=0; i<tree->child_num; i++){
        count = howManyBlockIhaveInside(tree->children[i],count);
    }
    return count;
}

int howManyFunctionsIHaveInside(node* tree,int count){
    if (tree == NULL) return count;
    if (strcmp(tree->token,"(FUNC")==0){
        count++;
    }
    for(int i=0; i<tree->child_num; i++){
        count = howManyFunctionsIHaveInside(tree->children[i],count);
    }
    return count;
}




// these functions are not in use atm
void semanticsCheck(node* tree){
    printf("semanticsCheck\n");
    // Create a scope stack
    printf("create a scope stack\n");
    ScopeStack* stack = newScopeStack();
    // Create the global scope
    printf("create the global scope\n");
    Scope* global_scope = newScope();
    // Push the global scope onto the stack
    pushScope(stack, global_scope);
    // Fill the global scope
    printScope(global_scope, stack->len-1);
    fillScope(stack, tree->children[2], global_scope, NULL, VOID_T);
    printScope(global_scope, stack->len-1);
}

void fillScope(ScopeStack* stack, node* tree, Scope* scope, VarArr* varArr, enum Type returnType){
    scope->varArr = deepCopyVarArr(varArr);
    scope->returnType = returnType;
    if(tree == NULL) return;
    printf("fillScopeByTree\n");
    fillScopeByTree(stack, tree, scope);
}

void topDownTree(node* tree){
    if (tree == NULL) return;
    printf("%s\n",tree->token);
    for (int i = 0; i < tree->child_num; i++)
    {
        topDownTree(tree->children[i]);
    }
    
}

void fillScopeBody(ScopeStack* stack, node* tree, Scope* scope){
    // we are inside a body of a function we don't need to start a new scope
    // we've already done that in the function we have to fill the current scope
    // within the new info
    printf("topDownTree\n");
    topDownTree(tree);
    
    
}

void fillScopeByTree(ScopeStack* stack, node* tree, Scope* scope){
    if (tree == NULL) return;
    for (int i = 0; i < tree->child_num; i++) {
        char* token = tree->children[i]->token;
        if ((strcmp(token,"#")==0) || strcmp(token,"")==0){
            fillScopeByTree(stack, tree->children[i], scope);
            continue;
        }
        // for each situation, check the scope
        if (strcmp(token,"(FUNC")==0){
            printf("add function\n");
            node* func = tree->children[i+2];

            // check if the function is already defined in the current scope
            // if not, add it to the scope else throw error
            // create a new scope for the function
            // push the new scope onto the stack
            // fill the new scope
            // pop the scope from the stack

            if (searchFunctionInScope(scope, func->children[0]->token) != NULL){
                printf("Error: function %s is already defined in the current scope\n", func->children[0]->token);
                exit(1);
            }
            Function* newFunc = newFunction(func->children[0]->token, VOID_T, NULL);
            newFunc->returnType = getFunctionType(func);
            printf("function return type is %s\n", getTypeAsString(newFunc->returnType));
            newFunc->varArr = getFunctionVarArr(func);
            // printf("index of (BODY is %d\n", indexOfSon(func, "(BODY"));
            // printtree_REAL(func->children[indexOfSon(func, "(BODY")+2],0);
            appendFunctionArr(scope->funcsArr, newFunc);
            Scope* new_scope = newScope();
            pushScope(stack, new_scope);
            printScope(new_scope, stack->len-1);
            new_scope->varArr = deepCopyVarArr(newFunc->varArr);
            new_scope->returnType = newFunc->returnType;
            fillScopeBody(stack,func->children[indexOfSon(func, "(BODY")+2],new_scope);
            printScope(new_scope, stack->len-1);
            popScope(stack);
            
        }
        fillScopeByTree(stack, tree->children[i], scope);
    }
}






enum Type getTypeAsEnum(char* type){
    if (strcmp(type,"INT")==0) return INT_T;
    if (strcmp(type,"REAL")==0) return REAL_T;
    if (strcmp(type,"CHAR")==0) return CHAR_T;
    if (strcmp(type,"BOOL")==0) return BOOL_T;
    if (strcmp(type,"INT*")==0) return INT_P_T;
    if (strcmp(type,"REAL*")==0) return REAL_P_T;
    if (strcmp(type,"CHAR*")==0) return CHAR_P_T;
    if (strcmp(type,"STRING")==0) return STRING_T;
    if (strcmp(type,"NONE")==0) return NONE_T;
    return VOID_T;
}
char* getTypeAsString(enum Type type){
    if (type == INT_T) return "INT";
    if (type == REAL_T) return "REAL";
    if (type == CHAR_T) return "CHAR";
    if (type == BOOL_T) return "BOOL";
    if (type == INT_P_T) return "INT*";
    if (type == REAL_P_T) return "REAL*";
    if (type == CHAR_P_T) return "CHAR*";
    if (type == STRING_T) return "STRING";
    if (type == NONE_T) return "NONE";
    return "VOID";
}

// to scan tree bottom up you need to use post-order traversal
// to scan tree top down you need to use pre-order traversal

node* getFunctionVarArr_Scanner(node* func,VarArr* varArr){
    if (func == NULL) return NULL;
    // ignore '(' ')' '\n' '' '#' ',' and func->type == func->getTypeAsEnum(token)
    if (strcmp(func->token,"(")==0 || strcmp(func->token,")")==0 || strcmp(func->token,"\n")==0 || strcmp(func->token,"")==0 || strcmp(func->token,"#")==0 || strcmp(func->token,",")==0 || func->type == getTypeAsEnum(func->token)){
    }else{
        // printf("add var %s and type is %s \n", func->token, getTypeAsString(func->type));
        appendVarArr(varArr, newVar(func->token, func->type));
    }
    for (int i = 0; i < func->child_num; i++) {
        getFunctionVarArr_Scanner(func->children[i], varArr);
    }
    return NULL;
}

node* get_var_list(node* tree,VarArr* varArr){
    if (tree == NULL) return NULL;
    if (tree->children == NULL) return NULL; 
    node* firstChild = tree->children[0]; 
    if (strcmp(firstChild->token,"#ass_in_var")==0){     
        // printf("%s->%s\n", firstChild->children[0]->children[1]->token, getTypeAsString(firstChild->type));
        appendVarArr(varArr, newVar(firstChild->children[0]->children[1]->token, firstChild->type));
    }else{
        // printf("%s->%s\n", firstChild->token, getTypeAsString(firstChild->type));
        appendVarArr(varArr, newVar(firstChild->token, firstChild->type));
    }
    
    get_var_list(tree->children[2], varArr);
    return NULL;
}

node* get_var_string_list(node* tree,VarArr* varArr){
    if (tree == NULL) return NULL;
    if (tree->children == NULL) return NULL; 
    node* firstChild = tree->children[0]; 
    if (strcmp(firstChild->token,"#ass_in_str")==0){     
        // printf("%s->%s\n", firstChild->children[0]->children[1]->token, STRING_T);
        appendVarArr(varArr, newVar(firstChild->children[0]->children[1]->children[0]->token, STRING_T));
    }else
    {
        // printf("%s->%s\n", firstChild->token, STRING_T);
        appendVarArr(varArr, newVar(firstChild->children[0]->token, STRING_T));
    }
    
    get_var_string_list(tree->children[2], varArr);
    return NULL;
}

node* add_vars_to_scope(node* tree, Scope* scope){
    if (tree == NULL) return NULL;
    if (tree->children == NULL) return NULL; 
    if (strcmp(tree->token,"#vars")==0){     
        node* var_st = tree->children[0];
        if (var_st->scope != NULL)
            addVarArrToScope(var_st->scope->varArr,scope);
    }
    for (int i = 0; i < tree->child_num; i++) {
        add_vars_to_scope(tree->children[i], scope);
    }
    return NULL;
}

node* add_functions_to_scope(node* tree, Scope* scope){
    if (tree == NULL) return NULL;
    if (tree->children == NULL) return NULL; 
    if (strcmp(tree->token,"#non_global_scope")==0){     
        node* func_st = tree->children[0];
        addFunctionArrToScope(func_st->scope->funcsArr,scope);
        func_st->scope->funcsArr = NULL;
    }
    for (int i = 0; i < tree->child_num; i++) {
        add_functions_to_scope(tree->children[i], scope);
    }
    return NULL;
}

node* add_args_to_scope(node* tree, Scope* scope){
    if (tree == NULL) return NULL;
    if (tree->children == NULL) return NULL; 
    if (strcmp(tree->token,"#exp_list")==0){     
        node* var_st = tree->children[0];
        if (var_st->use_scope != NULL){
            addVarArrToScope(var_st->use_scope->varArr,scope);
            addFunctionArrToScope(var_st->use_scope->funcsArr,scope);
        }
    }
    for (int i = 0; i < tree->child_num; i++) {
        add_args_to_scope(tree->children[i], scope);
    }
    return NULL;
}

node* add_statements_to_scope(node* statementsTree, Scope* scope){
    if (statementsTree == NULL) return NULL;
    if (statementsTree->children == NULL) return NULL; 
    if (strcmp(statementsTree->token,"#statements")==0){     
        node* statement = statementsTree->children[0]; 
        if (statement->use_scope != NULL){
            addVarArrToScope(statement->use_scope->varArr,scope);
            addFunctionArrToScope(statement->use_scope->funcsArr,scope);
            statement->use_scope=NULL;
        }
    }
    for (int i = 0; i < statementsTree->child_num; i++) {
        add_statements_to_scope(statementsTree->children[i], scope);
    }
    return NULL;
}


VarArr* getFunctionVarArr(node* func){
    if (indexOfSon(func, "(ARGS")!= -1){
        node* args = func->children[indexOfSon(func, "(ARGS") + 2];
        VarArr* varArr = newVarArr();
        // printtree_REAL(args,0);
        getFunctionVarArr_Scanner(args, varArr);
        // print the varArr to check
        printVarArr(varArr);
        printf("\n");
        return varArr;
    }
    return NULL;
}

enum Type getFunctionType(node* func){
    // printtree_REAL(func,0);
    if (indexOfSon(func, "(RET ") != -1)
        return getTypeAsEnum(func->children[indexOfSon(func, "(RET ") + 1]->token);
    else{
        printf("Error: function %s has no return type\n", func->children[0]->token);
        exit(1);
    }
}

int indexOfSon(node* tree, char* token){
    for (int i = 0; i < tree->child_num; i++) {
        // printf("tree->children[%d]->token = %s\n", i, tree->children[i]->token);
        if (strcmp(tree->children[i]->token, token)==0)
            return i;
    }
    return -1;
}