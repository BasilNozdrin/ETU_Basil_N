a = 0; b = 2; ya = 1; yb = 2;
f = @(x,y) log(x+1)*pow2(y);

lsp = linspace(a,b,50);
[x,y] = ode45(f, [a,b], [ya,yb]);
plot(x,y);
# print -djpg figure-lsnode.jpg