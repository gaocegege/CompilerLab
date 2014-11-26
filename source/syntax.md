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

    <specific list> <interface block> <is block> <code block> <main end>

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

specific list:

    <specific> , <specific list>
    <specific>
    <>

specific:

    extends <type>
    encloses <expression>
    // default: extends <class base> / <program base> / <function base>
    // default: (if need) encloses outer is reference of type of outer

definition:

    <var definition> ;
    <const definition> ;
    <static definition> ;
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
    // only bind once in the code block

static definition:

    static <id> is <type>

return definition:

    return <id> is <type>
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
    <return> ;
    <structure>
    <repeat> ;
    ;

assignment:

    <expression> := <expression>

return:

    return <expression>
    return

Code Structure
---

structure:

    if <expression> then <statement list> <condition chain> <structure end>
    for <id> := <for range> do <statement list> <structure end>
    foreach <id> in <expression> do <statement list> <structure end>
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
    <literal> <access operation>
    <id> <access operation>
    ( <expression> )

access operation:

    <argument apply> <access operation>
    . <id> <access operation>
    <>

argument apply:

    <literal>
    <id>
    ( <expression list> )
    // x[0] is x.__call<array of 1 integer>([0])

Identifier
---

type:

    <native type>
    <wrap type>
    <program type>
    <function type>
    <type inference>
    <class>
    <id>

*id*:

    [A-Za-z_][A-Za-z0-9_]*

Type
---

native type:

    void
    boolean
    byte
    integer
    real

wrap type:

    <array>
    <pointer>
    <reference>

array:

    array of <integer> <type>
    array of <type>
    // the second version is pointer

pointer:

    pointer of <type>

reference:

    reference of <type>

program type:

    program <id>

function type:

    function <id>

type inference:

    type of <expression>

Operator
---

relation:

    <comparison>
    in

addition:

    <addsub>
    or
    xor

multiplication:

    <muldivmod>
    <shlshr>
    div
    mod
    and

unary operator:

    <addsub>
    not

*comparison*:

    ==|<=|=<|>=|=>|!=|<|>

*addsub*:

    \+|-

*muldivmod*:

    \*|\/|%

*shlshr*:

    <<|>>

Literal
---

literal:

    <boolean>
    <byte>
    <integer>
    <real>
    <string>
    <instant array>
    <type info>

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

type info:

    $ <type> $

Special
---

**space**:

    <ignored>

**keyword**:

    <reserved id>
    <sign>

*reserved id*:

    [A-Za-z_][A-Za-z0-9_]*

*sign*:

    \:=|[\(\)\[\],.;$]

*ignored*:

    (\/\/.*|[ \t\r\n])*
    // including comments
