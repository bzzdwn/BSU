var carrot >= 0; # кг моркови
var apple >= 0; # кг яблок
minimize cost: 100*carrot + 200*apple; # целевая функция
s.t. vitamin_A: 12*carrot + apple >= 10; # ограничения витамина А
s.t. vitamin_B: 74*carrot + 25*apple >= 90; # ограничения витамина В\
