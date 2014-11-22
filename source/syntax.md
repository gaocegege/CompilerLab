MyLang - Syntax Definition
===

File
---

**root**:

    <> <main structure> ; <>
    <> <main structure> <>
    <!Syntax error>
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

    <specific> <interface block> <is block> <code block> <main end>

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

    end program <id>
    end function <id>
    end class
    end
    // should match the body

Definition
---

function proto:

    <id> ( <argument list> )

argument list:

    <argument option> <id> , <argument list>
    <argument option> <id>
    <>

argument option:

    in
    out
    reg
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

    type <id> is <type>

var definition:

    var <id> is <type>

const definition:

    const <id> is <type>

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

    <expression> := <expression>

inherit:

    inherit

return:

    return <expression>

Code Structure
---

structure:

    if <expression> then <statement list> <condition chain> <structure end>
    for <expression> := <for range> do <statement list> <structure end>
    foreach <expression> in <expression> do <statement list> <structure end>
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

    <additive expression> <relative operation>

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
    <access expression>
    ( <expression> )

access expression:

    <value expression> <access operation>

access operation:

    . <access operation>
    <>

value expression:

    <id> <argument apply>
    <id>

argument apply:

    <literal>
    <value expression>
    ( <expression list> )
    // x[0] is x.__call<array of 1 integer>([0])

Identifier
---

type list:

    <type> , <type list>
    <type>

type:

    <native type>
    <array>
    <reference>
    <class>
    <id>

*id*:

    [A-Za-z_][A-Za-z0-9_]*

Type
---

native type:

    empty
    boolean
    byte
    integer
    real

array:

    array of <integer> <type>
    array of <type>
    // the second version is pointer

reference:

    reference of <type>

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
    <byte>
    <integer>
    <real>
    <string>
    <instant array>

boolean:

    yes
    no

*byte*:

    '([^\\]|\\.)'

*integer*:

    [0-9]+

*real*:

    [0-9]*\.[0-9]+([Ee][\+-]?[0-9]+)?

*string*:

    "([^\\]|\\.)*"

instant array:

    [ <expression list> ]

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

    ([ \t\r\n]|\/\/.*)*
    // including comments
