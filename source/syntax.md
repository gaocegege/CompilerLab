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
    // <class> - not allowed here

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

Specific
---

specific list:

    <specific> , <specific list>
    <specific>
    <>

specific:

    <extend specific>
    <enclose specific>

extend specific:

    extends <typed bind>
    // default: extends <class base> / <program base> / <function base>

enclose specific:

    encloses <typed bind>
    // default: (if need) encloses decltype(ref(outer)) default ref(outer)

Definition
---

definition:

    <type definition> ;
    <var definition> ;
    <const definition> ;
    <static definition> ;
    <fastvar definition> ;
    <return definition> ;
    <main structure>
    ;
    // fastvar (passed by register) for program and function only
    // return for function only

type definition:

    type <id> is <type>
    // const <id> is typeid default <...>

var definition:

    var <id bind>

const definition:

    const <id bind>

static definition:

    static <id bind>

fastvar definition:

    fastvar <id bind>
    // fastvar is supported in program and function

return definition:

    return <id bind>
    // return is supported in function only

Type
---

id bind:

    <id> is <typed bind>
    <typed bind>
    // allow anonymous

typed bind:

    <type> default <expression>
    <type>

type:

    auto
    <class>
    <expression>
    // built-in:
    //     void typeid
    //     byte boolean (boolean is uint) integer
    //     real (double) string (pair of length and pchar)
    // compile-time generation:
    //     array of <integer> <id>
    //     pointer of <id>
    //     reference of <id>

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

    for <id> in <for range> do <statement list> end for

foreach structure:

    foreach <id> in <expression> do <statement list> end foreach

while structure:

    while <expression> do <statement list> end while

condition chain:

    elif <expression> then <statement list> <condition chain>
    else <statement list>
    <>

for range:

    <expression> to <expression>
    <expression> downto <expression>

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
    ( <expression> )

access operation:

    <argument apply> <access operation>
    . <id> <access operation>
    <>

argument apply:

    of <value list>
    <value>
    ( <expression list> )
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

    <byte>
    <integer>
    <real>
    <string>
    <instant array>
    <id>
    // const boolean yes := (unsigned -1)
    //                no := 0
    // id of runtime value -> value access
    //               other -> literal

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
