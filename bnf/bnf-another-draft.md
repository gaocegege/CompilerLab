MyLang - Syntax Definition
===

File
---

**root**:

    <> <program> ; <>
    <> <program> <>
    // allow spaces before and after

Main Structure
---

program:

    program <function proto> <function body>

function:

    function <function proto> <function body>

class:

    class <extend> <interface block> <main end>

extend:

    extends <typename id>
    <>

Block
---

function body:

    <interface block> begin <code block> <main end>

interface block:

    <definition> <interface block>
    <>

is block:

    is <value block>
    <>

value block:

    <value definition> <value block>
    <>

code block:

    <statement> <code block>
    <>

main end:

    end program <function id>
    end function <function id>
    end class
    end
    // should match the body

Definition
---

function proto:

    <function id> ( <argument list> )

argument list:

    <value id> , <argument list>
    <value id>
    <>

definition:

    <type definition> ;
    <value definition> ;
    <return definition> ;
    <function> ;
    ;

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

    <expression> ;
    <assignment> ;
    <return> ;
    <structure>
    <repeat> ;
    ;

assignment:

    <variable> := <expression>

return:

    return <expression>

Code Structure
---

structure:

    if <expression> then <code block> <condition chain> <structure end>
    for <variable> := <for range> do <code block> <structure end>
    foreach <variable> in <expression> do <code block> <structure end>
    while <expression> do <code block> <structure end>

condition chain:

    elif <expression> then <code block> <condition chain>
    else <code block>
    <>

for range:

    <expression> to <expression>
    <expression> downto <expression>

structure end:

    end if
    end for
    end foreach
    end while
    end
    // should match the structure

repeat:

    repeat <code block> until <expression>
    // special structure

Expression
---

variable:

    <value id> . <variable>
    <value id> [ <expression> ]
    <value id>


    <expression>

    <relation> <additive expression>
    <additive expression>


expression:

    <relative expression>

relative expression:

    <additive expression> <relation operation>

relative operation:

    <relation> <relative expression>
    <>

additive expression:

    <multiplicative expression> <additive operation>

additive operation:

    <addition> <additive expression>
    <>

multiplicative expression:

    <unary expression> <multiplicative operation>

multiplicative operation:

    <multiplication> <multiplicative expression>
    <>

unary expression:

    <unary operator> <unary expression>
    <literal>
    <variable> <argument expression>
    <variable>
    [ <expression list> ]

argument expression:

    <unary expression>
    ( <expression list> )

expression list:

    <expression> , <expression list>
    <expression>
    <>

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

    [A-Za-z_][A-Za-z0-9_]*

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

    [0-9]*\.[0-9]+([Ee][\+-]?[0-9]+)?

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
