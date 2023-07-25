incr,triplo :: Integer -> Integer
incr x = x+1
triplo x = 3*x
boasVindas :: String -> String
boasVindas nome = "Ola, " ++ nome ++ "!"

-- a) incr (triplo 3) -> incr (3*3) -> incr (9) -> 9 + 1 -> 10
-- b) triplo (incr 3) -> triplo (3+1) -> triplo (4) -> 3*4 -> 12
-- c) boasVindas "Linguagem" ++ " Haskell" -> "Ola, Linguagem!" ++ " Haskell" -> "Ola, Linguagem! Haskell"
-- d) boasVindas ("Linguagem" ++ " Haskell") -> boasVindas("Linguagem Haskell") -> "Ola, Linguagem Haskell!"
-- e) boasVindas(boasVindas "Haskell") -> boasVindas("Ola, Haskell!") -> "Ola, Ola, Haskell!!"
