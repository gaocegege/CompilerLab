MyLang - Syntax Definition
===

File
---

**root**:

     <program> 
     <program> ; 
    // allow spaces before and after

Main Structure
---

program:

    program <function proto> <function body>

function:

    function <function proto> <function body>

class:

    class <interface block> <main end>
    class extends <typename id> <interface block> <main end>

Block
---

function body:

    <interface block> begin <code block> <main end>
    <interface block> is <value block> begin <code block> <main end>

interface block:

    <definition> <interface block>

value block:

    <value definition> <interface block>

code block:

    <statement> <code block>

main end:

    end
    end program <function id>
    end function <function id>
    end class
    // should match the body

Definition
---

function proto:

    <function id> ( )
    <function id> ( <argument list> )

argument list:

    <value id>
    <value id> , <argument list>

definition:

    <type definition> ;
    <value definition> ;
    <return definition> ;
    <function> ;

type definition:

    type <typename id> is <type id>

value definition:

    <var definition>
    <const definition>

var definition:

    var <value id> is <type id>

const definition:

    const <value id> is <type id>

return definition:

    return <type id>
    // return is supported in function only

Statement
---

statement:

    ;
    <expression> ;
    <assignment> ;
    <return> ;
    <structure>
    <repeat> ;

assignment:

    <variable> := <expression>

return:

    return <expression>

structure:

    if <expression> then <code block> <condition chain> <structure end>
    for <variable> := <for range> do <code block> <structure end>
    foreach <variable> in <expression> do <code block> <structure end>
    while <expression> do <code block> <structure end>

condition chain:

    elif <expression> then <code block> <condition chain>
    else <code block>

for range:

    <expression> to <expression>
    <expression> downto <expression>

structure end:

    end
    end if
    end for
    end foreach
    end while
    // should match the structure

repeat:

    repeat <code block> until <expression>
    // special structure

Expression
---

variable:

    <value id>
    <value id> . <variable>
    <value id> [ <expression> ]

expression:

    <expression> <relation> <additive expression>
    <additive expression>
    // warning: has left-recursion
    // may skipped by LL(k) parser and parsed by shunting yard algorithm or level counting

additive expression:

    <additive expression> <addition> <multiplicative expression>
    <multiplicative expression>

multiplicative expression:

    <multiplicative expression> <multiplication> <unary expression>
    <unary expression>

unary expression:

    <unary operator> <unary expression>
    <literal>
    <variable>
    <variable> <unary expression>
    <variable> ( <expression list> )
    [ <expression list> ]
    // distinguish variable by callability

expression list:

    <expression> , <expression list>

Identifier
---

type id:

    <class>
    <array>
    <native type>
    <typename id>

typename id:

    <id>

function id:

    <id>

value id:

    <id>

*id*:

    [a-z_][a-z0-9_]*

Type
---

array:

    array of <integer> <type id>

native type:

    boolean
    integer
    real
    string

Operator
---

relation:

    in
    <comparison>

*comparison*:

    <|=|>|<=|=<|<>|><|>=|=>

addition:

    +
    -
    or
    xor

multiplication:

    *
    /
    div
    mod
    and

unary operator:

    +
    -
    not

Literal
---

literal:

    <boolean>
    <integer>
    <real>
    <string>

boolean:

    yes
    no

*integer*:

    [0-9]+

*real*:

    [0-9]*\.[0-9]+([eE][\+-]?[0-9]+)?

*string*:

    "([^\\]|\\.)*"

Special
---

**space**:

    <ignored>

**keyword**:

    <id>
    <sign>

*sign*:

    [\(\)\[\],.+\-*\/;]|:=

*ignored*:

    ([ \t\n]|\/\/.*$)*
    // including comments
