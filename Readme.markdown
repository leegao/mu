Refer to http://www.opensource.org/licenses/gpl-3.0.html for license information.

The Mu Language
===============

The mu language is an experimental language with a syntax derived from C. 
The language features variables whose types are determined dynamically during runtime. 
The aim of the project is simplicity, so there are only 5 primitive types; they are:

*	number
*	string
*	list
*	function
*	boolean

and an extra nil type that denotes the lack of value.

There are 5 arithmetic operators closed on the domain of reals, they are:

``` c
+ - * / %
```

Furthermore, the traditional comparison operators from the number domain to booleans are:

``` c
< <= > >=
```

while these will work on boolean, numbers, and strings as well:

``` c
== !=
```

Function declaration follows this syntax:

``` javascript
function(arg1, arg2, arg3){
	...
}
```

and variable declaration:

``` javascript
var identifier;
var identifier = xxx;
```
Conditional statements are also supported. The syntax of a while loop is:

``` javascript
while expr {
	...
}
```

and the for loop:

``` javascript
// Using a counter
for (var i = 0, i < n, i = i + 1){
	...
}

// Foreach
for el in iterable {
	...
}
```