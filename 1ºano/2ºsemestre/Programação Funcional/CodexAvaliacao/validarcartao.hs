validar :: Integer -> Bool
validar n = mod (somar (duplicar (decompor n))) 10 == 0

decompor :: Integer -> [Integer]
decompor n = if (n < 0) then error "número inválido"
              else if (n < 10) then [n]
                    else m : decompor d -- a lista fica invertida
                       where m = mod n 10
                             d = div n 10

duplicar :: [Integer] -> [Integer]
duplicar [] = []
duplicar (x:[]) = (x:[])
duplicar (x : y : xs) = x : 2*y : duplicar xs -- x é o último elemento da lista

somar :: [Integer] -> Integer
somar [] = 0
somar (x : xs) = if (x < 10) then x + somar xs
                  else d1 + m1 + somar xs
                     where d1 = div x 10
                           m1 = mod x 10
