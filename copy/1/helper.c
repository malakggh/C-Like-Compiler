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
    /* printf("for token: %s, childnum= %d",newnode->token,newnode->child_num); */
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
    return newnode;
}

node* expNode(char* token,node* first,node* second){
    return mknode("#",(node*[]){
    mknode1(token),nl(),
    mknode("",(node*[]){first,NULL}),nl(),
    mknode("",(node*[]){second,NULL}),nl(),
    mknode1(")"),nl(),NULL});
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
    scope->returnType = VOID_T;
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
        printf("funcsArr: []");
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
    printf("]");
}

void printScpoe(Scope* Scope, int i){
    printf("#################start#####################\n");
    printf("scope %d:\n", i);
    printf("return type: %s\n", getTypeAsString(Scope->returnType));
    printVarArr(Scope->varArr);
    printf("\n");
    printFunctionArr(Scope->funcsArr);
    printf("\n#################end#####################\n");
}


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
    printScpoe(global_scope, stack->len-1);
    fillScope(stack, tree->children[2], global_scope, NULL, VOID_T);
    printScpoe(global_scope, stack->len-1);
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
            printScpoe(new_scope, stack->len-1);
            new_scope->varArr = deepCopyVarArr(newFunc->varArr);
            new_scope->returnType = newFunc->returnType;
            fillScopeBody(stack,func->children[indexOfSon(func, "(BODY")+2],new_scope);
            printScpoe(new_scope, stack->len-1);
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
int test() {
    // Create a scope stack
    ScopeStack* stack = newScopeStack();

    // Create the first scope
    Scope* scope1 = newScope();

    // Add variables to the first scope
    Var* var1 = newVar("x", INT_T);
    appendVarArr(scope1->varArr, var1);

    // Add functions to the first scope
    Function* func1 = newFunction("foo", INT_T, NULL);  // You can pass a VarArr if needed
    appendFunctionArr(scope1->funcsArr, func1);

    // Push the first scope onto the stack
    pushScope(stack, scope1);

    // Create a new scope
    Scope* scope2 = newScope();

    // Add variables to the second scope
    Var* var2 = newVar("y", REAL_T);
    appendVarArr(scope2->varArr, var2);

    // Add functions to the second scope
    Function* func2 = newFunction("bar", VOID_T, NULL);  // You can pass a VarArr if needed
    appendFunctionArr(scope2->funcsArr, func2);

    // Push the second scope onto the stack
    pushScope(stack, scope2);

    // Perform searches in the scope stack
    char* searchVarName = "x";
    Var* foundVar = searchVarInStack(stack, searchVarName);
    if (foundVar != NULL) {
        printf("Variable '%s' found in the stack.\n", searchVarName);
    } else {
        printf("Variable '%s' not found in the stack.\n", searchVarName);
    }

    char* searchFuncName = "bar";
    Function* foundFunc = searchFunctionInStack(stack, searchFuncName);
    if (foundFunc != NULL) {
        printf("Function '%s' found in the stack.\n", searchFuncName);
    } else {
        printf("Function '%s' not found in the stack.\n", searchFuncName);
    }

    // Pop the scopes from the stack
    popScope(stack); // Pop the second scope
    popScope(stack); // Pop the first scope

    // Clean up memory
    // ...

    return 0;
}

expressionNode *mkExpNode(char *name, expressionNode *left, expressionNode *right)
{
    return nullptr;
}
