MyLang - Syntax Definition
===

File
---

**root**:

    <> <main structure> ; <>
    <> <main structure> <>
    // allow spaces before and after

main structure:

    <program>
    <function>
    <class>

Main Structure
---

program:

    program <function proto> <main body>

function:

    function <function proto> <main body>

class:

    class <main body>

Block
---

main body:

    <specific> <interface block> <code block> <main end>

interface block:

    <definition> <interface block>
    <>

is block:

    is <interface block>
    <>

code block:

    begin <statement list>
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

specific:

    extends <type list>
    <>

definition:

    <var definition> ;
    <const definition> ;
    <type definition> ;
    <program> ;
    <function> ;
    <return definition> ;
    ;
    // return definition for function only (or cause a warning)

type definition:

    type <type id> is <type>

var definition:

    var <value id> is <type>

const definition:

    const <value id> is <type>

return definition:

    return <type>
    // return is supported in function only

Statement
---

statement list:

    <statement> <statement list>
    <>

statement:

    <expression> ;
    <assignment> ;
    <inherit> ;
    <return> ;
    <structure>
    <repeat> ;
    ;

assignment:

    <variable> := <expression>

inherit:

    inherit

return:

    return <expression>

Code Structure
---

structure:

    if <expression> then <statement list> <condition chain> <structure end>
    for <variable> := <for range> do <statement list> <structure end>
    foreach <variable> in <expression> do <statement list> <structure end>
    while <expression> do <statement list> <structure end>

condition chain:

    elif <expression> then <statement list> <condition chain>
    else <statement list>
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

    repeat <statement list> until <expression>
    // special structure

Expression
---

expression list:

    <expression> , <expression list>
    <expression>
    <>

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

variable:

    <value id> . <variable>
    <value id> [ <expression> ]
    <value id>

Identifier
---

type list:

    <type> , <type list>
    <type>

type:

    <class>
    <array>
    <native type>
    <type id>

type id:

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

    array of <integer> <type>

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
