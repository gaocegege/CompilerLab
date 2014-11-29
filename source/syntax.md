MyLang - Syntax Definition
===

File
---

**root**:

    <> <main structure> <>
    // allow spaces before and after
    // ignore tail

main structure:

    <program>
    <function>
    // <class> not allowed here

Main Structure
---

program:

    program <function proto> <main body> <end program>

function:

    function <function proto> <main body> <end function>

class:

    class <main body> end class

end program:

    end program <id>
    end

end function:

    end function <id>
    end

Block
---

main body:

    <interface block> <is block> <code block>

interface block:

    <definition> <interface block>
    <>

is block:

    is <interface block>
    <>

code block:

    begin <statement list>
    <>

Proto
---

function proto:

    <id> ( <argument list> )

argument list:

    <argument> , <argument list>
    <argument>
    <>

argument:

    in <id>
    out <id>
    <id>

Definition
---

definition:

    <type definition>
    <field definition>
    <main structure> ;
    ;

type definition:

    type <id> is <type>
    // the same as "const <id> is typeid default <...>"

field definition:

    <field type> <id bind>

field type:

    extends
    enclose
    var
    const
    static
    register
    return
    // register is supported in program and function
    // return is supported in function only

Type
---

id bind:

    <id> is <type> <default>
    <type> <default>
    // allow anonymous

default:

    default <expression>
    <>

type:

    auto
    <class>
    <expression> <type of>
    // built-in:
    //     void typeid
    //     byte boolean (boolean is uint) integer
    //     real (double) string (pair of length and pchar)
    // compile-time generation:
    //     array of <integer> <type>
    //     pointer of <type>
    //     reference of <type>

type of:

    of <value> <type>
    of <type>
    <>

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

    <expression> <assign sign> <expression>

*assign sign*:

    \:=|\+=|-=|\*=|\/=

return:

    return <expression>
    return

Code Structure
---

structure:

    <if structure>
    <for structure>
    <foreach structure>
    <while structure>

if structure:

    if <expression> then <statement list> <condition chain> end if

for structure:

    for <id> in <expression> <to range> do <statement list> end for

foreach structure:

    foreach <id> in <expression> do <statement list> end foreach

while structure:

    while <expression> do <statement list> end while

condition chain:

    elif <expression> then <statement list> <condition chain>
    else <statement list>
    <>

to range:

    to <expression>
    downto <expression>

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
    <value> <access operation>
    ( <expression> ) <access operation>

access operation:

    <value> <access operation>
    ( <expression list> ) <access operation>
    . <id> <access operation>
    <>
    // x[0] is x.__call<array of 1 integer>([0])
    // id can be var, const, type etc

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
    div
    mod
    and
    shl
    shr
    rol
    ror

unary operator:

    <addsub>
    not

*comparison*:

    ==|<=|=<|>=|=>|!=|<|>

*addsub*:

    \+|-

*muldivmod*:

    \*|\/|%

Value
---

value list:

    <value> <value list>
    <>

value:

    <literal>
    <id>
    // id of runtime value -> value access
    //               other -> literal

literal:

    <byte>
    <real>
    <integer>
    <string>
    <instant array>
    // const boolean yes := (unsigned -1)
    //                no := 0

*byte*:

    '([^\\]|\\.)'

*real*:

    [0-9]*\.[0-9]+([Ee][\+-]?[0-9]+)?

*integer*:

    [0-9]+

*string*:

    "([^\\]|\\.)*"

instant array:

    [ <expression list> ]

Special
---

**space**:

    <ignored>

**keyword**:

    <reserved id>
    <sign>

*id*:

    [A-Za-z_][A-Za-z0-9_]*

*reserved id*:

    [A-Za-z_][A-Za-z0-9_]*

*sign*:

    [\(\)\[\],.;]

*ignored*:

    (\/\/.*|[ \t\r\n])*
    // including comments
