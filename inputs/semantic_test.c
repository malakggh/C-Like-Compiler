/* comment
Long */
function foo1(arg-> a, b, c : int; arg-> c1 : char) : bool
{
    var res:bool;
    {
        var x, b: char;
        var y: int;
        var count: bool;
        b='&';

        count = 7;
        /*1 a=x; 
        
        
        
        */
        /*2 b=8; */
        a=(y*7)/a-y;
        /*3 a=(y*7)/b-y; */
        /*4 a=(y*7)/a-c1; */
        /*5 res=(b==c) && (y>a); */
        /*6 res=(b==c1) && (y+a); */
        /*7 3+6=9; */
        /*8%x=6 ;*/
    }
    return res;
}

function fee1(arg-> i, j, k, x : int) : void
{
    function fee2 (arg-> l, m, n : int) : bool
    {
        var x, j: bool;
        /*10 var bool n;*/
        var k: char;
        k='@';
        i=l + l;
        /*11 i=j+1; */
        /*12 i=k+1; */
        if((k=='*') || (x!=false) && ( l+m < i)) {
            x=l<m;
        }
        return x;
    }
    {
        var x: char;
        var k: bool;
        k=fee2(5,i,j);
        /*13 x=fee2(5,i,j); */
        /*14 k = fee2(5,i); */
        /*15k = fee2(5,x,j); */
    }
    /*16 n=false; */
    /*17 x='#'; */
    x=k;
}

function foo3(arg-> i, j , k: int) : int
{
    function square(arg-> t: int) : int /* function declaration */
    {
        var temp: int;
        temp=t*t;
        return temp;
    }
    var total: int; /* variable declaration */
    var bo: bool;
    bo=foo1(i, j, k, '^');
    /*18 j=foo2(); */
    total=square(i+j+k); /* statemets */
    return total;
}

function foo2() : int
{
    string s1 [100];
    string s2 [100];
    var i, j, cnt: int;
    i=0;
    j=0;
    cnt=1;
    while(i < |s1|) {
        while(j < |s2| / 2) {
            if(s1[i] == s2[j]) {
                cnt=cnt*2;
            }
            j=j+1;
        }
        i=i+1;
    }
    return cnt;
}

function foo4() : int
{
    {
        var x: int;
        var y: int*;
        x=5;
        y=&x;
        x=6;
        if(&x == y && *y == x ) {
        *y=9;
    }
    {
        var x: char*;
        string y[10];
        var z: char;
        x=&y[5];
        z=*(x);
        y="barfoo";
        {
            var x: char;
            var y: int*;
            var z: char*;
            var g:char;
            /*19 y=&(1+3);
            y=&x;
            z=&(&(g)); */
        }
    }
    }
    return 0;
}

function main() : void
{
    var a: int;
    a = foo2();
}