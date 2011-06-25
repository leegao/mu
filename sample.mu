this = [1, 2, 3, 4, 5];
match this with
  [a,b,c]
| a::b::c::tl { print(a + b + c); }
| _ { error("Bad Expression"); };
