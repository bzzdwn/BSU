set n;
set m;
param c{n};
param p{m};
var x{n} >=0 integer;
var y{m} >=0 integer;

maximize z: sum{i in n} c[i]*x[i] - sum{i in m} p[i]*y[i];
s.t. r1: x[1] + y[1] >= 20;
s.t. r2: x[2] + y[1] >= 50;
s.t. r3: x[3] + y[2] >= 40;
s.t. sh: y[1] + y[2] <= 20;