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
    // <program> like l-value: has receive / no return
    // <function> like r-value: has return / no receive

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

    <public block> <private block> <code block>

public block:

    <definition list>

private block:

    is <definition list>
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
    var <id>
    <id>

Definition
---

definition list:

    <definition> <definition list>
    <>

definition:

    <type definition>
    <field definition>
    <field deletion>
    <main structure> ;
    ;

type definition:

    type <id> is <type>
    // the same as "const <id> is typeid default <...>"

field definition:

    <field type> <id bind>

field deletion:

    delete <id>

field type:

    extends
    enclose
    var
    const
    static
    fast
    receive
    return
    // fast is supported in program and function
    // receive is supported in program only
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
    // "array of 10 integer" is the same as "array(10, integer)"

type of:

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
    <receive> ;
    <pause> ;
    <return> ;
    <structure>
    <repeat> ;
    ;

assignment:

    <expression> <assign sign> <expression>

*assign sign*:

    \:=|\+=|-=|\*=|\/=

receive:

    receive <expression>
    receive

pause:

    pause

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

    <real>
    <integer>
    <byte>
    <string>
    <instant array>
    // const boolean yes := (unsigned -1)
    //                no := 0

*real*:

    [0-9]*\.[0-9]+([Ee][\+-]?[0-9]+)?

*integer*:

    [0-9]+

*byte*:

    '([^\\]|\\.)'

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
